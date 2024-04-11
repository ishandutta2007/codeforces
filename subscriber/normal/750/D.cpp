#include<bits/stdc++.h>
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

#define TASK "1"

using namespace std;

char was[411][411][4][31];

int col[411][411];


int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int n;
int t[33];
int ans = 0;

void go(int x, int y, int d, int w) {
	if (w == n) return;

	if (was[x][y][d][w]) return;
	was[x][y][d][w] = 1;

	for (int i = 0; i < t[w]; i++) {
		if (!col[x][y]) ans++;
		col[x][y] = 1;
		if (i + 1 == t[w]) break;
		x += dx[d];
		y += dy[d];
	}
	go(x + dx[(d + 7) % 8], y + dy[(d + 7) % 8], (d + 7) % 8, w + 1);
	go(x + dx[(d + 1) % 8], y + dy[(d + 1) % 8], (d + 1) % 8, w + 1);
}

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> t[i];

	go(200, 200, 0, 0);

	cout << ans << endl;
	
	return 0;
}