#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <algorithm>
#define pii pair<int, int>
#define fi first
#define se second
#define ll long long int
#define ls ch[x][0]
#define rs ch[x][1]
#define lowbit(x) x & -x
#define maxr 100005
#define maxn 200015
#define maxm
#define X(x) 
#define Y(x)
#define TAN(x)
#define next NEXT
#define hash HASH
#define M 
#define pb push_back
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define esrep(i, x, NS) for (register int i = NS :: h[x]; i; i = NS :: e[i].next)
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
	char ch = gc(); bool f = 1; x = 0;
	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
	if (ch == '-') f = 0, ch = gc();
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	if (!f) x = -x;
}
int n, m, mx, ct;
int a[maxn];
deque<int> s;
int ans[maxn][2];
int ans2[maxn][2];

void init(){
	while(1){
		if (s.front() == mx) break;
		ct++;
		ans[ct][0] = s.front(); s.pop_front();
		ans[ct][1] = s.front(); s.pop_front();
		int x = max(ans[ct][0], ans[ct][1]), y = min(ans[ct][0], ans[ct][1]);
		s.push_front(x), s.push_back(y);
	}
	rep(i, 0, n - 2){
		ans2[i][0] = s.front(); s.pop_front();
		ans2[i][1] = s.front(); s.pop_front();
		int x = max(ans2[i][0], ans2[i][1]), y = min(ans2[i][0], ans2[i][1]);
		s.push_front(x), s.push_back(y);
	}
}
void solve(ll x){
	if (x <= ct) printf("%d %d\n", ans[x][0], ans[x][1]);
	else printf("%d %d\n", ans2[(x - ct - 1) % (n - 1)][0], ans2[(x - ct - 1) % (n - 1)][1]);
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("A.in", "r", stdin);
	#endif
	read(n), read(m);
	rep(i, 1, n) read(a[i]), mx = max(mx, a[i]), s.push_back(a[i]);
	init();
	ll x;
	rep(i, 1, m) read(x), solve(x); 
	return 0;
}