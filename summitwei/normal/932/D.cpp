#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
typedef long double ld;
#define INF 10000000000000000LL
#define MOD 1000000007LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 400005
#define ML 20 //FIX
int q;
int n;
int up[MN][ML];
int par[MN][ML];
ll mx[MN][ML];
ll sms[MN][ML];
ll w[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll lst = 0;
    cin >> q;
    n = 1;
    w[0] = INF;
    F0R(i, ML){
        mx[0][i] = INF;
        sms[0][i] = INF;
        if(i != 0){
            mx[1][i] = INF;
            sms[1][i] = INF;
        }
    }
    F0R(_, q){
        int t; ll p, q;
        cin >> t >> p >> q;
        p ^= lst; q ^= lst;
        //cout << "really " << t << " " << p << " " << q << "\n";
        if(t == 1){
            ++n;
            w[n] = q;
            par[n][0] = p;
            mx[n][0] = q;
            FOR(i, 1, ML-1){
                par[n][i] = par[par[n][i-1]][i-1];
                mx[n][i] = max(mx[n][i-1], mx[par[n][i-1]][i-1]);
            }
            int cur = par[n][0];
            RFOR(i, ML-1, 0){
                if(mx[cur][i] < q){
                    cur = par[cur][i];
                }
            }
            //cout << "up from " << n << " " << cur << "\n";
            up[n][0] = cur;
            sms[n][0] = q; //not including the one it hits
            FOR(i, 1, ML-1){
                up[n][i] = up[up[n][i-1]][i-1];
                sms[n][i] = sms[n][i-1] + sms[up[n][i-1]][i-1];
                //cout << n << " " << i << " " << up[n][i] << " " << sms[n][i] << "\n";
            }
        } else{
            int amt = 0;
            int cur = p;
            ll sm = 0;
            RFOR(i, ML-1, 0){
                if(sms[cur][i]+sm <= q){
                    amt += (1<<i);
                    sm += sms[cur][i];
                    cur = up[cur][i];
                }
            }
            cout << amt << "\n";
            lst = amt;
        }
    }

    return 0;
}