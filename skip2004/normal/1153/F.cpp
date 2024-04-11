#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#include<unordered_map>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
#define all(v) (v).begin(),(v).end()
#define rep(i,l,r) for(int i=(l),i##end=(r);i<=i##end;++i)
using namespace __gnu_pbds;
using namespace std;
const int mod = 998244353;
const int maxn = 4010;
inline void flush(){cout.flush(),fflush(stdout);}
typedef unsigned long long u64;
typedef unsigned u32;
typedef long long ll;
typedef long double ld;
template<typename T>using heap=__gnu_pbds::priority_queue<T>;
template<typename T>using rbt=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
template<typename T>inline istream&operator,(istream&cin,T&x){return cin>>x;}
template<typename T>inline ostream&operator,(ostream&cout,const T&x){return cout<<x;}
template<typename _1,typename _2>inline void up(_1&a,const _2&b){if(a<b)a=b;}
template<typename _1,typename _2>inline void down(_1&a,const _2&b){if(a>b)a=b;}
istream&in=cin;ostream&out=cout;
inline int pow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=ll(a)*a%mod)
		if(b&1)ans=ll(ans)*a%mod;
	return ans;
}
int _[maxn],inv_[maxn],_inv[maxn];
inline int inv(int a){return inv_[a];}
int n,k,l;
int p[maxn];
inline void reduce(int & x){
	x += x >> 31&mod;
}
inline void mul(int*a,const int * b){
	static int c[maxn];
	memset(c,0,sizeof c);
	for(int j=0;j<3;++j)
		for(int i=0;i+j<maxn;++i)
			reduce(c[i+j]+=(ll)a[i]*b[j]%mod-mod);
	for(int i=0;i<maxn;++i) a[i]=c[i];
}
inline void div(int*a,const int*b){
	int t=pow(b[2],mod-2);
	for(int i=maxn;--i>=2;){
		a[i]=ll(a[i])*t%mod;
		if(i>=1)reduce(a[i-1]-=(ll)a[i]*b[1]%mod);
		if(i>=2)reduce(a[i-2]-=(ll)a[i]*b[0]%mod);
	}
	for(int i=0;i+2<maxn;++i) a[i]=a[i+2];
	a[maxn-1]=0,a[maxn-2]=0;
}
inline int INT(int *a,int b){
	int ans=0;
	for(int i=0,t=1;i+1<maxn;++i){
		t=ll(t)*b%mod;
		reduce(ans += ll(a[i]) * inv(i+1) % mod * t % mod-mod);
	}
	return ans;
}
int main(){
	inv_[1]=1;
	for(int i=2;i<maxn;++i) inv_[i]=ll(inv_[mod%i])*(mod-mod/i)%mod;
	_inv[0]=_[0]=1;
	for(int i=1;i<maxn;++i)
		_[i]=ll(_[i-1])*i%mod,
		_inv[i]=ll(_inv[i-1])*inv_[i]%mod;
	in,n,k,l;
	int a1[3]={0,1,mod-1},a2[3];
	for(int&i:a1)i=ll(i)*2%mod;
	reduce(a2[0]=1-a1[0]);
	for(int i=1;i<3;++i) reduce(a2[i]=-a1[i]);
	p[0]=1;
	for(int i=1;i<=k;++i)mul(p,a1);
	for(int i=1;i<=n-k;++i)mul(p,a2);
	int ans=0,t=0;
	for(int i=k;i<=n;++i){
		int c=ll(_[n])*_inv[i]%mod*_inv[n-i]%mod;
		reduce(ans+=INT(p,1)*ll(c)%mod-mod);
		reduce(t+=c-mod);
		mul(p,a1),div(p,a2);
	}
	out,ll(ans)*inv(1)%mod*l%mod,'\n';
}