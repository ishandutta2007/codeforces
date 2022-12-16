// hello darkness my old friend, I've come to talk with you again

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef unsigned long long ll;
typedef pair<int,int> pii;

const int maxn = 210, MAX = 55, mod = 1e9 + 7, inf = 1e9 + 10;

struct Aho{
    int nxt[MAX][2], f[MAX], C = 0;
    bool bad[MAX];
    Aho(){
	memset(nxt, 0, sizeof nxt);
	memset(f, 0, sizeof f);
	memset(bad, 0, sizeof bad);
	C = 0;
    }
    void in(){
	int k;
	cin >> k;
	int nw = 0;
	while(k--){
	    int x;
	    cin >> x;
	    if(nxt[nw][x] == 0)
		nxt[nw][x] = ++C;
	    nw = nxt[nw][x];
	}
	bad[nw] = 1;	
    }
    void build(){
	queue<int> q;
	for(int i = 0; i < 2; i++)
	    if(nxt[0][i] != 0)
		q.push(nxt[0][i]);
	while(sz(q)){
	    int u = q.front();
	    q.pop();
	    bad[u]|= bad[ f[u] ];
	    for(int i = 0; i < 2; i++){
		if(nxt[u][i] == 0)
		    nxt[u][i] = nxt[ f[u] ][i];
		else
		    f[ nxt[u][i] ] = nxt[ f[u] ][i], q.push(nxt[u][i]);
	    }		
	}
    }
};Aho aho;

vector<int> change[maxn], used[maxn];
int who[maxn], who2[maxn], start[maxn];

vector<int> bst1[maxn][MAX], bst2[maxn][MAX];

ll dp[maxn][MAX][MAX];
bool seen[maxn][MAX][MAX];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int G, N, M;
    cin >> G >> N >> M;

    int counter = G;
    
    for(int i = 0; i < N; i++){
	int a, k;
	cin >> a >> k;
	change[i].resize(k);
	start[i] = counter;
	for(int j = 0; j < k; j++){
	    cin >> change[i][j];
	    who[counter] = i;
	    used[ change[i][j] ].PB(counter);
	    counter++;
	}
	who2[i] = a;
    }
    for(int i = 0; i < M; i++){
	aho.in();
    }
    aho.build();

    int AH = aho.C + 1;

    priority_queue< pair<ll, pair<int, pii> >, vector< pair<ll, pair<int, pii> > >, greater< pair<ll, pair<int, pii> > > > pq;
    for(int i = 0; i < AH; i++){
	if(aho.bad[i] == 0 && aho.bad[ aho.nxt[i][0] ] == 0)
	    dp[0][i][ aho.nxt[i][0] ] = 1, pq.push({1, {0, {i, aho.nxt[i][0]} }});
	if(aho.bad[i] == 0 && aho.bad[ aho.nxt[i][1] ] == 0)
	    dp[1][i][ aho.nxt[i][1] ] = 1, pq.push({1, {1, {i, aho.nxt[i][1]} }});	
    }
    auto better = [&](int a, int b, int c, ll x){
		      if(dp[a][b][c] == 0 || dp[a][b][c] > x)
			  dp[a][b][c] = x, pq.push({x, {a, {b, c}}});
		  };
    while(sz(pq)){
	int id = pq.top().S.F, l1 = pq.top().S.S.F, l2 = pq.top().S.S.S;
	pq.pop();
	if(seen[id][l1][l2])
	    continue;
	seen[id][l1][l2] = 1;
	
	bst1[id][l1].PB(l2);
	bst2[id][l2].PB(l1);
	
	if(id < G){
	    for(int ID : used[id]){
		if(ID == start[ who[ID] ]){
		    better(ID, l1, l2, dp[id][l1][l2]);
		}
		else{
		    for(int i : bst2[ID-1][l1])
			better(ID, i, l2, dp[ID-1][i][l1] + dp[id][l1][l2]);
		}
	    }
	}
	else if(id - start[ who[id] ] + 1 == sz(change[ who[id] ])){
	    better(who2[ who[id ] ], l1, l2, dp[id][l1][l2]);
	}
	else{
	    int index = id - start[ who[id] ];
	    int c = change[ who[id] ][index + 1];
	    for(int i : bst1[c][l2])
		better(id+1, l1, i, dp[id][l1][l2] + dp[c][l2][i]);
	}
    }

    for(int i = 2; i < G; i++){
	ll bst = 0;
	for(int j : bst1[i][0]){
	    if(bst == 0 || bst > dp[i][0][j])
		bst = dp[i][0][j];
	}
	if(bst == 0)
	    cout << "YES\n";
	else
	cout << "NO " << bst << "\n";	
    }
    return 0;
}