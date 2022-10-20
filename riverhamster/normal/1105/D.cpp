#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <queue>
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int N = 1005;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
char s[N][N];
int sp[15], ans[15];
int n, m, p;
queue<pair<int, int> > q[10];
int dis[N][N];
pair<int, int> tmp[N*N];
template<typename T> inline void in(T &x){ //Read Positive Integer.
	register char ch; x = 0;
	// register int f = 1;
	while(isspace(ch = getchar()));
	// if(ch == '-') ch = getchar(), f = -1;
	do x = x * 10 + ch - '0'; while(isdigit(ch = getchar()));
	// x *= f;
}
inline bool check(int x, int y){
	// printf("check (%d, %d): %s\n",x , y, x>0 && x<=n && y>0 && y<=m && s[x][y] == '.'?"success":"failed");
	return x>0 && x<=n && y>0 && y<=m && s[x][y] == '.';
}

void work(){
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			if(s[i][j] != '.' && s[i][j] != '#') q[s[i][j]-'0'].push(make_pair(i, j));
	pair<int, int> x;
	bool flag = true;
	while(flag){
		flag = false;
		for(int i=1; i<=p; i++){
			int len = 0;
			while(!q[i].empty()){
				x = q[i].front(); q[i].pop();
				dis[x.fi][x.se] = sp[i];
				tmp[++len] = x;
			}
			for(int t=1; t<=len; t++) q[i].push(tmp[t]);
			len = 0;
			while(!q[i].empty()){
				x = q[i].front(); q[i].pop();
				if(dis[x.fi][x.se] == 0){
					tmp[++len] = x;
					continue;
				}
				for(int d=0; d<4; d++){
					if(check(x.fi + dx[d], x.se + dy[d])){
						dis[x.fi+dx[d]][x.se+dy[d]] = dis[x.fi][x.se] - 1;
						s[x.fi+dx[d]][x.se+dy[d]] = '0' + i;
						q[i].push(make_pair(x.fi+dx[d], x.se+dy[d])); flag = true;
					}
				}
			}
			for(int t=1; t<=len; t++) q[i].push(tmp[t]);
			len = 0;
		}
	}
}

int main(){
	// freopen("d.in", "r", stdin);
	// freopen("d.out", "w", stdout);
	in(n); in(m); in(p);
	for(int i=1; i<=p; i++)
		in(sp[i]);
	for(int i=1; i<=n; i++)
		scanf("%s", s[i] + 1);
	work();
	// for(int i=1; i<=n; i++) printf("%s\n", s[i]+1);
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			if(s[i][j] != '#' && s[i][j] != '.') ans[s[i][j]-'0']++;
	for(int i=1; i<=p; i++)
		printf("%d ", ans[i]);
	return 0;
}