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
typedef pair<ll, int> pli;
typedef vector<int> vi;

const int N = (int)2e5 + 50;

int n, p[N];
ll k;
string str;

int res[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        rep(i, 0, n) cin >> p[i];
        cin >> str;
        vi idx(n);
        iota(all(idx), 0);
        sort(all(idx), [&](const int i, const int j) {
            return str[i] == str[j] ? p[i] < p[j] : str[i] < str[j];
        });
//        ll res = 0;
        rep(i, 0, n) {
            res[idx[i]] = i + 1;
//            res += abs(i - p[idx[i]]);
        }
        rep(i, 0, n) cout << res[i] << " ";
        cout << endl;
//        cout << res </**/< '\n';

    }

}