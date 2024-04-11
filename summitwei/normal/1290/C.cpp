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
 
#define MN 300005
int n, k;
string s;
vi tog[MN];
 
int dsu[MN];
int p[MN];
int sz[MN];
ll odd[MN]; //cost if you take this guy
ll tot[MN]; //total cost, to deal with stupid edges
pii fd(int x){
    if(dsu[x] == x) return {x, 0};
    pii val = fd(dsu[x]);
    return {val.f, val.s ^ 1 ^ p[x]};
}
ll ans;
void jn(int x, int y, int d){ //0 if same, 1 if diff
    pii r1 = fd(x), r2 = fd(y);
    d = d ^ r1.s ^ r2.s;
    x = r1.f; y = r2.f;
    if(x == y) return;
    if(sz[x] < sz[y]) swap(x, y);
    //cout << "merging " << x << " " << y << " " << d << "\n";
 
    ans -= min(odd[x], tot[x]-odd[x]);
    ans -= min(odd[y], tot[y]-odd[y]);
    sz[x] += sz[y];
    tot[x] += tot[y];
    dsu[y] = x;
    p[y] = d;
    if(d == 0){
        odd[x] += (tot[y]-odd[y]);
    } else{
        odd[x] += odd[y];
    }
    //cout << x << " " << odd[x] << " " << tot[x] << "\n";
    ans += min(odd[x], tot[x]-odd[x]);
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    cin >> n >> k;
    cin >> s;
    FOR(i, 1, k){
        dsu[i] = i;
        sz[i] = 1;
        tot[i] = 1;
        odd[i] = 1;
    }
    FOR(i, 1, k){
        int c;
        cin >> c;
        F0R(_, c){
            int x;
            cin >> x;
            tog[x].pb(i);
        }
    }
 
    FOR(i, 1, n){
        if(tog[i].size() == 0){
            cout << ans << "\n";
            continue;
        }
        if(tog[i].size() == 1){
            int v = tog[i][0];
            pii res = fd(v);
            v = res.f;
            int d = res.s ^ (s[i-1]-'0');
            //cout << "hmm " << v << "\n";
            ans -= min(odd[v], tot[v]-odd[v]);
            tot[v] += MN;
            if(d){
                odd[v] += MN;
            }
            //cout << tot[v] << " " << odd[v] << " " << v << "\n";
            ans += min(odd[v], tot[v]-odd[v]);
            cout << ans << "\n";
            continue;
        }
        int u = tog[i][0], v = tog[i][1];
        jn(u, v, s[i-1]-'0');
        cout << ans << "\n";
    }
 
    return 0;
}