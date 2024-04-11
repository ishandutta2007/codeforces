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
typedef vector<ll> vll;
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

#define MN 305
int n;
map<int, int> a;
int m;
vi b;
ll dp[MN][MN];

ll fac[MN];
ll ch[MN][MN];
void gch(){
    fac[0] = 1;
    ch[0][0] = 1;
    FOR(i, 1, MN-2){
        fac[i] = (fac[i-1]*i)%MOD;
        FOR(j, 0, i){
            ch[i][j] = (ch[i-1][j]+(j==0?0:ch[i-1][j-1]))%MOD;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    gch();

    cin >> n;
    FOR(i, 1, n){
        int x;
        cin >> x;
        for(int j=2; j*j<=x; ++j){
            while(x % (j*j) == 0){
                x /= (j*j);
            }
        }
        a[x]++;
    }
    for(auto u : a){
        b.pb(u.s);
    }
    m = b.size();
    /*for(auto u : a) cout << u.s << " ";
    cout << "\n";*/
    //memset(dp, -1, sizeof dp);
    //cout << calc(1, n) << "\n";
    dp[0][0] = 1;
    int amt = 0;
    F0R(i, m){
        FOR(j, 0, amt){
            //cout << i << " " << j << " " << dp[i][j] << "\n";
            FOR(reg, 1, min(b[i], amt+1)) FOR(yeet, 0, min(j, reg)){
                //cout << reg << " " << yeet << " get ";
                int nw = j+(b[i]-reg)-yeet;
                ll spl = (fac[b[i]]*ch[b[i]-1][reg-1])%MOD;
                ll oth = (ch[j][yeet]*ch[amt+1-j][reg-yeet])%MOD;
                ll fin = (spl*oth)%MOD;
                //cout << fin << " " << nw << "\n";
                dp[i+1][nw] = (dp[i+1][nw]+(fin*dp[i][j]))%MOD;
            }
        }
        amt += b[i];
    }
    cout << dp[m][0] << "\n";

    return 0;
}