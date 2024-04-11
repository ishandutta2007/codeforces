//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=(y);x<=(z);x++)
#define per(x,y,z) for(int x=(y);x>=(z);x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 1505;

int n, k, dep;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
int randint(mt19937& rnd, int L, int R) {
	uniform_int_distribution<int> dist(L, R);
	return dist(rnd);
}
bool ask(int u, int w, int v) {
	printf("? %d %d %d\n", u, w, v);
	fflush(stdout);
	char c[5];
	scanf("%s", c);
	return c[0] == 'Y';
}
void give(int rt) {
	printf("! %d\n", rt);
	fflush(stdout);
}
int dist(int x, int y) {
	int ans = 0;
	rep(i, 1, n) {
		if(x == i || y == i) continue;
		ans += ask(x, i, y);
	}
	return ans + 1;
}

int main() {
	mt19937 rnd(time(0));
	scanf("%d%d", &n, &k);
	dep = 1;
	for(int u=1,tmp=1;tmp<n;tmp+=(u*=k)) ++dep;
	int x, y;
	while(true) {
		do {
			x = randint(rnd, 1, n);
			y = randint(rnd, 1, n);
		}while(x == y);
		int qwq = dist(x, y);
		if(qwq == 2 * (dep - 1)) break;
	}
	rep(i, 1, n) {
		if(x != i && y != i && ask(x, i, y) && dist(x, i) == dep - 1) {
			give(i);
			break;
		}
	}
	return 0;
}