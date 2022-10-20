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
const int N = 200005, T = 800005;
int tr[T], tag[T];
void pd(int x){
	if(tag[x]){
		tag[x<<1] += tag[x]; tag[x<<1|1] += tag[x];
		tr[x<<1] += tag[x]; tr[x<<1|1] += tag[x];
		tag[x]=0;
	}
}
void modify(int x, int l, int r, int ql, int qr, int v){
	//if(x == 1) printf("modify [%d, %d] : delta %d\n", ql, qr, v);
	if(ql <= l && r <= qr){
		tr[x] += v; tag[x] += v;
		return;
	}
	int mid = (l+r)>>1;
	pd(x);
	if(ql <= mid) modify(x<<1, l, mid, ql, qr, v);
	if(qr > mid) modify(x<<1|1, mid+1, r, ql, qr, v);
	tr[x] = max(tr[x<<1], tr[x<<1|1]);
}
/*int query(int x, int l, int r, int ql, int qr){
	if(ql <= l && r <= qr) return tr[x];
	int mid = (l + r) >> 1, res = 0;
	pd(x);
	if(ql<=mid) res = max(res, query(x<<1, l, mid, ql, qr));
	if(qr > mid) res = max(res, query(x<<1|1, mid+1, r, ql, qr));
	return res;
}*/
int n;
#define Rt 1, 1, n

int s1[N];
int ty[N];

int main(){
	//File("cf1257e");
	int c1, c2, c3, x;
	in(c1); in(c2); in(c3);
	n = c1 + c2 + c3;
	for(int i=1; i<=c1; i++) in(x), ++s1[x];
	for(int i=1; i<=c2; i++) in(x), ty[x] = 1, modify(Rt, x, n, 1);
	for(int i=1; i<=c3; i++) in(x), ty[x] = -1, modify(Rt, x, n, -1);
	for(int i=1; i<=n; i++) s1[i] += s1[i-1];
	int res = c1 + c2 - max(tr[1], 0);
	int used2 = 0;
	//printf("at first res = %d\n", res);
	for(int i=1; i<=n; i++){
		int get = i - s1[i];
		int give = c1 - s1[i];
		if(ty[i]){
			if(ty[i] == 1) ++used2;
			modify(Rt, i, n, -ty[i]);
		}
		int mx = max(tr[1], 0);
		int mov = (c2 - used2) - mx;
		//printf("i = %d : get %d give %d move %d\n", i, get, give, mov);
		res = min(res, get + give + mov);
	}
	printf("%d\n", res);
	return 0;
}