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

const int maxn = 1010, maxc = 44, mod = 1e9 + 7, inf = 1e9 + 10;

int a[maxn][maxn];
vector<pii> col[maxc];

bool mark[maxn][maxn], markc[maxc];
int dis[maxc][maxn][maxn];

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};
	     
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++){
	for(int j = 0; j < m; j++){
	    cin >> a[i][j];
	    col[ a[i][j] ].PB({i, j});
	}
    }
    for(int c = 1; c <= k; c++){
	memset(mark, 0, sizeof mark);
	memset(markc, 0, sizeof markc);
	queue<pii> q;
	for(pii x: col[c])
	    q.push(x), mark[x.F][x.S] = 1, dis[c][x.F][x.S] = 0;
	markc[c] = 1;
	
	while(sz(q)){
	    pii p = q.front();
	    q.pop();
	    int x = p.F, y = p.S;
	    for(int i = 0; i < 4; i++){
		int X = x + dx[i], Y = y + dy[i];
		if(X >= 0 && Y >= 0 && X < n && Y < m && !mark[X][Y])
		    mark[X][Y] = 1, dis[c][X][Y] = dis[c][x][y]+1, q.push({X, Y});
	    }
	    if(markc[ a[x][y] ] == 0){
		markc[ a[x][y] ] = 1;
		for(pii p : col[ a[x][y] ]){
		    if(!mark[p.F][p.S])
			mark[p.F][p.S] = 1, dis[c][p.F][p.S] = dis[c][x][y] + 1, q.push(p);
		}
	    }
	}
    }
    int q;
    cin >> q;
    while(q--){
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	--a, --b, --c, --d;
	int ans = abs(a-c) + abs(b-d);
	for(int i = 1; i <= k; i++)
	    ans = min(ans, dis[i][a][b] + dis[i][c][d] + 1);
	cout << ans << "\n";
    }
    return 0;
}