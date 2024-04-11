#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
#define INF 1000000000
#define MOD 1000000007
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 200005
int sieve[MN];
int pr[MN];
int np;
void getSieve(){
    np = 0;
    FOR(i, 2, MN-1){
        if(sieve[i]) continue;
        np++;
        pr[np] = i;
        for(int j = i; j <= MN-1; j += i){
            sieve[j] = np;
        }
    }

    //cout << np << "\n";
}

int n;
int vals[MN];
vi edges[MN];

set<int> facs[MN];


bool vis[MN][2];
pii farthest(int cn, int g, int trial){
    vis[cn][trial] = true;
    
    int mx = 0;
    int mxn = cn;

    F0R(i, edges[cn].size()){
        int nn = edges[cn][i];

        if(vis[nn][trial]) continue;
        if(vals[nn] % g != 0) continue;
        
        pii resp = farthest(nn, g, trial);
        if(resp.f > mx){
            mx = resp.f;
            mxn = resp.s;
        }
    }

    return mp(mx+1, mxn);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    getSieve();

    cin >> n;
    FOR(i, 1, n){
        cin >> vals[i];

        int num = vals[i];
        while(num != 1){
            int ind = sieve[num];
            facs[ind].insert(i);

            int k = pr[ind];
            while(num % k == 0) num /= k;
        }
    }
    FOR(_, 1, n-1){
        int x, y;
        cin >> x >> y;
        edges[x].pb(y);
        edges[y].pb(x);
    }

    int ans = 0;

    FOR(i, 1, np){
        if(facs[i].empty()) continue;
        /*cout << pr[i] << " ";
        for(auto u : facs[i]){
            cout << u << " ";
        }
        cout << "\n";*/

        for(auto u : facs[i]){
            vis[u][0] = false;
            vis[u][1] = false;
        }

        for(auto u : facs[i]){
            if(vis[u][0]) continue;

            pii p1 = farthest(u, pr[i], 0);
            pii p2 = farthest(p1.s, pr[i], 1);

            ans = max(ans, p2.f);
        }
    }

    cout << ans << "\n";

    return 0;
}