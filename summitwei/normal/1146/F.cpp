#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define INF 1000000000
#define MOD 998244353
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 200005

pll egcd(ll a, ll b){ //a*first+b*second=gcd
    if(a == 0){
        return mp(0, 1);
    }

    pll prev = egcd(b%a, a);

    return mp(prev.s-(b/a)*prev.f, prev.f);
} //using ll's just to be safe wrt overflow issues

ll modInv(ll x){ //return x^-1 % MOD
    pll res = egcd(x, MOD);

    res.f = (res.f+MOD)%MOD;

    //cout << "modinv of " << x << " is " << res.f << "\n";

    return res.f;
}

ll modDiv(ll x, ll y){
    return (x*modInv(y))%MOD;
}

int n;
int p[MN];
vi ch[MN];

ll dp[MN][3];

//dp[i] = answer @ i

//dp[i][0] = answer where i is used and good already
//dp[i][1] = answer where i is not used
//prod of dpch0+dpch1
//dp[i][2] = answer where i is used but you need to connect it
//dp[i][2] = sum of dpch0+dpch2 * other0or1
//all0+1 * dpch0+2/0+1

void dfs(int cn){
    if(ch[cn].size() == 0){
        dp[cn][0] = 1;
        return;
    }

    ll tot = 1;

    ll sm = 0;
    ll ree[3];
    ree[1] = 1;
    F0R(i, ch[cn].size()){
        int nn = ch[cn][i];

        dfs(nn);
        
        ree[1] = (ree[1]*(dp[nn][0]+dp[nn][1]))%MOD;
        ll num = (dp[nn][0]+dp[nn][2])%MOD;
        ll den = (dp[nn][0]+dp[nn][1])%MOD;
        sm += modDiv(num, den);
        sm %= MOD;
        tot *= (dp[nn][0]*2+dp[nn][1]+dp[nn][2])%MOD;
        tot %= MOD;
    }
    ree[2] = (ree[1]*sm)%MOD;
    ree[0] = (tot-ree[1]-ree[2])%MOD;
    ree[0] = (ree[0]+MOD)%MOD;
    F0R(i, 3){
        dp[cn][i] = ree[i];
        //cout << "ans at " << cn << " " << i << " is " << ree[i] << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    FOR(i, 2, n){
        cin >> p[i];
        ch[p[i]].pb(i);
    }
    
    dfs(1);
    cout << (dp[1][0]+dp[1][1])%MOD << "\n";
    
    return 0;
}