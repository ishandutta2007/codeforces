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

#define MN 300005
#define MM 15000005
int n;
int a[MN];
map<int, pii> ree; //smallest used & freq
map<int, int> tot;
int fac[MM];
bool fou[MM];
vi pri;
void linsie(){
    fou[0] = fou[1] = true;
    FOR(i, 2, MM-5){
        //cout << "doing " << i << "\n";
        if(!fou[i]){
            pri.pb(i);
            fac[i] = i;
        }
        for(auto u : pri){
            //cout << "chking " << u << "\n";
            if(i*u > MM-5 || u > fac[i]) break;
            //cout << "didn't break\n";
            fou[i*u] = true;
            fac[i*u] = u;
            //cout << i*u << " found\n";
        }
        //cout << i << " smallest fac is " << fac[i] << "\n";
    }
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    linsie();
 
    cin >> n;
    F0R(i, n){
        cin >> a[i];
        while(a[i] != 1){
            int cf = fac[a[i]];
            int cnt = 0;
            while(a[i] % cf == 0){
                //cout << "hi\n";
                a[i] /= cf;
                ++cnt;
            }
            if(ree[cf].f == 0 || ree[cf].f > cnt){
                ree[cf] = {cnt, 1};
            } else if(ree[cf].f == cnt){
                ree[cf].s++;
            }
            ++tot[cf];

            //cout << i << " " << cf << " " << cnt << "\n";
        }
    }
    int ans = n;
    for(auto &u : ree){
        int val = u.f;
        //cout << val << " " << u.s.f << " " << u.s.s << " " << tot[val] << "\n";
        if(tot[val] != n){
            u.s = {0, n-tot[val]};
        }
        ans = min(ans, u.s.s);
    }
    if(ans == n) ans = -1;
    cout << ans << "\n";

    return 0;
}