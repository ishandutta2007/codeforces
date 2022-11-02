#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
#define INF 0x3f3f3f3f
#define MOD 998244353LL
#define EPS 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 100005
int t;
ll n, a, d;
map<ll, ll> ree;
ll calc(ll x){
    if(x == 0) return 0;
    if(x == 1) return d;
    if(ree[x] != 0) return ree[x];

    ll res = 1e18;
    if(x <= 1e18/d) res = x*d;
    
    res = min(res, d*(x%2)+a+calc(x/2));
    if(x%2) res = min(res, d*(2-x%2)+a+calc(x/2+1));

    //cout << x << " " << res << "\n";
    return ree[x] = res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> d >> a;
    cout << calc(n) << "\n";
    
    return 0;
}