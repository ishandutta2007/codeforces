// I think of what the world could be, A vision of the one I see, A million dreams is all it's gonna take

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn = 210, mod = 1e9 + 7;
const ll inf = 1e15 + 10;

int a[maxn], x[maxn], y[maxn];
int g[maxn][maxn];
ll dp[maxn][maxn];
bool mark[maxn][maxn];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
    
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n, d;
    cin >> n >> d;
    for(int i = 1; i < n-1; i++){
	cin >> a[i];
    }
    for(int i = 0; i < n; i++){
	cin >> x[i] >> y[i];
	x[i]+= 101, y[i]+= 101;
    }
    for(int i = 0; i < n; i++){
	g[x[i]][y[i]]+= a[i];
    }
    for(int i = 0; i < maxn; i++){
	for(int j = 0; j < maxn; j++)
	    dp[i][j] = inf;
    }
    priority_queue<pair<ll, pii>, vector<pair<ll, pii> >, greater< pair<ll, pii> > > pq;
    pq.push({0, {x[0], y[0]}});
    dp[x[0]][y[0]] = 0;
    
    while(sz(pq)){
	pii p = pq.top().S;
	pq.pop();
	if(mark[p.F][p.S])
	    continue;
	mark[p.F][p.S] = 1;
	for(int i = 0; i < 4; i++){
	    int x = p.F + dx[i], y = p.S + dy[i];
	    if(x < 0 || y < 0 || x >= maxn || y >= maxn)
		continue;
	    if(dp[x][y] > dp[p.F][p.S] + d - g[x][y])
		dp[x][y] = dp[p.F][p.S] + d - g[x][y], pq.push({dp[x][y], {x, y}});
	}
    }
    return cout << dp[x[n-1]][y[n-1]] << endl, 0;
}