#include<cstdio>
#include<algorithm>
#include<stack>
#include<queue>
#include<deque>
#include<vector>
#include<string>
#include<string.h>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<map>
#include<set>
#include<iostream>
#include<sstream>
#include<cctype>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < n; ++i)
#define rrep(i,n) for(int i = 1; i <= n; ++i)
#define drep(i,n) for(int i = n-1; i >= 0; --i)
#define gep(i,g,j) for(int i = g.head[j]; i != -1; i = g.e[i].next)
#define each(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define rng(a) a.begin(),a.end()
#define maxs(x,y) x = max(x,y)
#define mins(x,y) x = min(x,y)
#define pb push_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcount
#define snuke srand((unsigned)clock()+(unsigned)time(NULL))
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;

const int MX = 100005, INF = 1000010000;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;
const int dx[] = {-1,0,1,0}, dy[] = {0,-1,0,1}; //<^>v

int h, w;
string a, b;

bool used[25][25];

int bfs(int i, int j) {
	if (i<0||j<0||i>=h||j>=w) return 0;
	if (used[i][j]) return 0;
	used[i][j] = true;
	int res = 1;
	if (a[i] == '<') res += bfs(i,j-1);
	if (a[i] == '>') res += bfs(i,j+1);
	if (b[j] == '^') res += bfs(i-1,j);
	if (b[j] == 'v') res += bfs(i+1,j);
	return res;
}
int dfs(int si, int sj) {
	rep(i,h)rep(j,w) used[i][j] = false;
	return bfs(si,sj);
}

int main(){
	cin >> h >> w >> a >> b;
	rep(i,h)rep(j,w) {
		if (dfs(i,j) != h*w) {
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}