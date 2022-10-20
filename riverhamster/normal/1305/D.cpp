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
vector<int> G[N];
bool vis[N];
int deg[N];

int LCA(int x, int y){
	printf("? %d %d\n", x, y);
	fflush(stdout);
	int res;
	scanf("%d", &res);
	if(res == -1) exit(0);
	return res;
}

void dfs(int x){
	vis[x] = true;
	for(int v : G[x]){
		--deg[v];
		if(vis[v]) continue;
		dfs(v);
	}
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i=1; i<n; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		G[x].pb(y); G[y].pb(x);
		++deg[x]; ++deg[y];
	}
	static int pt[N], p1[N], p0, cnt = 0, c1 = 0;
	while(1){
		cnt = 0; c1 = 0; p0 = 0;
		for(int j=1; j<=n; j++){
			if(!vis[j] && deg[j] > 1) pt[++cnt] = j;
			if(!vis[j] && deg[j] == 1) p1[++c1] = j;
			if(!vis[j] && deg[j] == 0) p0 = j;
			if(cnt == 2 || p0 != 0) break;
		}
		// printf("cnt = %d c1 = %d\n", cnt, c1);
		if(cnt == 2){
			int x = pt[1], y = pt[2];
			int l = LCA(x, y);
			if(l == x){
				vis[x] = true;
				dfs(y);
				vis[x] = false;
			}
			else if(l == y){
				vis[y] = true;
				dfs(x);
				vis[y] = false;
			}
			else{
				vis[l] = true;
				dfs(x); dfs(y);
				vis[l] = false;
			}
		}
		else{
			if(p0 != 0) printf("! %d\n", p0);
			else{
				for(int i=1; i<c1; i+=2){
					int l = LCA(p1[i], p1[i+1]);
					if(l == p1[i]){
						printf("! %d\n", p1[i]);
						fflush(stdout);
						return 0;
					}
					else if(l == p1[i+1]){
						printf("! %d\n", p1[i+1]);
						fflush(stdout);
						return 0;
					}
				}
				if(c1 & 1)
					printf("! %d\n", LCA(p1[c1], pt[1]));
				else printf("! %d\n", pt[1]);
			}
			fflush(stdout);
			return 0;
		}
	}
	return 0;
}