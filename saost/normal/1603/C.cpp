#include <bits/stdc++.h>
#define FOR(i,l,r) for(int i=l; i<=r; ++i)
#define REP(i,l,r) for(int i=l; i<r; ++i)
#define FORD(i,r,l) for(int i=r; i>=l; --i)
#define REPD(i,r,l) for(int i=r-1; i>=l; --i)
#define pii pair<long long,int>
using namespace std;
const int N = 100005, MOD = 998244353;
int t, n, a[N], exist[N];
long long cnt[N], cnt2[N], val[N], val2[N], res;
vector<int> Q, Q2;

int get(int w, int v) {
    if (w <= v) return w;
    if (w % v == 0) return v;
    int x = w % v;
    int sl = (w + v - 1) / v;
    int k = (v - x + sl - 1) / sl;
    return v - k;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n;
        for(int i=1; i<=n; ++i) cin >> a[i];
        for(int i=n; i; --i) {
            Q2.push_back(a[i]);
            exist[a[i]] = 1;
            cnt2[a[i]] = 1;
            val2[a[i]] = 0;
            for(int v : Q) {
                int w = get(a[i], v);
                int sl = (a[i] - 1) / v;
                if (!exist[w]) {
                    exist[w] = 1;
                    val2[w] = cnt2[w] = 0;
                    Q2.push_back(w);
                }
                (val2[w] += val[v] + cnt[v] * sl) %= MOD;
                (cnt2[w] += cnt[v]) %= MOD;
            }
            for(int v : Q2) {
                cnt[v] = cnt2[v];
                val[v] = val2[v];
                (res += val[v]) %= MOD;
                exist[v] = 0;
            }
            Q = Q2;
            Q2.clear();
        }
        Q.clear();
        cout << res << '\n';
        res = 0;
    }
}