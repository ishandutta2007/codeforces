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
int n, m;
pll ch[MN];
vector<pair<pii, ll> > ree;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    F0R(_, m){
        int u, v; ll d;
        cin >> u >> v >> d;
        ch[v].f += d;
        ch[u].f -= d;
    }
    FOR(i, 1, n) ch[i].s = i;

    sort(ch+1, ch+1+n);

    int l = 1, r=n;
    while(l<r){
        ll mn = min(-ch[l].f, ch[r].f);
        if(mn == 0) break;
        ree.pb({{ch[l].s, ch[r].s}, mn});
        //cout << ch[l].s << " " << ch[r].s << " " << mn << "\n";
        ch[l].f += mn;
        ch[r].f -= mn;
        while(l <= n && ch[l].f == 0) ++l;
        while(r >= 1 && ch[r].f == 0) --r;
    }
    cout << ree.size() << "\n";
    for(auto u : ree){
        cout << u.f.f << " " << u.f.s << " " << u.s << "\n";
    }
    
    return 0;
}