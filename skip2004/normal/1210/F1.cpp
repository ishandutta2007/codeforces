#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#include<bits/stdc++.h>
#define all(v) (v).begin(),(v).end()
#define rep(i,l,r) for(int i=(l),i##end=(r);i<=i##end;++i)
using namespace __gnu_pbds;
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 20;
inline void flush(){cout.flush(),fflush(stdout);}
typedef unsigned long long u64;
typedef unsigned u32;
typedef long long ll;
typedef long double ld;
template<typename t>using heap=__gnu_pbds::priority_queue<t>;
template<typename t>using rbt=tree<t,null_type,less<t>,rb_tree_tag,tree_order_statistics_node_update>;
template<typename t>inline istream&operator,(istream&cin,t&x){return cin>>x;}
template<typename t>inline ostream&operator,(ostream&cout,const t&x){return cout<<x;}
template<typename _1,typename _2>inline void up(_1&a,const _2&b){if(a<b)a=b;}
template<typename _1,typename _2>inline void down(_1&a,const _2&b){if(a>b)a=b;}
istream&in=cin;ostream&out=cout;
inline int pow(int a,int b){
    int ans=1;
    for(;b;b>>=1,a=ll(a)*a%mod)
        if(b&1)ans=ll(ans)*a%mod;
    return ans;
}
inline int inv(int a){return pow(a,mod-2);}
typedef long long ll;
int a[maxn][maxn];;
int ans,n;
 
const int N = 2001000;
int f[N],g[N],b[N];
int mp[N],tot[maxn];
inline void reduce(int & x){ x += x >> 31 & mod; }
inline void dfs(int x){
}
inline int fac(int x){ return x == 0 ? 1 : fac(x - 1) * x; }
inline int C(int n,int m){ return fac(n) / fac(m) / fac(n - m); }
inline int pc(int x){ return __builtin_popcount(x); }
vector<int> v[maxn];
inline void fwt(int * a,int lim){
	if(!(lim/=2)) return;
	for(int i=0;i<lim;++i) reduce(a[i] += a[i + lim] - mod);;
	fwt(a,lim),fwt(a + lim,lim);
}
inline void fwt2(int * a,int lim){
	if(!(lim/=2)) return;
	for(int i=0;i<lim;++i) reduce(a[i] -= a[i + lim]);
	fwt2(a,lim),fwt2(a + lim,lim);
}
main(){
	ios::sync_with_stdio(false),in.tie(0);
	in,n;
	rep(i,0,n-1) rep(j,0,n-1){
		in,a[i][j];
		a[i][j] = ll(a[i][j]) * inv(100) % mod;
		b[i * n + j] = a[i][j];
	}
	rep(i,0,(1<<n)-1){
		v[pc(i)].push_back(i);
		mp[i] = tot[pc(i)]++;
	}
	const int m = n / 2;
	rep(i,0,(1<<(m * n))-1){
		int p = 1; int S[3];
		for(int j=0;j<m * n;++j) p = ll(p) * (i >> j & 1 ? b[j] : mod + 1 - b[j]) % mod;
		for(int j=0;j<m;++j) S[j] = (i >> j * n) & ((1 << n) - 1); 
		int st = 0;
		for(int j : v[m]){
			int s[3],tot = 0;
			for(int k=j;k;k&=k-1) s[tot++] = __builtin_ctz(k);
			sort(s,s + m);
			do{
				for(int j=0;j<m;++j)
					if((S[j] >> s[j] & 1) == 0) goto nxt;
				st |= 1 << mp[j];
				nxt:;
			}while(next_permutation(s,s+m));
		}
		reduce(f[st] += p - mod);
	}
	// fwt(f,1 << tot[m]);
	const int M = n - m;
	rep(i,0,(1<<(M * n))-1){
		int p = 1; int S[3];
		for(int j=0;j<M * n;++j) p = ll(p) * (i >> j & 1 ? b[j + n * m] : mod + 1 - b[j + n * m]) % mod;
		for(int j=0;j<M;++j) S[j] = (i >> j * n) & ((1 << n) - 1); 
		int st = 0;
		for(int j : v[n - m]){
			int s[3],tot = 0;
			for(int k=j;k;k&=k-1) s[tot++] = __builtin_ctz(k);
			sort(s,s + M);
			do{
				for(int j=0;j<M;++j) if((S[j] >> s[j] & 1) == 0) goto nxt2;
				st |= 1 << mp[(~j) & (1 << n) - 1];
				nxt2:;
			}while(next_permutation(s,s+M));
		}
		reduce(g[st] += p - mod);
	}
	int ans = 0;
	fwt(f,1 << tot[m]); fwt(g,1 << tot[m]);
	for(int i=0;i<1<<tot[m];++i) f[i] = ll(f[i]) * g[i] % mod;
	fwt2(f,1<<tot[m]);
	for(int i=1;i<1<<tot[m];++i) reduce(ans += f[i] - mod);
	out,ans,'\n';
}