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
#define MOD 998244353
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 1005
int n;
vi e[MN];

int sz[MN];
void dfs(int cn){
    sz[cn] = 1;
    F0R(i, e[cn].size()){
        int nn = e[cn][i];

        if(sz[nn] != 0) continue;
        dfs(nn);
        sz[cn] += sz[nn];
    }
}

int fc(int cn){
    F0R(i, e[cn].size()){
        int nn = e[cn][i];

        if(sz[cn] > sz[nn] && sz[nn] > n/2){
            return fc(nn);
        }
    }
    return cn;
}

void make(int cn, int mult){
    //cout << "doing " << cn << " " << mult << "\n";
    int cur = 1;
    F0R(i, e[cn].size()){
        int nn = e[cn][i];
        if(sz[nn] > sz[cn]) continue;

        cout << cn << " " << nn << " " << cur*mult << "\n";
        make(nn, mult);
        cur += sz[nn];
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    F0R(_, n-1){
        int u, v;
        cin >> u >> v;
        e[u].pb(v);
        e[v].pb(u);
    }

    dfs(1);
    int cent = fc(1);

    /*FOR(i, 1, n) cout << sz[i] << " ";
    cout << "\n";
    cout << "cent is " << cent << "\n";*/

    memset(sz, 0, sizeof sz);
    dfs(cent);
    vpii ots;
    F0R(i, e[cent].size()){
        int nn = e[cent][i];
        ots.pb(mp(sz[nn], nn));
    }
    sort(ots.begin(), ots.end());
    int onMult = 1;
    int cur = 1;
    F0R(i, e[cent].size()){
        cout << cent << " " << ots[i].s << " " << cur*onMult << "\n";
        make(ots[i].s, onMult);
        cur += ots[i].f;
        if(cur >= (n+1)/3 && onMult == 1){
            onMult = cur;
            cur = 1;
        }
    }

    return 0;
}