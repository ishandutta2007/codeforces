#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
#define INF 1000000000
#define MOD 998244353
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define p_q priority_queue

#define FOR(i, a, b) for (int i=(a); i<=(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MAX_N 1000005

ll facs[MAX_N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;

    ll nfact = 1;
    FOR(x, 2, n){
        nfact = (x*nfact) % MOD;
    }

    //cout << nfact << "\n";
    ll ans = nfact;

    ll fact = 1;
    RFOR(b, n-1, 2){
        fact = (fact*(b+1))%MOD;
        ans = (ans+(nfact-fact)) % MOD;
    }

    cout << (ans+MOD)%MOD << "\n";

    return 0;
}