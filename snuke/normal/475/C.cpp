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
int x, y;
int si, sj;
string s[1005];
string t[1005];
bool fd;

void findsi() {
	rep(i,h)rep(j,w) {
		if (s[i][j] == 'X') {
			si = i; sj = j;
			fd = true;
			return;
		}
	}
}
bool isrec() {
	findsi();
	for (int i = si; i < h; ++i) {
		if (s[i][sj] == '.') break;
		x++;
	}
	for (int i = sj; i < w; ++i) {
		if (s[si][i] == '.') break;
		y++;
	}
	rep(i,h)rep(j,w) {
		if (i >= si && i < si+x && j >= sj && j < sj+y) {
			if (s[i][j] == '.') return false;
		} else {
			if (s[i][j] == 'X') return false;
		}
	}
	return true;
}

bool can(int a, int b) {
	rep(i,h) t[i] = s[i];
	int ni = si, nj = sj;
	rep(i,a)rep(j,b) {
		if (t[ni+i][nj+j] == '.') return false;
		t[ni+i][nj+j] = '.';
	}
	while (1) {
		//printf("%d %d\n",ni,nj);
		//rep(i,h)cout << t[i] << endl;
		if (ni+a < h) {
			if (t[ni+a][nj] == 'X') {
				rep(i,b) {
					if (t[ni+a][nj+i] == '.') return false;
					t[ni+a][nj+i] = '.';
				}
				ni++;
				continue;
			}
		}
		if (nj+b < w) {
			if (t[ni][nj+b] == 'X') {
				rep(i,a) {
					if (t[ni+i][nj+b] == '.') return false;
					t[ni+i][nj+b] = '.';
				}
				nj++;
				continue;
			}
		}
		break;
	}
	rep(i,h)rep(j,w) if (t[i][j] == 'X') return false;
	return true;
}

int tate() {
	if (sj+y >= w) return INF;
	int ti = -1;
	for (int i = si; i < si+x; ++i) {
		if (s[i][sj+y] == 'X') {
			ti = i;
			break;
		}
	}
	if (ti == -1) return INF;
	int a = (si+x)-ti, b = y;
	if (!can(a,b)) return INF;
	return a*b;
}
int yoko() {
	if (si+x >= h) return INF;
	int ti = -1;
	for (int i = sj; i < sj+y; ++i) {
		if (s[si+x][i] == 'X') {
			ti = i;
			break;
		}
	}
	if (ti == -1) return INF;
	int b = (sj+y)-ti, a = x;
	if (!can(a,b)) return INF;
	return a*b;
}

int main(){
	cin >> h >> w;
	rep(i,h) cin >> s[i];
	int ans = INF;
	if (isrec()) {
		ans = min(x,y);
	} else {
		if (!fd) ans = 0; else {
			ans = min(ans,tate());
			ans = min(ans,yoko());
		}
	}
	if (ans == INF) ans = -1;
	cout << ans << endl;
	return 0;
}