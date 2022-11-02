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

#define MN 100005
int n;
ll a[MN];
vi cnt[64];
vi e[MN];

int dist[MN];

int bfs(int x, int y){
    queue<int> aah;
    memset(dist, -1, sizeof dist);

    aah.push(x);
    dist[x] = 0;
    while(!aah.empty()){
        int top = aah.front();
        aah.pop();
        if(top == y) return dist[y]+1;
        for(auto u : e[top]){
            if(x == top && y == u) continue;
            if(dist[u] != -1 && dist[u] <= dist[top]+1) continue;
            dist[u] = dist[top]+1;
            aah.push(u);
        }
    }
    return INF;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    F0R(i, n){
        cin >> a[i];
        F0R(j, 63){
            if(a[i] & 1LL<<j){
                cnt[j].pb(i);
            }
        }
    }

    F0R(i, 63){
        if(cnt[i].size() > 2){
            cout << "3\n";
            return 0;
        }
        if(cnt[i].size() == 2){
            e[cnt[i][0]].pb(cnt[i][1]);
            e[cnt[i][1]].pb(cnt[i][0]);
        }
    }
    int ans = INF;
    F0R(i, 63){
        if(cnt[i].size() == 2){
            ans = min(ans, bfs(cnt[i][0], cnt[i][1]));
        }
    }

    if(ans == INF) cout << "-1\n";
    else cout << ans << "\n";

    return 0;
}