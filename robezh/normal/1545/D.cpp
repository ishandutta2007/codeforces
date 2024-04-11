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

const int N = 1005;

int n, m;
int a[N][N];
ll sum1[N], sum2[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> m >> n;

    rep(i, 0, n) {
        rep(j, 0, m) {
            cin >> a[i][j];
            sum1[i] += a[i][j];
            sum2[i] += 1LL * a[i][j] * a[i][j];
        }
    }
    map<ll, int> d1;
    rep(i, 1, n) d1[sum1[i] - sum1[i - 1]]++;
    ll d = 0;
    for (auto &p : d1) {
        if(p.second >= n - 3) {
            d = p.first;
        }
    }


    map<ll, int> cnt;
    ll s2 = 0;

    rep(i, 1, n - 1) {
        if(sum1[i] - sum1[i - 1] == d) continue;

        if(i >= 3) s2 = (sum2[0] + sum2[2] - sum2[1] * 2) ;
        else s2 = (sum2[n - 3] + sum2[n - 1] - 2 * sum2[n - 2]);

        ll c1 = (sum1[i - 1] + sum1[i + 1]) / 2;
        ll c2 = (sum2[i - 1] + sum2[i + 1] - s2) / 2;
        ll add = c1 - sum1[i];
        rep(j, 0, m) {
            if(sum2[i] - 1LL * a[i][j] * a[i][j] + 1LL * (a[i][j] + add) * (a[i][j] + add) == c2) {
                cout << i << " " << (a[i][j] + add) << "\n";
                return 0;
            }
        }
    }
    assert(false);
    return 0;

}