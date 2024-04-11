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

#define MN 5005
ll n, l, r, k;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    cin >> n >> l >> r >> k;
    r = (r-l+n)%n+1;
    ll ans = -1;
    ll o = n-r;
    if(n <= 5000){
        FOR(i, 0, r){
            FOR(j, 0, o){
                ll per = r+i+j+o;
                ll res = (k-1)%per+1;
                //cout << "checking " << i << " " << j << " " << per << " " << res << "\n";
                if(res == r+i){
                    ans = max(ans, i+j);
                }
                if(res+1 == r+i && i != 0){
                    ans = max(ans, i+j);
                }
            }
        }
        cout << ans << "\n";
    } else{
        FOR(i, 0, k/n){ //# of full loops
            if(i == 0){
                if(r*2 < k || r > k) continue;

                ans = max(ans, n-r*2+k); //take care of last guy sweet 1?
                if(r*2 != k) ++ans;
                continue;
            }
            ll ot = r*i+o*i+r;
            if(ot > k) continue;
            ll ls = k-ot;
            ll sma = ls%i;
            ll lgb = (ls-sma)/i-sma;
            //cout << i << " " << ot << " " << ls << " " << sma << " " << lgb << "\n";
            if(lgb > o){
                ll dif = lgb-o;
                ll ch = (dif+i)/(i+1);
                lgb -= ch*(i+1);
                sma += ch*i;
            }
            /*if(lgb == -1){
                ans = max(ans, sma-1);
            }*/
            if(lgb < 0 || sma > r) continue;
            ans = max(ans, lgb+sma);
        }
        FOR(i, 1, k/n){ //top guy has 2
            ll ot = r*i+o*i+r;
            if(ot > k+1) continue;
            ll ls = k+1-ot;
            ll sma = ls%i;
            ll lgb = (ls-sma)/i-sma;
            //cout << i << " " << ot << " " << ls << " " << sma << " " << lgb << "\n";
            if(lgb > o){
                ll dif = lgb-o;
                ll ch = (dif+i)/(i+1);
                lgb -= ch*(i+1);
                sma += ch*i;
            }
            /*if(lgb == -1){
                ans = max(ans, sma-1);
            }*/
            if(lgb < 0 || sma > r || sma == 0) continue;
            ans = max(ans, lgb+sma);
        }
        cout << ans << "\n";
    }

    return 0;
}