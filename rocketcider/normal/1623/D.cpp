#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
const int maxn=5e5+10,mod=1e9+7;
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
mi ans,mul,p;
int cnt,m,n,st,sx,sy,tot,tx,ty,t_case,vis[4][maxn];
inline int id(int dx,int dy){return 2*(dx==-1)+(dy==-1);}
inline int idx(int x,int y){return (x-1)*m+y;}
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d%d%d%d%d%d",&n,&m,&sx,&sy,&tx,&ty,&p);
		p/=100;
		for(ri i=0;i<4;++i)clear(vis[i],idx(n,m),-1);
		cnt=st=tot=0;
		ri dx=1,dy=1;
		vis[0][idx(sx,sy)]=0;
		vector<int>pos;
		if(sx==tx||sy==ty)pos={0};
		while(true){
			if(sx==1)dx=1;if(sx==n)dx=-1;
			if(sy==1)dy=1;if(sy==m)dy=-1;
			sx+=dx,sy+=dy;
			if(~vis[id(dx,dy)][idx(sx,sy)]){
				st=vis[id(dx,dy)][idx(sx,sy)];
				break;
			}
			vis[id(dx,dy)][idx(sx,sy)]=++cnt;
			if(sx==tx||sy==ty)pos.push_back(cnt);
		}
		ans=0,mul=1;
		ri cyc=cnt-st+1,gd=0;
		for(ri i:pos)gd+=(i>=st);
		mi q=(1-p)^gd,lp=1/(1-q),ex=q*lp*lp;
		for(ri i:pos){
			if(i<st)ans+=mul*p*i;
			else ans+=mul*p*(i*lp+cyc*ex);
			mul*=1-p;
		}
		printf("%d\n",ans);
	}
	return 0;
}