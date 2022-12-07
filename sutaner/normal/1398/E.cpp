#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define erep2(i, x) for (register int& i = cur[x]; i; i = e[i].next)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define fi first
#define se second
#define ui unsigned int
#define ld long double
#define ll long long int 
#define pb push_back
#define pc putchar
#define lowbit(x) (x & -x)
#define maxr 2000020
#define maxn 400020
#define maxm
#define maxs
#define maxb
#define M 
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
	char ch = gc(); x = 0; bool f = 1;
	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
	if (ch == '-') f = 0, ch = gc();
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
}
int _num[20];
template <class T> void write(T x){	
	if (!x) {putchar('0'), putchar('\n'); return;}
	if (x < 0) putchar('-'), x = -x;
	int c = 0;
	while (x) _num[++c] = x % 10, x /= 10;
	while (c) putchar('0' + _num[c--]); 
	putchar('\n');
}

int n;
int lis[maxn], cs = 0;
pii ope[maxn];

ll sum[maxn << 2];
int num[maxn << 2];
int qx, qy, qd;
void add(int l, int r, int o){
	sum[o] += qd * lis[qx], num[o] += qd;
	if (l == r) return;
	int mid = ((r - l) >> 1) + l;
	if (qx <= mid) add(l, mid, o << 1);
	else add(mid + 1, r, o << 1 | 1);
}
ll get(int l, int r, int o){
	if (l == r) return sum[o];
	int mid = ((r - l) >> 1) + l;
	if (num[o << 1 | 1] >= qd) return get(mid + 1, r, o << 1 | 1);
	else {qd -= num[o << 1 | 1]; return sum[o << 1 | 1] + get(l, mid, o << 1);}
}

set<int> light, fire; 
ll sum_light = 0;

int main(){
	read(n);
	rep(i, 1, n) read(ope[i].fi), read(ope[i].se), lis[++cs] = abs(ope[i].se);
	sort(lis + 1, lis + 1 + cs);
	cs = unique(lis + 1, lis + 1 + cs) - lis - 1;
	int x, y;
	rep(i, 1, n) {
		int d = 1;
		if (ope[i].se < 0) d = -1;
		x = ope[i].fi;
		y = lower_bound(lis + 1, lis + 1 + cs, abs(ope[i].se)) - lis;
		y *= d; 
		if (x == 0){
			if (y > 0) fire.insert(lis[y]);
			else fire.erase(lis[-y]);
		}
		else {
			if (y > 0) light.insert(lis[y]), sum_light += lis[y];
			else light.erase(lis[-y]), sum_light -= lis[-y]; 
		}
		qx = abs(y), qd = (y > 0) ? 1 : -1;
		add(1, cs, 1);
		
		ll res = sum[1];
		if (!light.empty()){
			if (fire.empty()) res += (sum_light - *light.begin()); 
			else if (*light.begin() > *fire.rbegin()){
				res += (sum_light - *light.begin() + *fire.rbegin()); 
			}
			else {
				qd = light.size();
				res += get(1, cs, 1);
			}
		}
		printf("%lld\n", res);
	}
	return 0;
}