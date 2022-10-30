#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
#define INF 0x3f3f3f3f
#define MOD 1000000007LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
#define FOR(i, a, b) for (ll i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (ll i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 200005
ll n;
ll a[MN];
set<ll> chked;

ll get(ll x, ll y){
    if(x < y) return y-x;
    x %= y;
    return min(x, y-x);
}
ll chk(ll x){
    if(chked.count(x)) return n;
    chked.insert(x);
    if(x <= 1) return n;
    ll ans = 0;
    F0R(i, n){
        ans += get(a[i], x);
        if(ans > n) return n;
    }
    //cout << x << " " << ans << "\n";
    return ans;
}
ll fac(ll x){
    if(x <= 1) return n;
    ll res = n;
    for(ll i=2; i*i<=x; ++i){
        if(x != 0 && x % i == 0){
            while(x != 0 && x % i == 0) x /= i;
            res = min(res, chk(i));
        }
    }
    if(x != 1) res = min(res, chk(x));
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    unsigned seed1 = std::chrono::system_clock::now().time_since_epoch().count();
    mt19937 bruh(seed1);

    cin >> n;
    F0R(i, n){
        cin >> a[i];
    }

    ll ans = n;
    F0R(_, 20){
        ll ree = bruh() % n;
        ans = min(min(ans, fac(a[ree]-1)), min(fac(a[ree]), fac(a[ree]+1)));
    }
    cout << ans << "\n";

    return 0;
}