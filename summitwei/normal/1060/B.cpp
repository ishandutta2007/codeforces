#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define INF 0x3f3f3f3f
#define MOD 1000000007LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 100005


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;
    if(n <= 9){ cout << n << "\n"; return 0;}
    ll ns = 9;
    while(ns*10+9 <= n) ns = ns*10+9;
    ll o = n-ns;
    ll ans = 0;
    while(ns > 0){
        ans += ns%10;
        ns /= 10;
    }
    while(o > 0){
        ans += o%10;
        o /= 10;
    }
    cout << ans << "\n";
    
    return 0;
}