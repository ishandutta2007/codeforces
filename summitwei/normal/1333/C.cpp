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
ll ps[MN];
map<ll, int> ree;
int lb[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    ree[0] = 1;
    FOR(i, 1, n){
        cin >> a[i];
        ps[i] = ps[i-1]+a[i];
        if(ree[ps[i]] != 0) lb[i] = ree[ps[i]];
        else lb[i] = -1;
        ree[ps[i]] = i+1;
    }
    //FOR(i, 1, n) cout << lb[i] << " ";
    //cout << "\n";
    ll ans = 0;
    int cur = 0;
    FOR(i, 1, n){
        cur = max(cur, lb[i]);
        ans += (i-cur);
    }
    cout << ans << "\n";

    return 0;
}