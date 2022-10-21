#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=2e5+10,mod=998244353;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
namespace st{
	#define int long long 
	typedef long long ll;
	const ll mod=998244353;
	int G=3,invG;
	const int N=2400000;
	ll ksm(ll b,int n){
	    ll res=1;
	    while(n){
	        if(n&1) res=res*b%mod;
	        b=b*b%mod; n>>=1;
	    }
	    return res;
	}
	int tr[N];
	void NTT(ll *f,int n,int fl){
	    for(int i=0;i<n;++i)
	        if(i<tr[i]) swap(f[i],f[tr[i]]);
	    for(int p=2;p<=n;p<<=1){
	        int len=(p>>1);
	        ll w=ksm((fl==0)?G:invG,(mod-1)/p);
	        for(int st=0;st<n;st+=p){
	            ll buf=1,tmp;
	            for(int i=st;i<st+len;++i)
	                tmp=buf*f[i+len]%mod,
	                f[i+len]=(f[i]-tmp+mod)%mod,
	                f[i]=(f[i]+tmp)%mod,
	                buf=buf*w%mod;
	        }
	    }
	    if(fl==1){
	        ll invN=ksm(n,mod-2);
	        for(int i=0;i<n;++i)
	            f[i]=(f[i]*invN)%mod;
	    }
	}
	ll f[N],g[N],a[N],b[N],c[N],fac[N],ifac[N],inv[N];
	void init(int n){
	    fac[0]=1;
	    for(int i=1;i<=n;++i)
	        fac[i]=1ll*fac[i-1]*i%mod;
	    ifac[n]=ksm(fac[n],mod-2);
	    for(int i=n-1;i>=0;--i)
	        ifac[i]=1ll*(i+1)*ifac[i+1]%mod;
	    inv[1]=1;
	    for(ri i=2;i<=n;++i)
	    	inv[i]=(mod-mod/i)*inv[mod%i]%mod;
	}
	void main(int n){
	    invG=ksm(G,mod-2);
	    init(n);
	    for(int i=0;i<=n;++i){
	        a[i]=(i&1?mod-ifac[i]:ifac[i]);
	        if(i==1)b[i]=(n+1)*ifac[i]%mod;
			else b[i]=(1-ksm(i,n+1)+mod)%mod*ksm(1-i+mod,mod-2)%mod*ifac[i]%mod;
	    }
	    int limit=1;
	    while(limit<=(n<<1)) limit<<=1;
	    for(int i=0;i<=limit;++i)
	        tr[i]=(tr[i>>1]>>1)|(i&1?limit>>1:0);
	    NTT(a,limit,0);NTT(b,limit,0);
	    for(int i=0;i<=limit;++i)
	        a[i]=a[i]*b[i]%mod;
	    NTT(a,limit,1);
	    for(int i=0;i<=limit;++i)c[i]=a[i];
	    clear(tr,limit),clear(f,limit),clear(g,limit),clear(a,limit),clear(b,limit),clear(fac,limit),clear(ifac,limit),clear(inv,limit);
	}
	#undef int
}
struct modint{
	int val;
	inline modint(int val_=0):val(val_){}
	inline modint &operator=(int val_){return val=val_,*this;}
	inline modint &operator+=(const modint &k){return val=val+k.val>=mod?val+k.val-mod:val+k.val,*this;}
	inline modint &operator-=(const modint &k){return val=val-k.val<0?val-k.val+mod:val-k.val,*this;}
	inline modint &operator*=(const modint &k){return val=1ll*val*k.val%mod,*this;}
	inline modint &operator^=(int k){
	    modint ret=1,tmp=*this;
	    for(;k;k>>=1,tmp*=tmp)if(k&1)ret*=tmp;
	    return val=ret.val,*this;
	}
	inline modint &operator/=(modint k){return *this*=(k^=mod-2);}
	inline modint &operator+=(int k){return val=val+k>=mod?val+k-mod:val+k,*this;}
	inline modint &operator-=(int k){return val=val<k?val-k+mod:val-k,*this;}
	inline modint &operator*=(int k){return val=1ll*val*k%mod,*this;}
	inline modint &operator/=(int k){return *this*=((modint(k))^=mod-2);}
	template<class T>friend modint operator+(modint a,T b){return a+=b;}
	template<class T>friend modint operator-(modint a,T b){return a-=b;}
	template<class T>friend modint operator*(modint a,T b){return a*=b;}
	template<class T>friend modint operator^(modint a,T b){return a/=b;}
	template<class T>friend modint operator/(modint a,T b){return a/=b;}
	friend modint operator^(modint a,int b){return a^=b;}
	friend bool operator==(modint a,int b){return a.val==b;}
	friend bool operator!=(modint a,int b){return a.val!=b;}
	inline bool operator!(){return !val;}
	inline modint operator-(){return val?mod-val:0;}
	inline modint &operator++(){return *this+=1;}
};
using mi=modint;
mi mu[maxn],pre[maxn];
vector<int>pri;
bool vis[maxn];
inline void sieve(int siz){
	mu[1]=pre[1]=1;
	for(ri i=2;i<=siz;++i){
		if(!vis[i])mu[i]=mod-1,pri.push_back(i);
		for(ri j:pri){
			if(i*j>siz)break;
			vis[i*j]=true;
			if(i%j==0)break;
			mu[i*j]=-mu[i];
		}
		pre[i]=pre[i-1]+mu[i];
	}
}
mi ans;
int k,m,n;
inline mi calc(int k){
	st::main(k);
	mi ret=0;
	for(ri i=1;i<=min(k,m);++i)ret+=(st::c[i]*(i-1+(i!=m))%mod);
	return ret;
}
int main(){
	scanf("%d%d",&n,&m);
	if(n==1||m==1)return putchar(49),0;
	sieve(--n);
	for(ri i=1;i<=n;){
		ri nxt=n/(n/i);
		ans+=calc(n/i)*(pre[nxt]-pre[i-1]);
		i=nxt+1;
	}
	printf("%d",ans);
	return 0;
}