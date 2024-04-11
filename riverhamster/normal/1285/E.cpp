#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;
#define File(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)
typedef long long ll;
template<typename T> inline void in(T &x){ //Read Positive Integer.
	char ch; x = 0;
	int f = 1;
	while(isspace(ch = getchar()));
	if(ch == '-') ch = getchar(), f = -1;
	do x = x * 10 + ch - '0'; while(isdigit(ch = getchar()));
	x *= f;
}

const int N = 200005, lgN = 20;
#define Rt 1, 1, pc*2-1
int l[N], r[N];
int p[N*2];
int sum[N*16], ndel[N*16], del[N*16];
int val[N*4];

void ins(int x, int l, int r, int ql, int qr){
	if(ql <= l && r <= qr){
		++sum[x]; return ;
	}
	int mid = (l + r) >> 1;
	if(ql <= mid) ins(x<<1, l, mid, ql, qr);
	if(qr > mid)  ins(x<<1|1, mid+1, r, ql, qr);
}
void build(int x, int l, int r){
	if(l == r){
		ndel[x] = sum[x] > 0;
		del[x] = sum[x] > 1;
		val[l] = sum[x];
		return ;
	}
	int mid = (l + r) >> 1;
	sum[x<<1] += sum[x]; sum[x<<1|1] += sum[x];
	build(x<<1, l, mid); build(x<<1|1, mid+1, r);
	ndel[x] = ndel[x<<1] + ndel[x<<1|1] - (int)(val[mid] && val[mid+1]);
	del[x] = del[x<<1] + del[x<<1|1] - (int)(val[mid] > 1 && val[mid+1] > 1);
}
int ask(int x, int l, int r, int ql, int qr){
	// printf("On query [%d, %d] : node %d[%d, %d]\n", ql, qr, x, l, r);
	if(ql <= l && r <= qr) return del[x];
	int mid = (l + r) >> 1, lt, rt;
	lt = ql <= mid ? ask(x<<1, l, mid, ql, qr) : ndel[x<<1];
	rt = qr > mid ? ask(x<<1|1, mid+1, r, ql, qr) : ndel[x<<1|1];
	// printf("%d[%d, %d]: res %d\n", x, l, r, lt + rt - (int)(val[mid] > (int)(ql <= mid && mid <= qr) && val[mid+1] > (ql <= mid+1 && mid+1 <= qr)));
	return lt + rt - (int)(val[mid] > (int)(ql <= mid && mid <= qr) && val[mid+1] > (ql <= mid+1 && mid+1 <= qr));
}

int main(){
	// File("cf1285e");
	int T; in(T);
	while(T--){
		int n, pc = 0; in(n);
		for(int i=1; i<=n; i++) in(l[i]), in(r[i]), p[++pc] = l[i], p[++pc] = r[i];
		sort(p+1, p+1+pc); pc = unique(p+1, p+1+pc) - p - 1;
		for(int i=1; i<=n; i++){
			l[i] = lower_bound(p+1, p+1+pc, l[i]) - p; r[i] = lower_bound(p+1, p+1+pc, r[i]) - p;
			ins(Rt, l[i]*2-1, r[i]*2-1);
		}
		build(Rt);
		int res = 1, t;
		for(int i=1; i<=n; i++) res = max(res, t = ask(Rt, l[i]*2-1, r[i]*2-1));//, printf("Final res %d\n", t);
		printf("%d\n", res);
		fill(sum+1, sum+1+8*pc, 0); fill(del+1, del+1+8*pc, 0); fill(ndel+1, ndel+1+8*pc, 0); fill(val, val+1+pc*2, 0);
		// memset(sum, 0, sizeof(sum)); memset(del, 0, sizeof(del)); memset(val, 0, sizeof(val));
	}
	return 0;
}