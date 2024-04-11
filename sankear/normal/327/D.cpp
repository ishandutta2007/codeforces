#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <deque>
#include <stack>
#include <complex>
#include <cassert>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(s) int((s).size())
#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define LLD "%lld"
#else
#define eprintf(...) 42
#define LLD "%I64d"
#endif
#define next _next
#define prev _prev
#define rank _rank
#define link _link
#define hash _hash

typedef long long ll;
typedef long long llong;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef complex <double> tc;

const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));
const int N = 500;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

struct tans{
	char ch;
	int x, y;
	
	tans(){}
	
	tans(char _ch, int _x, int _y){
		ch = _ch;
		x = _x;
		y = _y;
	}
	
};

int n, m;
char a[N + 10][N + 10];
vector <tans> ans;

inline bool good(int x, int y){
	return x >= 0 && x < n && y >= 0 && y < m;
}

void dfs(int x, int y){
	a[x][y] = 'B';
	ans.pb(tans('B', x, y));
	for(int i = 0; i < 4; i++){
		int nx = x + dx[i], ny = y + dy[i];
		if(good(nx, ny) && a[nx][ny] == '.'){
			dfs(nx, ny);
		}
	}
	for(int i = 0; i < 4; i++){
		int nx = x + dx[i], ny = y + dy[i];
		if(good(nx, ny) && a[nx][ny] == 'B'){
			ans.pb(tans('D', x, y));
			a[x][y] = 'R';
			ans.pb(tans('R', x, y));
			break;
		}
	}
}

int main(){
	//gen();
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d %d", &n, &m);
	gets(a[0]);
	for(int i = 0; i < n; i++){
		gets(a[i]);
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(a[i][j] == '.'){
				dfs(i, j);
			}
		}
	}
	printf("%d\n", sz(ans));
	for(int i = 0; i < sz(ans); i++){
		printf("%c %d %d\n", ans[i].ch, ans[i].x + 1, ans[i].y + 1);
	}
	return 0;
}