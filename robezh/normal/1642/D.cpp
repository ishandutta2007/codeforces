#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define subnb true
#define Lnb true
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
const int MOD = (int)1e9 + 7;

mt19937_64 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
const int N = 505;
uniform_int_distribution<int> BDIST(0.1 * MOD, 0.9 * MOD);
const int base = BDIST(rng);

int n;
int a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        map<int, int> mp;
        rep(i, 0, n) {
            cin >> a[i];
            mp[a[i]]++;
        }
        bool good = true;
        for (auto &p : mp) good &= p.second % 2 == 0;
        if(!good) {
            cout << -1 << '\n';
            continue;
        }
        vi res;
        vector<pii> ops;
        auto rev = [&](int idx) {
            for (int j = n - 1, d = 0; j >= idx; j--, d++) {
                ops.push_back({idx + d, a[j]});
//                cout << "ins " << idx + d << " with " << a[j] << endl;
            }
            res.push_back((n - idx) * 2);
            reverse(a + idx, a + n);
        };

        for (int i = 0; i < n; i++) {
            int mnj = i;
            for (int j = i; j < n; j++) if(a[j] < a[mnj]) mnj = j;
            rev(mnj);
            rev(i);
        }
//        rep(i, 0, n) cout << a[i] << " ";
//        cout << endl;
        rep(i, 0, n / 2) res.push_back(2);
        cout << sz(ops) << '\n';
        for (auto &p : ops) cout << p.first << " " << p.second << '\n';
        reverse(all(res));
        cout << sz(res) << '\n';
        for (int x : res) cout << x << " ";
        cout << '\n';

    }

}