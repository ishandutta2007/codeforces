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

#define MN 200005
int n;
pii bruh[MN];
pair<pii, int> ree[MN];
priority_queue<pii> hmm;
int ori[MN];
int fw[MN];
int bk[MN];
set<int> nw;
int cst;

int vis[MN];

int dfs(int cn){
    //cout << "doing " << cn << "\n";
    if(vis[cn] == 2) return 0;
    if(vis[cn] == 1){
        cst = cn;
        return 1;
    }

    vis[cn] = 1;
    
    //auto nd = nw.upper_bound(bruh[cn].s);
    for(auto u = nw.lower_bound(bruh[cn].f); u != nw.end() && *u <= bruh[cn].s; ){
        //cout << "hmm\n";
        if(*u == fw[cn]){ ++u; continue; }
        //cout << "checking " << *u << " " << bk[*u] << "\n";
        int nn = bk[*u];
        int res = dfs(nn);
        //cout << "found " << nn << " from " << cn << "\n";

        if(res == -1) return -1;
        if(res == 1){
            fw[cn] = *u;
            if(cn == cst) return -1;
            else return 1;
        }
        //cout << "erasing " << *u << "\n";
        u = nw.erase(u);
    }

    //cout << "done with " << cn << "\n";
    //nw.erase(cn);
    vis[cn] = 2;
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    FOR(i, 1, n){
        cin >> ree[i].f.f >> ree[i].f.s;
        ree[i].s = i;
        bruh[i] = ree[i].f;
    }
    sort(ree+1, ree+1+n);
    int cur = 1;
    FOR(i, 1, n){
        while(cur <= n && ree[cur].f.f <= i){
            hmm.push({-ree[cur].f.s, ree[cur].s});
            ++cur;
        }
        pii top = hmm.top();
        hmm.pop();
        fw[top.s] = i;
    }
    //FOR(i, 1, n) cout << fw[i] << " ";
    //cout << "\n";

    memcpy(ori, fw, sizeof ori);

    FOR(i, 1, n) bk[fw[i]] = i;
    FOR(i, 1, n) nw.insert(i);
    bool sobbadobbasob = false;
    FOR(i, 1, n){
        //cout << "checking " << i << "\n";
        if(dfs(i) != 0){
            sobbadobbasob = true;
            break;
        }
    }
    if(!sobbadobbasob){
        cout << "YES\n";
        FOR(i, 1, n) cout << ori[i] << " ";
        cout << "\n";
    } else{
        cout << "NO\n";
        FOR(i, 1, n) cout << ori[i] << " ";
        cout << "\n";
        FOR(i, 1, n) cout << fw[i] << " ";
        cout << "\n";
    }
    
    return 0;
}