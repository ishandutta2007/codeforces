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
#define MOD 998244353LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 500005
int n, m, k;

pair<pii, int> req[MN];
int ops[MN];

ll dp[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k >> m;
    F0R(i, m){
        cin >> req[i].f.s >> req[i].f.f >> req[i].s;
    }
    sort(req, req+m);
    ll ans = 1;
    F0R(bt, k){
        //cout << "doing " << bt << "\n";
        memset(ops, 0, sizeof ops);
        F0R(i, m){
            if(req[i].s & (1<<bt)){
                ops[req[i].f.s]++;
                ops[req[i].f.f+1]--;
            }
        }
        memset(dp, 0, sizeof dp);
        int lb = 0;
        int cur = 0;
        int cc = 0;
        ll csm = 1;
        dp[0] = 1;
        FOR(i, 1, n){
            cc += ops[i];
            //cout << "doing " << i << " with cc " << cc << "\n";
            
            if(cc == 0){
                //ll cdp = que(1, 1, n, lb, i);
                dp[i] = csm;
                //cout << i << " " << cdp << "\n";
                csm = (csm+dp[i])%MOD;
                //upd(1, 1, n, i, cdp);
            }

            while(cur < m && req[cur].f.f == i){
                if(!((1<<bt) & req[cur].s)){
                    int olb = lb;
                    lb = max(lb, req[cur].f.s);
                    FOR(i, olb, lb-1){
                        csm = (csm+MOD-dp[i])%MOD;
                    }
                }
                ++cur;
            }
            //cout << "lb now " << lb << "\n";
        }

        //ll tot = que(1, 1, n, lb, n);
        ll tot = csm;
        //cout << "got " << tot << "\n";
        ans = (ans*tot)%MOD;
    }
    cout << ans << "\n";
    return 0;
}