#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
#define INF 0x3f3f3f3f
#define MOD 1000000007LL
#define EPS 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 1005
int t;
int n;
int a[MN];
int cnt[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;
    F0R(_, t){
        vi res;
        cin >> n;
        FOR(i, 1, n){
            cin >> a[i];
        }
        while(true){
            //cout << "hi\n";
            memset(cnt, 0, sizeof cnt);
            FOR(i, 1, n) cnt[a[i]]++;
            int z = 0;
            while(cnt[z] != 0) ++z;
            //cout << "mex is " << z << "\n";
            a[n+1] = n+1;
            int l=n;
            while(a[l]==a[l+1]-1) --l;
            if(l==z){
                res.pb(l);
                a[l] = z;
                //cout << "set " << l << " " << z << "\n";
            } else{
                res.pb(z+1);
                a[z+1] = z;
                //cout << "set " << z+1 << " " << z << "\n";
            }
            bool ok = true;
            FOR(i, 1, n-1) if(a[i]>=a[i+1]) ok=false;
            if(ok) break;
        }
        cout << res.size() << "\n";
        for(auto u : res) cout << u << " ";
        cout << "\n";
    }
    
    return 0;
}