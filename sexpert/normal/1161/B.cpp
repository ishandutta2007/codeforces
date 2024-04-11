#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;
int n, m;
vector<int> segs[2*MAXN];
int z[2*MAXN];

void zfunc() {
    int L = -1, R = -1;
    z[0] = -1;
    for(int i = 1; i < 2*n; i++) {
        if(i <= R) z[i] = min(z[i - L], R - i + 1);
        while(i + z[i] < 2*n && segs[z[i]] == segs[i + z[i]]) z[i]++;
        if(i + z[i] - 1 > R) L = i, R = i + z[i] - 1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    while(m--) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        if(x > y)
            swap(x, y);
        segs[x].push_back(y - x);
        segs[y].push_back(n - (y - x));
    }
    for(int i = 0; i < n; i++) {
        sort(segs[i].begin(), segs[i].end());
        segs[n + i] = segs[i];
    }
    zfunc();
    for(int i = 0; i < n; i++) {
        if(z[i] >= n) {
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";
}