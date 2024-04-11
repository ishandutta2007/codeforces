#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
#define INF 1000000000
#define MOD 998244353
#define EPSILON 0.00001
#define MAX_N 200005

#define FOR(i, a, b) for (int i=(a); i<=(b); i++)
#define F0R(i, a) for (ll i=0; i<(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

int N;
ll x, y;
vi adj[MAX_N];
int par[MAX_N];
pair<int, bool> dp[MAX_N]; //true = less than two children are true

void dfs(int node){
    int numTrue = 0;
    int totalSum = 0;
    F0R(i, adj[node].size()){
        int newN = adj[node][i];
        if(par[node] == newN) continue;
        par[newN] = node;
        dfs(newN);

        totalSum += dp[newN].first;
        if(dp[newN].second) numTrue++;
    }

    if(numTrue < 2){
        dp[node].second = true;
        dp[node].first = totalSum + numTrue;
    } else{
        dp[node].second = false;
        dp[node].first = totalSum + 2;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> x >> y;
    F0R(i, N-1){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if(x > y){
        int maxNum = adj[1].size();
        FOR(i, 2, N){
            maxNum = max(maxNum, (int)adj[i].size());
        }

        if(maxNum == N-1){
            cout << (N-2)*y+x << "\n";
        } else{
            cout << (N-1)*y << "\n";
        }
        return 0;
    }

    dfs(1);
    ll rootAns = (ll)dp[1].first;
    //cout << rootAns << "\n";

    cout << rootAns*x+(N-1-rootAns)*y << "\n";

    /*FOR(i, 1, N){
        cout << i << " " << dp[i].first << "\n";
    }*/
    return 0;
}