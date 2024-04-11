#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
#define INF 0x3f3f3f3f3f3f3f3fLL
#define MOD 998244353LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
#define FOR(i, a, b) for (ll i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (ll i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 1000005
int n, m, k;
ll cmn[MN]; //per town
ll tcstf[MN];
ll tcstb[MN];
pair<ll, pll> tow[MN], bck[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> k;
    int a=0, b=0;
    F0R(_, m){
        int d, f, t, c;
        cin >> d >> f >> t >> c;
        if(t == 0){
            tow[a] = {d, {f, c}};
            ++a;
        } else{
            bck[b] = {d, {t, c}};
            ++b;
        }
    }
    sort(tow, tow+a);
    sort(bck, bck+b);

    memset(cmn, 0x3f, sizeof cmn);
    ll sm = 0;
    int ppl = 0;
    int cur = 0;
    FOR(i, 1, MN-5){
        while(cur < a && tow[cur].f == i){
            int guy = tow[cur].s.f;
            if(cmn[guy] == INF){
                ++ppl;
                cmn[guy] = tow[cur].s.s;
                sm += cmn[guy];
            }
            sm -= cmn[guy];
            cmn[guy] = min(cmn[guy], tow[cur].s.s);
            sm += cmn[guy];

            ++cur;
        }
        if(ppl == n){
            tcstf[i] = sm;
            //if(i <= 20) cout << "got " << i << " " << sm << " fwd\n";
        } else{
            tcstf[i] = INF;
        }
    }
    memset(cmn, 0x3f, sizeof cmn);
    sm = 0; ppl = 0; cur = b-1;
    RFOR(i, MN-5, 1){
        while(cur >= 0 && bck[cur].f == i){
            int guy = bck[cur].s.f;
            if(cmn[guy] == INF){
                ++ppl;
                cmn[guy] = bck[cur].s.s;
                sm += cmn[guy];
                //cout << "found one on " << i << "\n";
            }
            sm -= cmn[guy];
            cmn[guy] = min(cmn[guy], bck[cur].s.s);
            sm += cmn[guy];

            --cur;
        }
        if(ppl == n){
            tcstb[i] = sm;
            //if(i <= 20) cout << "got " << i << " " << sm << " bck\n";
        } else{
            tcstb[i] = INF;
        }
    }

    ll ans = INF;
    FOR(i, 1, MN-5){
        int o = i+k+1;
        if(o > MN-5) continue;
        ans = min(ans, tcstf[i]+tcstb[o]);
    }

    if(ans == INF) ans = -1;

    cout << ans << "\n";

    return 0;
}