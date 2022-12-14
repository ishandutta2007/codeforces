#include <bits/stdc++.h>
#define FOR(i,l,r) for(int i=l; i<=r; ++i)
#define REP(i,l,r) for(int i=l; i<r; ++i)
#define FORD(i,r,l) for(int i=r; i>=l; --i)
#define REPD(i,r,l) for(int i=r-1; i>=l; --i)
using namespace std;
const int N = 1005;
int t, n, m, k, res, ans[N * N], sum[N * N], col[N * N], pre[N * N];
string s;

void Enter() {
    cin >> n >> m >> s;
}

void Process() {
    int tmp = 0;
    FOR(i, 1, n*m) ans[i] = sum[i] = 0;
    FOR(i, 1, m) col[i] = 0;
    FOR(i, 1, n) {
        FOR(j, 1, m) {
            int pos = (i - 1) * m + j;
            pre[pos] = pre[pos - 1];
            if (s[pos - 1] == '1') {
                if (col[j] == 0) {
                    col[j] = 1;
                    ++tmp;
                }
                ++pre[pos];
            }
            ans[pos] = tmp;
            if (pos <= m) sum[pos] = (pre[pos] > 0);
            else sum[pos] = sum[pos - m] + (pre[pos] > pre[pos - m]);

            cout << ans[pos] + sum[pos] << ' ';
        }
    }
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        Enter();
        Process();
    }
}