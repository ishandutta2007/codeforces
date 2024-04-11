#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
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

#define MN 30
int t;
int n;
int cur[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;
    F0R(_, t){
        cin >> n;
        int res = 1;
        int ans = 0;
        while(res*2-1 < n){ res *= 2; ++ans; }
        cur[0] = 1;
        //cout << "1 ";
        FOR(i, 1, ans){
            cur[i] = 1<<i;
            //cout << cur[i] << " ";
        }
        //cout << "\n";

        int tl = res*2-1-n;
        RFOR(i, ans, 1){
            int cl = min(tl, 1<<(i-1));
            //cout << "losing " << cl << "\n";
            tl -= cl; cur[i] -= cl;
        }
        //FOR(i, 0, ans) cout << cur[i] << " ";
        //cout << "\n";
        cout << ans << "\n";
        FOR(i, 1, ans){
            cout << cur[i]-cur[i-1] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}