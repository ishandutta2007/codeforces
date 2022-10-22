#include<bits/stdc++.h>
const int mod = 1e9 + 7;
const int maxn = 100100;
typedef long long ll;
inline void reduce(int & x) {
	x += x >> 31 & mod;
}
enum type{ Or, And };
template<type xxx> void Convolution(int * a, int * b, int * c, int lim);
template<> void Convolution<Or>(int * a, int * b, int * c, int lim) {
	if(lim <= 1) return void(c[0] = (ll) a[0] * b[0] % mod);
	lim >>= 1;
	for(int i = 0;i < lim;++i) {
		reduce(a[i + lim] += a[i] - mod);
		reduce(b[i + lim] += b[i] - mod);
	}
	Convolution<Or>(a, b, c, lim);
	Convolution<Or>(a + lim, b + lim, c + lim, lim);
	for(int i = 0;i < lim;++i) reduce(c[i + lim] -= c[i]);
}
template<> void Convolution<And>(int * a, int * b, int * c, int lim) {
	if(lim <= 1) return void(c[0] = (ll) a[0] * b[0] % mod);
	lim >>= 1;
	for(int i = 0;i < lim;++i) {
		reduce(a[i] += a[i + lim] - mod);
		reduce(b[i] += b[i + lim] - mod);
	}
	Convolution<And>(a, b, c, lim);
	Convolution<And>(a + lim, b + lim, c + lim, lim);
	for(int i = 0;i < lim;++i) reduce(c[i] -= c[i + lim]);
}
struct T
{
	int a[1 << 16];
	inline T operator & (const T & b) const { 
		T x, y, z; x = *this,y = b;
		Convolution<And>(x.a,y.a,z.a,1 << 16);
		return z;
	}
	inline T operator | (const T & b) const { 
		T x, y, z; x = *this,y = b;
		Convolution<Or>(x.a,y.a,z.a,1 << 16);
		return z;
	}
	inline T operator + (const T & y) const {
		T x;
		for(int i = 0;i < 1 << 16;++i) reduce(x.a[i] = a[i] + y.a[i] - mod);
		return x;
	}
} empty;
char s[maxn];
int n,a[maxn],b[maxn],c[maxn],d[maxn],e[maxn];
inline T get(int l,int r) {
	if(l + 1 == r) {
		T ret = empty;
		for(int i = 'A';i <= 'D';++i) {
			if(s[l] == i || s[l] == '?') {
				int s = 0;
				for(int j = 0;j < 16;++j) if((j >> i - 'A' & 1) == 1) s |= 1 << j;
				++ ret.a[s];
			}
			if(s[l] == i - 'A' + 'a' || s[l] == '?') {
				int s = 0;
				for(int j = 0;j < 16;++j) if((j >> i - 'A' & 1) == 0) s |= 1 << j;
				++ ret.a[s];
			}
		}
		return ret;
	}
	int o = 0;
	for(int i = l;i < r;++i) {
		if(s[i] == '(') ++ o;
		if(s[i] == ')') -- o;
		if(o == 0) {
			T a = get(l + 1, i),b = get(i + 3,r - 1),ans = empty;
			if(s[i + 1] != '|') ans = ans + (a & b);
			if(s[i + 1] != '&') ans = ans + (a | b);
			return ans;
		}
	}
	exit(1);
}
main()
{
	std::cin >> s >> n;
	T o = get(0, strlen(s));
	for(int i = 0;i < n;++i) std::cin >> a[i] >> b[i] >> c[i] >> d[i] >> e[i];
	int ans = 0;
	for(int i = 0;i < 1 << 16;++i) {
		for(int j = 0;j < n;++j) {
			int stu = a[j] << 0 | b[j] << 1 | c[j] << 2 | d[j] << 3;
			if((i >> stu & 1) != e[j]) goto nxt;
		}
		reduce(ans += o.a[i] - mod);
nxt:;
	}
	std::cout << ans << '\n';
}