#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
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
 
#define MN 100005
int n;
int l[MN];
vi s[MN];
int sn[MN];
int mn[MN], mx[MN];
vi bad;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    cin >> n;
    F0R(i, n){
        cin >> l[i];
        int cmn = INF;
        int cmx = -1;
        F0R(j, l[i]){
            int x;
            cin >> x;
            s[i].pb(x);
            if(x > cmn){
                sn[i] = true;
                //cout << i << " good " << x << "\n";
            }
            cmx = max(cmx, x);
            cmn = min(cmn, x);
        }
        mn[i] = cmn;
        mx[i] = cmx;
        if(!sn[i]){
            bad.pb(mx[i]);
            //cout << mx[i] << " ";
        }
    }
    //cout << "\n";
    sort(bad.begin(), bad.end());
    ll sm = 0;
    F0R(i, n){
        if(sn[i]) continue;
        //cout << "counting " << mn[i] << " " << sm << "\n";
        sm += upper_bound(bad.begin(), bad.end(), mn[i]) - bad.begin();
    }
    //cout << sm << "\n";
 
    cout << 1LL*n*n-sm << "\n";
 
    return 0;
}