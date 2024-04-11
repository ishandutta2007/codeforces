#include <bits/stdc++.h>
using namespace std;

const int N = 305;
typedef pair<int, int> P;

int n,m,k;
int mks[N];
int con[N][N];
bool ocu[N];
int id[N];
vector<P> res;

void cont(int a, int b) {
    con[a][b] = con[b][a] = 1;
}

int main() {
    cin >> n >> m >> k;
    for(int i = 0; i < k; i++) {
        cin >> mks[i]; mks[i]--;
        ocu[mks[i]] = true;
    }

    if(k == n) return !printf("-1\n");
    if((n-2)*(n-3)/2 + 2 * (n - k) + k - 2 < m) return !printf("-1\n");

    int s = 0, t = 1;
    m -= n - 1;
    for(int i = 2; i < n; i++) cont(s, i);
    cont(n-1, t);
    for(int i = n - 2; i >= k; i--) {
        if(m > 0) {
            cont(i, t);
            m--;
        }
    }

    for(int i = 2; i <= n - 1; i++) {
        for(int j = i + 1; j <= n - 1; j++) {
            if(m > 0) {
                cont(i, j);
                m--;
            }
        }
    }

    for(int i = 0; i < k; i++) id[i] = mks[i];
    int cur = 0;
    for(int i = k; i < n; i++) {
        while(cur < n && ocu[cur]) cur++;
        id[i] = cur++;
    }
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(con[i][j]) cout << id[i] + 1 << " " << id[j] + 1 << endl;
        }
    }






}