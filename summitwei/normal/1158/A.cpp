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

#define MN 100005
int n, m;
ll b[MN];
ll g[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    ll mx = 0, mn = INF;
    ll smb = 0;
    ll smg = 0;
    F0R(i, n){
        cin >> b[i];
        mx = max(mx, b[i]);
        smb += b[i];
    }
    F0R(i, m){
        cin >> g[i];
        mn = min(mn, g[i]);
        smg += g[i];
    }

    if(mx > mn){
        cout << "-1\n";
        return 0;
    }
    sort(b, b+n, greater<ll>());

    ll tot = smb*m;
    tot -= (b[0]*m);
    tot += smg;
    if(mx != mn) tot = tot + b[0]-b[1];

    cout << tot << "\n";
    
    return 0;
}