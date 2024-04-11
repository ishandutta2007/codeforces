#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

typedef vector<int> vi;
#define pb push_back
#define sz(x) int((x).size())

const int inf = 1 << 30;
const int MAXN = 3100;

vi par[MAXN];
vi child[MAXN];

int backw;
int maxsave;
int minsave;
int cursave;

void go(int x, int from) {
	int prmin = minsave;
	minsave = min(minsave, cursave);
	maxsave = max(maxsave, cursave - minsave);
	vi &p = par[x];
	for(int i = 0; i < sz(p); ++i) {
		if (p[i] == from) {
			continue;
		}
		cursave++;
		backw++;
		go(p[i], x);
		cursave--;
	}
	vi &c = child[x];
	for(int i = 0; i < sz(c); ++i) {
		if (c[i] == from) {
			continue;
		}
		cursave--;
		go(c[i], x);
		cursave++;
	}
	minsave = prmin;
}
int N;
int main() {	
	scanf("%d", &N);
	for(int i = 1; i < N; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		a--;	
		b--;
		par[b].pb(a);
		child[a].pb(b);
	}
	int ans = inf;
	for(int i = 0; i < N; ++i) {
		backw = maxsave = cursave = minsave = 0;
		go(i, -1);
		ans = min(ans, backw - maxsave);
	}
	printf("%d\n", ans);
	return 0;
}