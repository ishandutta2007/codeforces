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
#define MOD 998244353LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 200005
int n, k;
int m[MN];
int c[MN];
int cnt[MN];
int ps[MN];
vi ree[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    F0R(i, n){
        cin >> m[i];
        cnt[m[i]]++;
    }
    RFOR(i, k, 1) ps[i] = ps[i+1]+cnt[i];
    int ans = 0;
    FOR(i, 1, k){
        cin >> c[i];
        ans = max(ans, (ps[i]+c[i]-1)/c[i]);
    }
    sort(m, m+n);
    RFOR(i, n-1, 0){
        ree[i%ans].pb(m[i]);
    }
    cout << ans << "\n";
    F0R(i, ans){
        cout << ree[i].size() << " ";
        for(auto u : ree[i]) cout << u << " ";
        cout << "\n";
    }
    
    return 0;
}