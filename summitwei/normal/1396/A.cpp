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
#define MOD 1000000007LL
#define EPS 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 100005
ll n;
ll a[MN];

pll gcd(ll a, ll b){ //a*first+b*second=gcd
    if(a == 0){
        return mp(0, 1);
    }
 
    pll prev = gcd(b%a, a);
 
    return mp(prev.s-(b/a)*prev.f, prev.f);
} //using ll's just to be safe wrt overflow issues
pll x[MN];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    FOR(i, 1, n){
        cin >> a[i];
    }
    if(n==1){
        cout << "1 1\n" << -a[1] << "\n";
        cout << "1 1\n0\n1 1\n0\n";
        return 0;
    }
    FOR(i, 1, n-1){
        x[i] = {-n*a[i], (n-1)*a[i]};
    }
    cout << "1 " << n << "\n";
    FOR(i, 1, n-1) cout << x[i].f << " ";
    cout << "0\n";
    cout << "1 " << n-1 << "\n";
    FOR(i, 1, n-1) cout << x[i].s << " ";
    cout << "\n";
    cout << n << " " << n << "\n";
    cout << -a[n] << "\n";

    return 0;
}