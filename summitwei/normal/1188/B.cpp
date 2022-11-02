#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
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
#define RFOR(i, a, b) for (ll i=(a); i >= b; i--)

#define MN 300005
int n, p, k;
ll a[MN];
map<ll, int> ree;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> p >> k;
    ll ans = 0;
    F0R(i, n){
        ll x;
        cin >> x;
        ll y = (x*x)%p;
        ll z = (y*y)%p;
        ll bruh = z-(k*x)%p;
        bruh = (bruh+p)%p;
        ans += ree[bruh];
        ree[bruh]++;
    }
    cout << ans << "\n";
    
    return 0;
}