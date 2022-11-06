//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const int N = 505, K = 3005;

int n, m, k;
vector<tuple<char, int> > ans;
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}
bool run(char dir, int len) {
	chkmin(len, k);
	if(!len) return 0;
	ans.push_back(make_tuple(dir, len));
	k -= len;
	return 1;
}

int main() {
	scanf("%d%d%d", &n, &m, &k);
	int lim = 4 * n * m - 2 * n - 2 * m;
	if(k > lim) return puts("NO")&0;
	puts("YES");
	run('D', n-1);
	per(i, n, 2) {
		run('R', m-1);
		run('L', m-1);
		run('U', 1);
	}
	run('R', m-1);
	per(i, m, 1) {
		run('D', n-1);
		run('U', n-1);
		run('L', 1);
	}
	int sz = ans.size();
	printf("%d\n", sz);
	for(auto i : ans) printf("%d %c\n", get<1>(i), get<0>(i));
	return 0;
}