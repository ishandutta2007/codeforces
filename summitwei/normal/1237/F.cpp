#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define INF 1000000000
#define MOD 998244353LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 3605
int h, w, n;
int sh, sw;
bool rw[MN];
bool cl[MN];
ll dp[MN][MN][2]; //# of ways to place j 2-doms in first i rows

ll fac[MN];
pll gcd(ll a, ll b){ //a*first+b*second=gcd
    if(a == 0){
        return mp(0, 1);
    }

    pll prev = gcd(b%a, a);

    return mp(prev.s-(b/a)*prev.f, prev.f);
} //using ll's just to be safe wrt overflow issues
ll modInv(ll x){ //return x^-1 % MOD
    pll res = gcd(x, MOD);

    res.f = (res.f+MOD)%MOD;

    //cout << "modinv of " << x << " is " << res.f << "\n";

    return res.f;
}
ll modDiv(ll x, ll y){
    return (x*modInv(y))%MOD;
}
ll getFacs(){
    fac[0] = 1;
    FOR(i, 1, MN-1){
        fac[i] = (fac[i-1]*i)%MOD;
    }
}
ll choose(ll a, ll b){
    ll c = a-b;
    if(c < 0){
        cout << "ur bad\n";
        exit(0);
    }

    ll num = fac[a];
    ll denom = (fac[b]*fac[c])%MOD;

    //cout << "num " << num << " denom " << denom << "\n";

    return modDiv(num, denom);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    getFacs();

    cin >> h >> w >> n;
    sh = h; sw = w;
    F0R(i, n){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        rw[a] = cl[b] = rw[c] = cl[d] = true;
        if(a == c){
            --sh;
            sw -= 2;
        } else{
            --sw;
            sh -= 2;
        }
    }
    dp[0][0][0] = 1;
    dp[1][0][0] = 1;
    FOR(i, 2, h){
        dp[i][0][0] = 1;
        FOR(j, 1, h){
            dp[i][j][0] = dp[i-1][j][0];
            if(!rw[i] && !rw[i-1]){
                dp[i][j][0] += dp[i-2][j-1][0];
                dp[i][j][0] %= MOD;
            }
        }
    }
    dp[0][0][1] = 1;
    dp[1][0][1] = 1;
    FOR(i, 2, w){
        dp[i][0][1] = 1;
        FOR(j, 1, w){
            dp[i][j][1] = dp[i-1][j][1];
            if(!cl[i] && !cl[i-1]){
                dp[i][j][1] += dp[i-2][j-1][1];
                dp[i][j][1] %= MOD;
            }
        }
    }
    //cout << sh << " " << sw << "\n";
    ll sm = 0;
    FOR(i, 0, h){
        FOR(j, 0, w){
            if(2*i+j > sh || 2*j+i > sw) continue;
            //cout << "doing " << i << " horiz " << j << " vert\n";
            ll oa = sh-2*i;
            ll ob = sw-2*j;
            ll cha1 = dp[h][i][0];
            ll cha2 = choose(oa, j);
            ll cha3 = fac[i];
            ll chb1 = dp[w][j][1];
            ll chb2 = choose(ob, i);
            ll chb3 = fac[j];
            ll ree = 1;
            ree = (ree*cha1)%MOD;
            ree = (ree*cha2)%MOD;
            ree = (ree*cha3)%MOD;
            ree = (ree*chb1)%MOD;
            ree = (ree*chb2)%MOD;
            ree = (ree*chb3)%MOD;
            sm = (sm+ree)%MOD;
            //cout << cha1 << " " << cha2 << " " << cha3 << " " << chb1 << " " << chb2 << " " << chb3 << "\n";
        }
    }
    cout << sm << "\n";    

    return 0;
}