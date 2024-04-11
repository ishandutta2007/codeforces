#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;
#define File(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)
typedef long long ll;
template<typename T> inline void gi(T &x){
	char ch; x = 0;
	int f = 1;
	while(isspace(ch = getchar()));
	if(ch == '-') ch = getchar(), f = -1;
	do x = x * 10 + ch - '0'; while(isdigit(ch = getchar()));
	x *= f;
}
template<class T> void upmax(T &x, T y){x = x>y ? x : y;}
template<class T> void upmin(T &x, T y){x = x<y ? x : y;}

const int N = 200005, V = 1000005, lgV = 22;
const int Mn = -1000000000;
const int Mx = 1000000000;
int mx[V * 3], tag[V * 3], lc[V * 3], rc[V * 3], nc = 0;

struct Ka{
	int a, c;
}a[N];
struct Kb{
	int a, c;
}b[N];
struct Mo{
	int a, b, c;
}mo[N];
template<class T>
bool cmpa(T a, T b){
	// if(a.a == b.a) return a.c > b.c;
	return a.a < b.a;
}

int root = 0;
void mdy(int &x, int l, int r, int ql, int qr, int v){
	if(!x) x = ++nc, mx[x] = 0;
	// if(x == root) printf("mdy [%lld, %lld] %lld\n", ql, qr, v);
	if(ql > qr) return ;
	if(ql <= l && r <= qr){
		tag[x] += v, mx[x] += v;
		return ;
	}
	int mid = (l + r) >> 1;
	if(ql <= mid) mdy(lc[x], l, mid, ql, qr, v);
	if(qr > mid) mdy(rc[x], mid+1, r, ql, qr, v);
	if(l == r) mx[x] = tag[x];
	else mx[x] = max(mx[lc[x]], mx[rc[x]]) + tag[x];
}

#define Rt root, 1, 1000000
int costa[N];
int main(){
	// File("c");
	int n, m, p, mAc = Mx, mBc = Mx;
	gi(n); gi(m); gi(p);
	for(int i=1; i<=n; i++)
		gi(a[i].a), gi(a[i].c), upmin(mAc, a[i].c);
	for(int i=1; i<=m; i++)
		gi(b[i].a), gi(b[i].c), upmin(mBc, b[i].c);
	for(int i=1; i<=p; i++)
		gi(mo[i].a), gi(mo[i].b), gi(mo[i].c);
	sort(a+1, a+1+n, cmpa<Ka>);
	sort(b+1, b+1+m, cmpa<Kb>);
	sort(mo+1, mo+1+p, cmpa<Mo>);
	if(b[m].a == 1){
		printf("%d\n", -mAc - mBc);
		return 0;
	}
	costa[n + 1] = Mx;
	for(int i=n; i>=1; i--)
		costa[i] = min(costa[i+1], a[i].c);
	int mnC = b[m].c;
	mx[0] = Mn;
	for(int i=m-1; i>=1; i--){
		mdy(Rt, b[i].a, b[i+1].a - 1, -mnC);
		upmin(mnC, b[i].c);
	}
	mdy(Rt, 1, b[1].a - 1, -mnC);
	int pa = 1;
	int res = -mAc - mBc;
	// printf("Initially res = %d\n", res);
	for(int i=1; i<=p; i++){
		while(a[pa].a <= mo[i].a && pa <= n) ++pa;
		if(pa > n) break;
		mdy(Rt, mo[i].b, b[m].a - 1, +mo[i].c);
		// printf("i %d mx[root] %d pa %d costa[pa] %d\n", i, mx[root], pa, costa[pa]);
		upmax(res, mx[root] - costa[pa]);
	}
	printf("%d\n", res);
	return 0;
}