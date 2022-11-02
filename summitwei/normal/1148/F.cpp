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
#define MOD 1000000007
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)
 
#define MN 300005
int n;
pll vm[MN];
ll sm;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    cin >> n;
    F0R(i, n){
        cin >> vm[i].s >> vm[i].f;
        sm += vm[i].s;
    }
    sort(vm, vm+n);
 
    ll ans = 0;
    int cur = 0;
    FOR(i, 1, 62){
        ll cs = 0;
        while(cur < n && vm[cur].f < (1LL<<i)){
            //cout << "proc " << vm[cur].f << " " << vm[cur].s << "\n";
            ll res = vm[cur].f & ans;
            if(__builtin_parityll(res)){
                cs -= vm[cur].s;
            } else{
                cs += vm[cur].s;
            }
 
            cur++;
        }
        //cout << "after " << i << " cs is " << cs << " and ans is " << ans << "\n";
        if((sm>0) == (cs>0) && cs != 0){
            ans += (1LL<<(i-1));
        }
    }
    /*F0R(j, 62){
        ll cs = 0;
        F0R(i, n){
            if(vm[i].f & (1LL<<j)){
                //cs += vm[i].s;
                ll res = vm[cur].f & ans;
                if(__builtin_parityll(res)){
                    cs += vm[cur].s;
                } else{
                    cs -= vm[cur].s;
                }
            }
            if((sm > 0) == (cs > 0) && cs != 0){
                ans += (1LL<<(j));
            }
        }
    }*/
 
    cout << ans << "\n";
 
    return 0;
}