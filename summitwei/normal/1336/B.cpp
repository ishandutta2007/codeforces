#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<long long> vll;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define INF 0x3f3f3f3f3f3f3f3fLL
#define MOD 1000000007LL
#define EPSILON 0.00001
#define f first
#define s second
//#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 300005
int t;
int nr, ng, nb;
ll r[MN], b[MN], g[MN];
pll tot[MN];
ll lft[3][MN], rt[3][MN];

ll calc(ll a, ll b, ll c){
    if(a == -1 || b == -1 || c == -1) return INF;
    return (a-b)*(a-b)+(a-c)*(a-c)+(b-c)*(b-c);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;
    F0R(_, t){
        cin >> nr >> ng >> nb;
        F0R(i, nr){
            cin >> r[i];
            tot[i] = {r[i], 0};
        }
        F0R(i, ng){
            cin >> g[i];
            tot[nr+i] = {g[i], 1};
        }
        F0R(i, nb){
            cin >> b[i];
            tot[nr+ng+i] = {b[i], 2};
        }
        sort(tot, tot+nr+ng+nb);
        ll pr = -1, pg = -1, pb = -1;
        F0R(i, nr+ng+nb){
            if(tot[i].s == 0){
                pr = tot[i].f;
            } else if(tot[i].s == 1){
                pg = tot[i].f;
            } else{
                pb = tot[i].f;
            }
            lft[0][i] = pr; lft[1][i] = pg; lft[2][i] = pb;
        }
        
        pr = -1, pg = -1, pb = -1;
        RFOR(i, nr+ng+nb-1, 0){
            if(tot[i].s == 0){
                pr = tot[i].f;
            } else if(tot[i].s == 1){
                pg = tot[i].f;
            } else{
                pb = tot[i].f;
            }
            rt[0][i] = pr; rt[1][i] = pg; rt[2][i] = pb;
        }

        ll ans = INF;
        F0R(i, nr+ng+nb){
            if(tot[i].s == 0){
                ans = min(ans, calc(tot[i].f, lft[1][i], rt[2][i]));
                ans = min(ans, calc(tot[i].f, lft[2][i], rt[1][i]));
            } else if(tot[i].s == 1){
                ans = min(ans, calc(tot[i].f, lft[0][i], rt[2][i]));
                ans = min(ans, calc(tot[i].f, lft[2][i], rt[0][i]));
            } else{
                ans = min(ans, calc(tot[i].f, lft[1][i], rt[0][i]));
                ans = min(ans, calc(tot[i].f, lft[0][i], rt[1][i]));
            }
        }
        cout << ans << "\n";
    }
    
    return 0;
}