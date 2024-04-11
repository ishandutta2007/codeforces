#include <bits/stdc++.h>
using namespace std;
#define File(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define mkp make_pair
#define pb push_back
#define SP putchar(' ')
#define EL putchar('\n')

mt19937 rnd(chrono :: steady_clock :: now().time_since_epoch().count());
mt19937_64 rnd64(chrono :: steady_clock :: now().time_since_epoch().count()) ;

template<class T> inline void gi(T &x){
	char ch; x = 0;int f = 1;
	while(isspace(ch = getchar()));
	if(ch == '-') ch = getchar(), f = -1;
	do x = x * 10 + ch - '0'; while(isdigit(ch = getchar()));
	x *= f;
}
template<class T> inline void wi(T x){
	static char stk[128]; int top = 0;
	if(x == 0) putchar('0');
	if(x < 0) putchar('-'), x = -x;
	while(x) stk[++top] = x % 10, x /= 10;
	while(top) putchar(stk[top--] + '0');
}
template<class T> void upmax(T &x, T y){x = x>y ? x : y;}
template<class T> void upmin(T &x, T y){x = x<y ? x : y;}
const int N = 1005;
char a[N][N];
bool l[N], c[N];
int cl[N][N], cc = 0;
int n, m;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

bool border(int x, int y){return x >= 1 && x <= n && y >= 1 && y <= m && a[x][y] == '#';}

void dfs(int x, int y){
	cl[x][y] = cc;
	for(int d=0; d<4; d++){
		if(border(x + dx[d], y + dy[d]) && !cl[x+dx[d]][y+dy[d]])
			dfs(x + dx[d], y + dy[d]);
	}
}

int main(){
	// File("b");
	gi(n); gi(m);
	for(int i=1; i<=n; i++)
		scanf("%s", a[i] + 1);
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			if(a[i][j] == '#')
				l[i] = c[j] = true;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++){
			if(!cl[i][j] && a[i][j] == '#') ++cc, dfs(i, j);
		}
	for(int i=1; i<=n; i++){
		bool ok = false;
		int vc = 0;
		for(int j=1; j<=m; j++){
			if(!cl[i][j-1] && cl[i][j]) ++vc;
			if(vc > 1){
				puts("-1");
				return 0;
			}
			if(!c[j]) ok = true;
		}
		if(!(ok || l[i])){
			puts("-1");
			return 0;
		}
	}
	for(int i=1; i<=m; i++){
		bool ok = false;
		int vc = 0;
		for(int j=1; j<=n; j++){
			if(!cl[j-1][i] && cl[j][i]) ++vc;
			if(vc > 1){
				puts("-1");
				return 0;
			}
			if(!l[j]) ok = true;
		}
		if(!(ok || c[i])){
			puts("-1");
			return 0;
		}
	}
	wi(cc), EL;
	return 0;
}