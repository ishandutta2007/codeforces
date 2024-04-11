#include <bits/stdc++.h>

#define LL long long
#define pii pair<int,int>
using namespace std;
const int inf = 2147483647;
const int N = 200001;

int _max(int x, int y) {return x > y ? x : y;}
int _min(int x, int y) {return x < y ? x : y;}
inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
    while(ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return x * f;
}
void put(LL x) {
	if(x < 0) putchar('-'), x = -x;
	if(x >= 10) put(x / 10);
	putchar(x % 10 + '0');
}

struct Bit {
	int n, s[N];
	
	int lowbit(int x) {return x & -x;}
	void change(int x, int c) {for(int i = x; i <= n; i += lowbit(i)) s[i] += c;}
	int getsum(int x) {int sum = 0; for(int i = x; i; i -= lowbit(i)) sum += s[i]; return sum;}
} s;
struct node {
	int x, y;
} a[N];
int xx[N], yy[N];
vector<int> q[N];
vector<int> nxt[N], pre[N];
int S[N], ll[N], rr[N];
int tp, sta[N];

int findll(int x) {
	if(ll[x] != x) ll[x] = findll(ll[x]);
	return ll[x];
}

int findrr(int x) {
	if(rr[x] != x) rr[x] = findrr(rr[x]);
	return rr[x];
}

int main() {
	int n = read();
	for(int i = 1; i <= n; i++) a[i].x = xx[i] = read(), a[i].y = yy[i] = read();
	sort(xx + 1, xx + n + 1), sort(yy + 1, yy + n + 1);
	int l1 = unique(xx + 1, xx + n + 1) - (xx + 1), l2 = unique(yy + 1, yy + n + 1) - (yy + 1);
	for(int i = 1; i <= n; i++) a[i].x = lower_bound(xx + 1, xx + l1 + 1, a[i].x) - xx, a[i].y = lower_bound(yy + 1, yy + l2 + 1, a[i].y) - yy;
	LL ans = (LL)l1 * (l1 + 1) / 2;
	for(int i = 1; i <= n; i++) q[a[i].y].push_back(a[i].x);
	for(int i = 1; i < l2; i++) sort(q[i].begin(), q[i].end());
	for(int i = 1; i <= n; i++) S[a[i].x]++, ll[i] = rr[i] = i;
	s.n = l1; for(int i = 1; i <= n; i++) s.change(i, 1);
	int hh = l1;
	for(int i = 1; i < l2; i++) {
		LL sum = 0; int cc, len = (int)q[i].size();
		for(int j = 0; j < len; j++) {
			int x = q[i][j];
			S[x]--;
			if(j == 0) cc = s.getsum(q[i][0] - 1);
			else cc = s.getsum(q[i][j] - 1) - s.getsum(q[i][j - 1]);
			sum -= (LL)cc * (cc + 1) / 2;
			if(!S[x]) s.change(x, -1), --hh;
		} cc = s.getsum(l1) - s.getsum(q[i][len - 1]);
		sum -= (LL)cc * (cc + 1) / 2;
		sum += (LL)(hh + 1) * hh / 2;
		ans += sum;
	} put(ans), puts("");
	return 0;
}