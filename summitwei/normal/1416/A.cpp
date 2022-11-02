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

#define MN 300005 //check limits you incompetent ree
int n;
int a[MN];
vi cnt[MN];
pii res[MN];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    F0R(_, t){
        cin >> n;
        FOR(i, 1, n){
            cin >> a[i];
            cnt[a[i]].pb(i);
        }
        FOR(i, 1, n){
            res[i].s = i;
            int mx = 0;
            int pv = 0;
            for(auto u : cnt[i]){
                mx = max(mx, u-pv);
                pv = u;
            }
            mx = max(mx, n+1-pv);
            res[i].f = mx;
            //cout << i << " " << mx << "\n";
        }
        sort(res+1, res+n+1);
        int cur=1;
        int mn = INF;
        FOR(i, 1, n){
            while(cur != n && res[cur].f == i){
                mn = min(mn, res[cur].s);
                ++cur;
            }
            if(mn==INF) cout << "-1 ";
            else cout << mn << " ";
        }
        cout << "\n";
        FOR(i, 1, n) cnt[i].clear();
    }

    return 0;
}