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
#define maxn 1000120
#define maxm
#define maxs
#define maxb
#define M 
#define get GET
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std; 

int c[maxn];
void add(int x, int v){
	while (x < maxn) {
		c[x] += v;
		x += lowbit(x);
	}
}
int get(int x){
	int ans = 0;
	while (x){
		ans += c[x];
		x -= lowbit(x);
	}
	return ans;
}
int _lower_bound(int l, int r, int x){
	while (l < r){
		int mid = ((r - l) >> 1) + l;
		if (get(mid) < x) l = mid + 1; 
		else r = mid;
	}
	return l;
}

int n, q;

int main(){
	int x;
	scanf("%d%d", &n, &q);
	int ct = 0;
	rep(i, 1, n) scanf("%d", &x), add(x, 1), ct++;
	rep(i, 1, q){
		scanf("%d", &x);
		if (x < 0) {
			int _v = _lower_bound(1, maxn - 1, -x);
			//cerr << _v << endl;
			assert(_v != -1); 
			add(_v, -1);
			ct--;
		}
		else add(x, 1), ct++;
	}
	if (!ct) printf("0");
	else {
		srep(i, 1, maxn) if (get(i)) {printf("%d\n", i); return 0;} 
	}
	return 0;
}