#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define File(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)
typedef long long ll;
// typedef __int128 ll;
template<class T>
inline void write(T x){
	if(x == 0){putchar('0'); return ;}
	if(x < 0) x = -x, putchar('-');
	static char stk[1024];
	int top = 0;
	while(x != 0) stk[top++] = x % 10, x /= 10;
	while(top) putchar(stk[--top] + '0');
}

const int Len = 3000005, Len2 = 3000005;
ll d[Len2], ds[Len2];
int BITLen;
inline void modifyT(ll *t, int p, ll x){for(; p<=BITLen; p += p & -p) t[p] += x;}
inline ll queryT(ll *t, int p){ll r = 0; for(; p; p ^= (p & -p)) r += t[p]; return r;}
inline void modify(int p, ll x){
	if(p <= BITLen)
		modifyT(d, p, x), modifyT(ds, p, x * (p - 1));
}
inline ll query(int p){
	if(p < 0) return 0;
	p = min(p, BITLen);
	return p * queryT(d, p) - queryT(ds, p);
}

char a[Len], b[Len], s[Len2];
char c1[Len + Len2], c2[Len + Len2];
int z1[Len + Len2], z2[Len + Len2];
void buildZ(char s[], int n, int z[]){
	// puts(s);
	z[0] = n;
	for(int i=1, l=0, r=0; i<n; i++){
		if(i > r) z[i] = 0;
		else z[i] = min(z[i - l], r - i + 1);
		while(s[z[i]] == s[i + z[i]]) ++z[i];
		if(i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
	}
	// puts("Z-function:");
	// for(int i=0; i<n; i++) printf("%d ", z[i]);
	// puts("");
}

int l1[Len], l2[Len];

int main(){
	// File("cf1313e");
	int n, m;
	scanf("%d%d", &n, &m);
	scanf("%s%s%s", a, b, s);
	int la = n, lb = n, ls = m;

	BITLen = max(max(la, lb), ls) + 1;
	copy(s, s+ls, c1); c1[ls] = '#'; copy(a, a+la, c1+ls+1);
	buildZ(c1, ls + la + 1, z1);
	reverse(b, b+lb); reverse(s, s+ls);
	copy(s, s+ls, c2); c2[ls] = '#'; copy(b, b+lb, c2+ls+1);
	buildZ(c2, ls + lb + 1, z2);
	for(int i=1; i<=la; i++) l1[i] = z1[ls + i];
	for(int i=1; i<=lb; i++) l2[i] = z2[ls + lb + 1 - i];//, printf("l2[%d] = %d\n", i, l2[i]);

	for(int i=1; i<=min(lb, ls - 1); i++)
		modify(1, +1), modify(l2[i] + 1, -1);
	ll res = query(ls - 1) - query(ls - l1[1] - 1);
	for(int i=2; i<=la; i++){
		modify(1, -1); modify(l2[i-1] + 1, +1);
		if(i + ls - 2 <= lb) modify(1, +1), modify(l2[i + ls - 2] + 1, -1);
		res += query(ls - 1) - query(ls - l1[i] - 1);
	}

	printf("%lld\n", res);
	return 0;
}