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
#define maxn 100015
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
int n, a[maxn];
int main(){
	#ifndef ONLINE_JUDGE
		freopen("B.in", "r", stdin);
	#endif
	read(n);
	rep(i, 1, n) read(a[i]); sort(a + 1, a + 1 + n);
	ll now = 0;
	int ct = 0;
	per(i, n, 2) {
		a[i] -= (a[i - 1] + 1);
		//if (a[i] < 0){ printf("cslnb"); return 0;}
		if (a[i] == -1) ct++;
	}
	if (ct > 1) { printf("cslnb"); return 0;}
	rep(i, 1, n){
		if (a[i] == -1){
			if (a[i - 1] <= 0) { printf("cslnb"); return 0;}
			else a[i - 1]--, a[i] = 0;
			break;
		}
	}
	per(i, n, 1) now += (ll)a[i] * (n - i + 1);
	if ((now & 1) == (ct ^ 1)) { printf("sjfnb"); return 0;}
	else { printf("cslnb"); return 0;}
	return 0;
}