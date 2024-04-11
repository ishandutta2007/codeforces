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

#define MN 200005
int n;
ll a[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    F0R(i, n*2){
        cin >> a[i];
    }
    sort(a, a+2*n);
    ll ans = 1LL*(a[n-1]-a[0])*(a[2*n-1]-a[n]);
    FOR(i, 1, n){
        ll ot = (a[i+n-1]-a[i])*(a[2*n-1]-a[0]);
        ans = min(ans, ot);
    }
    cout << ans << "\n";
    
    return 0;
}