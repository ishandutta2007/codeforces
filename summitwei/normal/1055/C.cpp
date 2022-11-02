#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
#define INF 1000000000
#define MOD 1000000007
#define EPSILON 0.00001
#define MAX_N 100005
#define fi first
#define se second

#define FOR(i, a, b) for (int i=(a); i<=(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

ll mod(ll a, ll b){
    return ((a%b)+b)%b;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll l1, r1, t1, l2, r2, t2;
    cin >> l1 >> r1 >> t1 >> l2 >> r2 >> t2;

    ll tgcd = __gcd(t1, t2);

    ll aRes = mod(l2-l1, tgcd);
    ll aSt = l1+aRes;

    ll aRan = max(min(r2-l2+1, r1-aSt+1), (ll)0);

    ll bRes = mod(l1-l2, tgcd);
    ll bSt = l2 + bRes;
    ll bRan = max(min(r1-l1+1, r2-bSt+1), (ll)0);

    //cout << aRes << " " << aSt << " " << aRan << " " << bRes << " " << bSt << " " << bRan << "\n";
    cout << max(aRan, bRan) << "\n";
    return 0;
}