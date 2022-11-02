#include <bits/stdc++.h>
using namespace std;
#define N 200010
#define inf 1000000000
#define ep 1e-9
#define mp make_pair
#define pb push_back
#define ll long long
template<class T> void chkmax(T &a, T b) {if (a < b) a = b;}
template<class T> void chkmin(T &a, T b) {if (a > b) a = b;}
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, m, l, r;
char ch, s[N];
struct node{ll b; int ct;} p[N<<2];

inline int f(char c) {
	if (c <= '9') return c - '0';
	if (c <= 'Z') return c - 'A' + 10;
	return c - 'a' + 36;
}

void build (int id, int st, int en) {
	if (st == en) {
		p[id].ct = 1;
		p[id].b = 1ll<<(f(s[st]));
	}
	else {
		int md = (st + en) >> 1;
		build(id<<1, st, md);
		build(id<<1|1, md + 1, en);
		p[id].ct = p[id<<1].ct + p[id<<1|1].ct;
		p[id].b = p[id<<1].b | p[id<<1|1].b;
	}
}
bool vis[N];
void query(int id, int st, int en, int le, int ri, char cc) {
	if (st == en) {
		p[id].ct = 0;
		p[id].b = 0;
		vis[st] = 1;
		return;
	}

	int md = (st + en) >> 1;
	int a = p[id<<1].ct;
	if (a >= le && (p[id<<1].b&(1ll<<f(cc)))) query(id<<1, st, md, le, min(ri, a), cc);
	if (a < ri && (p[id<<1|1].b&(1ll<<f(cc)))) query(id<<1|1, md + 1, en, max(1, le - a), ri - a, cc);
	p[id].ct = p[id<<1].ct + p[id<<1|1].ct;
	p[id].b = p[id<<1].b | p[id<<1|1].b;
}


int main() {
	scanf("%d %d ", &n, &m);
	gets(s + 1);
	build(1, 1, n);
	while (m --) {
		scanf("%d %d %c", &l, &r, &ch);
		if ((p[1].b&(1ll<<f(ch))) && p[1].ct) query(1, 1, n, l, r, ch);
	}
	for (int i = 1; i <= n; i ++) if (!vis[i]) putchar(s[i]);
    return 0;
}