#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define INF 1000000000
#define MOD 1000000007
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)
 
#define MN 250005
int n; ll m;
ll fac[MN];
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    cin >> n >> m;
    fac[0] = 1;
    FOR(i, 1, n){
        fac[i] = (fac[i-1]*i)%m;
    }
    ll sm = 0;
    FOR(i, 1, n){
        ll amt = n+1-i;
        ll facts = (fac[i]*fac[n-i])%m;
        ll logic = (amt*amt)%m;
        sm += (facts*logic)%m;
        sm %= m;
    }
    cout << sm << "\n";
 
    return 0;
}