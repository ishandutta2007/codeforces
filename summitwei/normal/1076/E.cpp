#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
#define INF 1000000000
#define MOD 1000000007
#define EPSILON 0.00001
#define MAX_N 300005
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

int n, m;
vi edges[MAX_N];
int par[MAX_N];
vpii upds[MAX_N];
ll amtAdded[MAX_N];
int depth[MAX_N];
int maxD;
void dfsForDepth(int currNode){
    F0R(i, edges[currNode].size()){
        int newNode = edges[currNode][i];
        if(newNode == par[currNode]) continue;

        par[newNode] = currNode;
        depth[newNode] = depth[currNode]+1;
        maxD = max(maxD, depth[newNode]);
        dfsForDepth(newNode);
    }
}

ll currSum;
ll curr[MAX_N];
ll answers[MAX_N];
void dfsForAns(int currNode){
    F0R(i, upds[currNode].size()){
        curr[upds[currNode][i].s] += upds[currNode][i].f;
        currSum += upds[currNode][i].f;
    }
    if(currNode != 1){
        currSum -= curr[depth[currNode]-1];
    }
    
    answers[currNode] = currSum;

    F0R(i, edges[currNode].size()){
        int newNode = edges[currNode][i];
        if(newNode == par[currNode]) continue;

        dfsForAns(newNode);
    }

    F0R(i, upds[currNode].size()){
        curr[upds[currNode][i].s] -= upds[currNode][i].f;
        currSum -= upds[currNode][i].f;
    }
    if(currNode != 1){
        currSum += curr[depth[currNode]-1];
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    F0R(i, n-1){
        int x, y;
        cin >> x >> y;
        edges[x].pb(y);
        edges[y].pb(x);
    }

    dfsForDepth(1);

    cin >> m;
    F0R(i, m){
        int v, d, x;
        cin >> v >> d >> x;
        upds[v].pb(mp(x, min(maxD+1, d+depth[v])));
    }

    dfsForAns(1);

    FOR(i, 1, n){
        cout << answers[i] << " ";
    }
    
    return 0;
}