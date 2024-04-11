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
#define MAX_N 100005
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

int par[MAX_N];
vi ch[MAX_N];
int n;

int numLeaves[MAX_N];

void dfs(int node){
    int cnt = 0;

    for(auto newNode : ch[node]){
        dfs(newNode);
        cnt += numLeaves[newNode];
    }

    if(cnt == 0) cnt = 1;

    numLeaves[node] = cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    FOR(i, 2, n){
        cin >> par[i];
        ch[par[i]].pb(i);
    }

    dfs(1);
    
    sort(numLeaves+1, numLeaves+1+n);

    FOR(i, 1, n){
        cout << numLeaves[i] << " ";
    }
    
    return 0;
}