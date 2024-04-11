#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
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
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 1000005
int n;
ll a[MN];
int p[MN];
vi ch[MN];
ll sm[MN];
//set<ll> sms;

void dfs(int cn){
    sm[cn] = a[cn];
    for(auto nn : ch[cn]){
        dfs(nn);
        sm[cn] += sm[nn];
    }
    //if(cn != 1) sms.insert(sm[cn]);
}
int cnt[MN];
int tot[MN];
bool ok[MN];
ll dp[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    FOR(i, 1, n){
        cin >> a[i];
    }
    FOR(i, 2, n){
        cin >> p[i];
        ch[p[i]].pb(i);
    }
    dfs(1);

    FOR(i, 1, n){
        ll gcd = __gcd(sm[1], sm[i]);
        ll res = sm[1]/gcd;
        //cout << res << " sat\n";
        if(res <= n) ++cnt[res];
    }
    FOR(i, 1, n){
        for(int j=i; j<=n; j+=i){
            tot[j] += cnt[i];
        }
        if(tot[i] == i) ok[i] = true;
        //cout << i << " " << tot[i] << "\n";
    }

    ll ans = 0;
    //ok[1] = true;
    dp[1] = 1;
    FOR(i, 1, n){
        if(ok[i]){
            ans = (ans+dp[i])%MOD;
            for(int j=i*2; j<=n; j+=i){
                dp[j] = (dp[j]+dp[i])%MOD;
            }
        }
    }
    cout << ans << "\n";

    return 0;
}