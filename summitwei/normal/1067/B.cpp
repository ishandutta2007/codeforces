#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define INF 1000000000000LL
#define MOD 998244353LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 100005
int n; ll k;
vi e[MN];

int d[MN][2];

pii far(int cn, int p){ //{dist, node}
    pii ans = {-1, cn};
    for(auto nn : e[cn]) if(nn != p){
        pii res = far(nn, cn);
        ans = max(ans, res);
    }
    ++ans.f;
    return ans;
}
pair<int, pii> diam(){
    pii res1 = far(1, 0);
    pii res2 = far(res1.s, 0);
    return {res2.f, {res1.s, res2.s}};
}
void gd(int cn, int p, int tp){
    for(auto nn : e[cn]) if(nn != p){
        d[nn][tp] = d[cn][tp]+1;
        gd(nn, cn, tp);
    }
}

bool chk(int cn, int p, int lay){
    if(lay == k){
        if(e[cn].size() == 1){
            return true;
        } else{
            return false;
        }
    }
    if(lay == 0){
        if(e[cn].size() < 3) return false;
    } else{
        if(e[cn].size() < 4) return false;
    }

    for(auto nn : e[cn]) if(nn != p){
        if(!chk(nn, cn, lay+1)) return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    F0R(_, n-1){
        int u, v;
        cin >> u >> v;
        e[u].pb(v);
        e[v].pb(u);
    }

    auto ree = diam();
    if(ree.f != k*2){
        cout << "No\n";
        return 0;
    }
    gd(ree.s.f, 0, 0);
    gd(ree.s.s, 0, 1);

    int cen = -1;
    FOR(i, 1, n){
        if(d[i][0] == k && d[i][1] == k){
            cen = i;
            break;
        }
    }

    if(chk(cen, 0, 0)){
        cout << "Yes\n";
    } else{
        cout << "No\n";
    }

    return 0;
}