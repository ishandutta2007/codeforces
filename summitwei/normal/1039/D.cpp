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
#define fi first
#define se second

#define FOR(i, a, b) for (int i=(a); i<=(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

int dfsOrder[MAX_N];
int curOrder;
int par[MAX_N];

pii topEdges[MAX_N];
vi edges[MAX_N];
int n;

int answers[MAX_N];
//int smallestKnown[MAX_N]; //stores the smallest known k for a given answer

int parDFS(int node){
    F0R(i, edges[node].size()){
        int newNode = edges[node][i];
        if(par[node] == newNode) continue;

        par[newNode] = node;

        parDFS(newNode);
    }

    dfsOrder[curOrder] = node;
    curOrder++;
}

/*int k;
int cnt;
int dp[MAX_N];
void dfs(int node){
    int max = 0;
    int secondMax = 0;

    F0R(i, edges[node].size()){
        int newNode = edges[node][i];
        if(par[node] == newNode) continue;

        dfs(newNode);

        int res = dp[newNode];

        if(res > max){
            secondMax = max;
            max = res;
        } else if(res > secondMax){
            secondMax = res;
        }
    }

    if(max + secondMax + 1 >= k){
        cnt++;
        dp[node] = 0;
    } else{
        dp[node] = max+1;
    }
}*/

void updateParNode(int node, int val){
    if(val > topEdges[node].fi){
        topEdges[node].se = topEdges[node].fi;
        topEdges[node].fi = val;
    } else if(val > topEdges[node].se){
        topEdges[node].se = val;
    }
}
int procK(int k){
    if(answers[k] != -1) return answers[k];

    int cnt = 0;
    //memset(topEdges, {0, 0}, sizeof topEdges);
    FOR(i, 1, n){
        topEdges[i] = {0, 0};
    }

    F0R(i, n){
        int node = dfsOrder[i];

        if(topEdges[node].fi + topEdges[node].se + 1 >= k){
            cnt++;
        } else{
            updateParNode(par[node], topEdges[node].fi+1);
        }
    }

    answers[k] = cnt;
    return cnt;
}


/*int maxSize(int currK){
    if(answers[currK] != -1){
        return answers[currK];
    }

    k = currK;
    cnt = 0;
    memset(dp, 0, sizeof dp);

    dfs(1);

    answers[currK] = cnt;
    //smallestKnown[cnt] = min(smallestKnown[cnt], k);
    return cnt;
}*/

int upBound(int val, int lb){
    //first try the next one because sometimes it's just that
    //if(maxSize(lb+1) != val) return lb;

    int l = lb-1;
    int r = n+1;// = min(n+1, smallestKnown[cnt-1];
    /*if(smallestKnown[val-1] != -1){
        r = smallestKnown[val-1];
    }*/


    while(l+1 < r){
        int mid = (l+r)/2;

        if(procK(mid) == val){
            l = mid;
        } else{
            r = mid;
        }
    }

    return l;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //memset(smallestKnown, -1, sizeof smallestKnown);
    memset(answers, -1, sizeof answers);
    curOrder = 0;

    cin >> n;
    F0R(i, n-1){
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    parDFS(1);

    int rt = sqrt(n*log2(n));
    FOR(i, 1, rt){
        int size = procK(i);
        answers[i] = size;
    }

    int maxVal = answers[rt];
    int currLeft = rt;
    RFOR(i, maxVal, 1){
        int ub = upBound(i, currLeft);
        FOR(j, currLeft, ub){
            answers[j] = i;
        }

        currLeft = ub+1;
    }

    FOR(i, 1, n){
        if(answers[i] == -1){
            cout << "0\n";
        } else{
            cout << answers[i] << "\n";
        }
    }

    
    return 0;
}