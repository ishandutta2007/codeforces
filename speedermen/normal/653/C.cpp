#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
const int MD = 1000000007;

#define ll long long
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define FOR(i, a, b) for (int _tmp = b, i = a; i <= _tmp; ++i)

typedef pair < int, int > pii;
typedef vector < int > vi;
typedef vector < vi > vvi;

int n, t[N];

int main()
{
//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);
    ios_base::sync_with_stdio(0);
    set < pii > ans;
    cin >> n;
    FOR(i, 1, n) cin >> t[i];
    vi bad;
    FOR(i, 1, n - 1)
        if (i % 2 == 0 && t[i] <= t[i + 1]) {
            if (i != 1) bad.pb(i - 1);
            bad.pb(i);
            bad.pb(i + 1);
        } else if (i % 2 == 1 && t[i] >= t[i + 1]) {
            if (i != 1) bad.pb(i - 1);
            bad.pb(i);
            bad.pb(i + 1);
        }
    sort(bad.begin(), bad.end());
    bad.erase(unique(bad.begin(), bad.end()), bad.end());
    if (bad.size() > 10) {
        cout << 0;
        return 0;
    }
    for (int i = 0; i < bad.size(); ++i) {
        int pos = bad[i];
        FOR(j, 1, n) {
            if (j == pos) continue;
            if (ans.count(mp(j, pos))) {
                continue;
            }
            swap(t[j], t[pos]);
            bool ok = 1;
            if (j + 1 <= n) {
                if (j % 2 == 0 && t[j] <= t[j + 1])
                    ok = 0;
                if (j % 2 == 1 && t[j] >= t[j + 1])
                    ok = 0;
            }
            if (j - 1 >= 1) {
                if ((j - 1) % 2 == 0 && t[j - 1] <= t[j])
                    ok = 0;
                if ((j - 1) % 2 == 1 && t[j - 1] >= t[j])
                    ok = 0;
            }
            for (int k = 0; k < bad.size() && ok; ++k) {
                int j = bad[k];
                if (j + 1 <= n) {
                    if (j % 2 == 0 && t[j] <= t[j + 1])
                        ok = 0;
                    if (j % 2 == 1 && t[j] >= t[j + 1])
                        ok = 0;
                }
                if (j - 1 >= 1) {
                    if ((j - 1) % 2 == 0 && t[j - 1] <= t[j])
                        ok = 0;
                    if ((j - 1) % 2 == 1 && t[j - 1] >= t[j])
                        ok = 0;
                }
            }
            if (ok)
            {
                    ans.insert(mp(j, pos));
                ans.insert(mp(pos, j));
            }
            swap(t[j], t[pos]);
        }
    }
    cout << ans.size() / 2 << endl;
    return 0;
}