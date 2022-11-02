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
#define INF 1000000000000000LL
#define MOD 1000000007
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 205
ll sz; int sq;
pair<pll, pll> inp[MN];
vll xs, ys;

int n;
ll weights[MN][MN];
ll dist[MN];
queue<ll> q;
bool bfs(){
    memset(dist, 0, sizeof dist);
    dist[1] = 1;
    q.push(1);

    while(!q.empty()){
        ll top = q.front();
        q.pop();
        FOR(i, 1, n){
            if(dist[i] == 0 && weights[top][i] > 0){
                dist[i] = dist[top]+1;
                q.push(i);
            }
        }
    }

    return dist[n] > 0;
}

ll dfs(int node, ll curAmt){
    if(node == n) return curAmt;
    ll sm = 0;

    FOR(i, 1, n){
        if(dist[i] == dist[node]+1 && weights[node][i] > 0){
            ll toThis = dfs(i, min(curAmt-sm, weights[node][i]));
            
            sm += toThis;
            weights[node][i] -= toThis;
            weights[i][node] += toThis;
        }
    }

    if(sm == 0) dist[node] = 0;
    return sm;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> sz >> sq;
    F0R(i, sq){
        cin >> inp[i].f.f >> inp[i].f.s >> inp[i].s.f >> inp[i].s.s;
        xs.pb(inp[i].f.f);
        xs.pb(inp[i].s.f+1);
        ys.pb(inp[i].f.s);
        ys.pb(inp[i].s.s+1);
    }
    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());
    vll::iterator it1 = unique(xs.begin(), xs.end());
    vll::iterator it2 = unique(ys.begin(), ys.end());
    xs.resize(distance(xs.begin(), it1));
    ys.resize(distance(ys.begin(), it2));

    ll sz1 = xs.size()-1;
    ll sz2 = ys.size()-1;
    n = sz1+sz2+2;

    F0R(i, xs.size()-1){
        F0R(j, ys.size()-1){
            F0R(k, sq){
                if(inp[k].f.f <= xs[i] && inp[k].s.f >= xs[i+1]-1 && inp[k].f.s <= ys[j] && inp[k].s.s >= ys[j+1]-1){
                    //gr[i][j] = (xs[i+1]-xs[i])*(ys[j+1]-ys[j]);
                    //cout << i << " " << j << " " << k << " good\n";
                    weights[i+2][j+sz1+2] = INF;
                    break;
                }
            }
        }
    }
    F0R(i, xs.size()-1){
        weights[1][i+2] = xs[i+1]-xs[i];
    }
    F0R(j, ys.size()-1){
        weights[j+sz1+2][n] = ys[j+1]-ys[j];
    }

    /*FOR(i, 1, n){
        FOR(j, 1, n){
            cout << weights[i][j] << " ";
        }
        cout << "\n";
    }*/

    ll mf = 0;
    while(bfs()) mf += dfs(1, INF);

    cout << mf << "\n";
    
    return 0;
}