#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (n); i++)
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define f first
#define s second
#define rand(i, j) uniform_int_distribution<ll>((ll)(i), (ll)(j))(rng)
mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
    cout << "["; for (int i = 0; i < (int)v.size(); i++) {if (i) cout << ", "; cout << v[i]; } return cout << "]";
}
template<typename T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<typename T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }


//2 147 483 647 int max
//9 223 372 036 854 775 807 ll max


int main(){
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    if(m == 3 && n > 4) {
        cout << -1 << "\n";
        return 0;
    }

    const ld mx = 5e7;

    vector<pair<ll, ll>> ans;
    forn(i, m) {
        ld ang = 2*3.1415926*i/m + rand(0,100)/100000.0;
        // cout << ang << "\n";

        ans.pb({(int) (mx*cos(ang)), (int) (mx*sin(ang))});
        if(i+m < n) {
            ans.pb({(int) ((mx*.99)*cos(ang+.0001)), (int) ((mx*.99)*sin(ang+.0001))});

        }
    }

    // cout << ans << "\n";

    assert(ans.size() == n);
    forn(i, n) {
        cout << ans[i].f << " " << ans[i].s << "\n";
    }
}