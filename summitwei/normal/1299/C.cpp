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
#define MOD 1000000007
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)
 
#define MN 1000005
int n;
ll a[MN];
ll ps[MN];
int opt[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    FOR(i, 1, n){
        cin >> a[i];
        ps[i] = ps[i-1]+a[i];
    }
    int rt = n;
    ll sm = a[n];
    opt[n] = n;
    RFOR(i, n-1, 1){
        if(a[i]*(rt-i) < sm){
            opt[i] = i;
            rt = i;
            sm = a[i];
        } else{
            opt[i] = rt;
            sm += a[i];
            if(rt == n) continue;
            bool ree = true;
            do{
                int o = opt[rt+1];
                ll sm2 = ps[o]-ps[i-1];
                //cout << i << " " << rt << " " << sm << " " << o << " " << sm2 << "\n";
                if(sm2*(rt-i+1) <= sm*(o-i+1)){
                    opt[i] = o;
                    sm = sm2;
                    rt = o;
                } else{
                    ree = false;
                }
            } while(ree && rt != n);
        }
    }
    int i = 1;
    while(i <= n){
        int j = opt[i];
        long double avg = (ps[j]-ps[i-1])/((long double)(j-i+1));
        FOR(_, i, j){
            cout << fixed << setprecision(10) << avg << "\n";
        }
        i = j+1;
    }
    
    return 0;
}