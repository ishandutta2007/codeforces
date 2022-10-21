#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
const int maxn=2e5+10,mod=998244353;
clock_t st;inline void f(){while(1.0*(clock()-st)/CLOCKS_PER_SEC<=1.97);}
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
int a[maxn],k,m,n,q,x[maxn],y[maxn],t_case;
bool v1[maxn],v2[maxn];
int main(){
	st=clock();
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d%d%d",&n,&m,&k,&q);
		clear(v1,n),clear(v2,m);
		for(ri i=1;i<=q;++i)scanf("%d%d",x+i,y+i);
		ri cnt=0,cnt1=0,cnt2=0;
		for(ri i=q;i;--i){
			if(!v1[x[i]]&&!v2[y[i]])++cnt,++cnt1,++cnt2;
			else if(!v1[x[i]]&&cnt2<m)++cnt,++cnt1;
			else if(!v2[y[i]]&&cnt1<n)++cnt,++cnt2;
			v1[x[i]]=v2[y[i]]=true;
		}
		printf("%d\n",mi(k)^cnt);
	}
	return f(),0;
}