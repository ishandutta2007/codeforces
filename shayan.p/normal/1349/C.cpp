// Never let them see you bleed...
// Shayan.P  2020-05-12

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn = 1010, mod = 1e9 + 7, inf = 1e9 + 10;

string s[maxn];
int h[maxn][maxn], col[maxn][maxn];

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int n, m;

bool isol(int x, int y){
    for(int i = 0; i < 4; i++){
	int X = x + dx[i], Y = y + dy[i];
	if(X >= 0 && Y >= 0 && X < n && Y < m && s[x][y] == s[X][Y])
	    return 0;
    }
    return 1;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int q;
    cin >> n >> m >> q;
    for(int i = 0; i < n; i++){
	cin >> s[i];
    }
    memset(h, -1, sizeof h);
    queue<pii> qu;
    for(int i = 0; i < n; i++){
	for(int j = 0; j < m; j++){
	    if(!isol(i, j))
		h[i][j] = 0, qu.push({i, j}), col[i][j] = s[i][j] == '1';
	}
    }
    while(sz(qu)){
	int x = qu.front().F, y = qu.front().S;
	qu.pop();
	for(int i = 0; i < 4; i++){
	    int X = x + dx[i], Y = y + dy[i];
	    if(X >= 0 && Y >= 0 && X < n && Y < m && h[X][Y] == -1)
		h[X][Y] = h[x][y]+1, col[X][Y] = col[x][y], qu.push({X, Y});
	}	
    }    
    while(q--){
	int x, y;
	ll p;
	cin >> x >> y >> p;
	--x, --y;
	if(h[x][y] == -1 || h[x][y] > p){
	    cout << s[x][y] << "\n";
	}
	else{
	    cout << (col[x][y] ^ (p&1)) << "\n";
	}
    }
    return 0;
}