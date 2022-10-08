#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define N 200010

vector<int> A[N];
int n, f[N], g[N][2], c[N], U, q[N];

int main () {
    cin >> n;
    for (int i = 1; i < n; i ++) {
        int x, y;
        cin >> x >> y;
        -- x; -- y;
        A[x].pb(y); A[y].pb(x);
    }
    int l = 0, r = 1;
    q[0] = 0; f[0] = -1;
    while (l < r) {
        int x = q[l++];
        for (vector<int>::iterator i = A[x].begin(); i != A[x].end(); i ++)
            if (*i != f[x]) {
                f[*i] = x;
                q[r++] = *i;
                c[x] ++;
            }
    }
    for (int i = 0; i < n; i ++)
        if (c[i] == 0) U ++;
    for (int z = n-1; z >= 0; z --) {
        int x = q[z];
        if (c[x] == 0) {
            g[x][0] = g[x][1] = 1;
            continue;
        }
        int S = n;
        for (vector<int>::iterator i = A[x].begin(); i != A[x].end(); i ++)
            if (*i != f[x]) S = min(S, g[*i][1]);
        g[x][0] = S;
        int T = 0;
        for (vector<int>::iterator i = A[x].begin(); i != A[x].end(); i ++)
            if (*i != f[x]) T += g[*i][0];
        g[x][1] = T;
    }
    cout << U-g[0][0]+1 << " " << g[0][1] << endl;
    return 0; 
}