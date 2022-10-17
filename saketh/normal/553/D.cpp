#include <algorithm>
#include <assert.h>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string.h>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

typedef long long ll;

void setup(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(15);
}

const int MAXN = 100005;

int N, M, K;
bool fort[MAXN];

vector<int> adj[MAXN];
int good[MAXN];
int tot[MAXN];

int frac_comp(ll a, ll b, ll c, ll d){
    ll v1 = a  * d;
    ll v2 = b * c;
    if(v1 == v2) return 0;
    if(v1 < v2) return -1;
    return 1;
}

pair<int, int> small(pair<int, int> a, pair<int, int> b){
    return frac_comp(a.first, a.second, b.first, b.second) == -1 ? a : b;
}

struct city{
    int idx;
    bool operator<(const city &o) const{
        int res = frac_comp(good[idx], tot[idx], good[o.idx], tot[o.idx]);
        if(res == 0) return idx < o.idx;
        return res == -1;
    }
};

pair<int, int> make_frac(int a, int b){
    int g = a ? __gcd(a, b) : b;
    return {a/g, b/g};
}

set<city> subs;
pair<int, int> valu[MAXN];
int rem[MAXN];

int main(){
    setup();
    
    cin >> N >> M >> K;
    for(int i=0; i<K; i++){
        int f;
        cin >> f;
        fort[f-1] = true;
    }

    for(int i=0; i<M; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        if(!fort[v]) good[u]++;
        adj[v].push_back(u);
        if(!fort[u]) good[v]++;
    }

    pair<int, int> best = {1, 1};

    for(int i=0; i<N; i++){
        tot[i] = adj[i].size();
        if(!fort[i]) {
            best = small(best, make_frac(good[i], tot[i]));
            subs.insert({i});
        }
    }

    int NF = subs.size();
    valu[0] = best;

    int P = 0;
    while(subs.size()>1){
        auto it = subs.begin();
        int blocker = it->idx;
        subs.erase(it);
        for(int nbr : adj[blocker]){
            auto it2 = subs.lower_bound({nbr});
            if(it2 == subs.end() || it2->idx != nbr) continue;
            subs.erase(it2);
            good[nbr]--;
            subs.insert({nbr});
        }
        it = subs.begin();
        rem[P] = blocker;
        P++;
        valu[P] = make_frac(good[it->idx], tot[it->idx]);

        if(frac_comp(best.first, best.second, valu[P].first, valu[P].second) == -1){
            best = valu[P];
        }
    }
    
    vector<bool> use(N, true);

    int U = N;
    for(int i=0; i<N; i++)
        if(fort[i]) {
            use[i] = false;
            U--;
        }

    for(int i=0; i<NF; i++){
        if(valu[i] == best) break;
        use[rem[i]] = false;       
        U--;
    }

    cout << U << "\n";
    for(int i=0; i<N; i++)
        if(use[i]) cout << i+1 << " ";
    cout << endl;
}