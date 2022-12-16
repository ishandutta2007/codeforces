// Never let them see you bleed...
// Shayan.P  2020-06-18

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn = 60, mod = 1e9 + 7, inf = 1e9 + 10;

string s[maxn];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
bool mark[maxn][maxn];
int CNT, n, m;

void dfs(int x, int y){
    mark[x][y] = 1;
    CNT+= s[x][y] == 'G';
    for(int k = 0; k < 4; k++){
	int X = x + dx[k], Y = y + dy[k];
	if(X >= 0 && Y >= 0 && X < n && Y < m && !mark[X][Y] && s[X][Y] != '#')
	    dfs(X, Y);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int q;
    cin >> q;
    while(q--){
	int gd = 0;
	cin >> n >> m;
	bool bad = 0;
	for(int i = 0; i < n; i++){
	    cin >> s[i];
	}
	for(int i = 0; i < n; i++){
	    for(int j = 0; j < m; j++){
		gd+= s[i][j] == 'G';
		if(s[i][j] == 'B'){
		    for(int k = 0; k < 4; k++){
			int x = i + dx[k], y = j + dy[k];
			if(x >= 0 && y >= 0 && x < n && y < m && s[x][y] == 'G')
			    bad = 1;
			if(x >= 0 && y >= 0 && x < n && y < m && s[x][y] == '.')
			    s[x][y] = '#';
		    }
		}
	    }
	}
	memset(mark, 0, sizeof mark);
	CNT = 0;
	if(s[n-1][m-1] == '.')
	    dfs(n-1, m-1);
	if(CNT == gd && !bad)
	    cout << "Yes\n";
	else
	    cout << "No\n";
    }
    return 0;
}