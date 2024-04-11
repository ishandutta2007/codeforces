#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<sstream>
#include<cstring>
#define mp make_pair
#define pb push_back      
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define pw(x) (1ll<<(x))
#define buli(x) __builtin_popcountll(x)
#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)
#define M 1000000007
#define N 211111
#define right afadf

#define TASK "1"

using namespace std;
typedef pair<int,int> pt;

int n, m;
string s[555];

int e[555][555], up[555][555], right[555][555];

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> s[i];

	for (int i = 0; i < n - 1; i++) for (int j = 0; j < m - 1; j++) {
		e[i + 1][j + 1] = e[i][j + 1] + e[i + 1][j] - e[i][j];

		if (s[i][j] == '.' && s[i + 1][j] == '.') e[i + 1][j + 1]++;
		if (s[i][j] == '.' && s[i][j + 1] == '.') e[i + 1][j + 1]++;
	}

	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
		up[i + 1][j] = up[i][j];
		if (s[i][j] == '.' && i + 1 < n && s[i + 1][j] == '.') up[i + 1][j]++;

		right[i][j + 1] = right[i][j];

		if (s[i][j] == '.' && j + 1 < m &&  s[i][j + 1] == '.') right[i][j + 1]++;
	}

	int q;
	cin >> q;
	while (q--) {
		int x, y, xx, yy;
		cin >> x >> y >> xx >> yy;
		x--;
		y--;
		xx--;
		yy--;

		int ans = 0;
		if (xx > x || yy > y) {
			ans += e[xx][yy] - e[x][yy] - e[xx][y] + e[x][y];
		}
		if (xx > x) {
			ans += up[xx][yy] - up[x][yy];
		}
		if (yy > y) {
			ans += right[xx][yy] - right[xx][y];
		}
		cout << ans << endl;
	}



	return 0;
}