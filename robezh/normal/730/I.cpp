#include <bits/stdc++.h>
using namespace std;

const int N = 3005, INF = (int)1e9;

int n,p,s;
int a[N], b[N];
int id[N];
int dpl[N][N], dpr[N][N];
bool tkl[N][N], tkr[N][N];

int main() {
    cin >> n >> p >> s;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i], id[i] = i;
    sort(id + 1, id + n + 1, [](int i, int j) {
        return a[i] - b[i] > a[j] - b[j];
    });
    for(int i = 0; i < N; i++) fill(dpl[i], dpl[i] + N, -INF);
    for(int i = 0; i < N; i++) fill(dpr[i], dpr[i] + N, -INF);
    dpl[0][0] = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            dpl[i][0] = dpl[i-1][0];
            dpl[i][j] = max(dpl[i-1][j-1] + a[id[i]], dpl[i-1][j]);
            tkl[i][j] = dpl[i-1][j-1] + a[id[i]] > dpl[i-1][j];
        }
    }

    dpr[n+1][0] = 0;
    for(int i = n; i >= 1; i--) {
        dpr[i][0] = dpr[i+1][0];
        for(int j = 1; j <= n; j++) {
            dpr[i][j] = max(dpr[i+1][j-1] + b[id[i]], dpr[i+1][j]);
            tkr[i][j] = dpr[i+1][j-1] + b[id[i]] > dpr[i+1][j];
        }
    }
    int res = 0, l = 0;
    for(int i = p; i <= n - s; i++) {
        if(dpl[i][p] + dpr[i+1][s] > res) {
            res = dpl[i][p] + dpr[i+1][s];
            l = i;
        }
    }
    vector<int> L, R;
    int cur = p;
    for(int i = l; i >= 1; i--) if(tkl[i][cur]) L.push_back(id[i]), cur--;
    cur = s;
    for(int i = l + 1; i <= n; i++) if(tkr[i][cur]) R.push_back(id[i]), cur--;
    cout << res << endl;
    for(int x : L) cout << x << " ";
    cout << endl;
    for(int x : R) cout << x << " ";
    cout << endl;



}