#pragma GCC optimize(3)
#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
#include<cmath>
#define PII pair<int,int>
#define pb push_back
#define ep emplace_back
#define mp make_pair
#define fi first
#define se second
#define pow powl
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){ if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:-x;
}
inline void print(int x){
	if(x<0) putchar('-'),x=~x+1;
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
const int mod=998244353;
struct Matrix{
	int a[2][2];
	Matrix(){memset(a,0,sizeof(a));}
	friend Matrix operator *(Matrix x,Matrix y){
		Matrix res;
		for(int i=0;i<2;++i){
			for(int j=0;j<2;++j){
				for(int k=0;k<2;++k){
					(res.a[i][j]+=1ll*x.a[i][k]*y.a[k][j]%mod)%=mod;
				}
			}
		}
		return res;
	}
}seg[400010],bas;
struct edge{
	int u,fu,v,fv;
	double d;
	int D;
	bool operator <(const edge &x)const{
		return d>x.d;
	}
}e[400010];
int cnt;
int n;
int p[100010][2];
int v[100010],pos[100010];
int qpow(int x,int k){
	int res=1;
	while(k){
		if(k&1) res=1ll*res*x%mod;
		x=1ll*x*x%mod;
		k>>=1;
	}
	return res;
}

void pushup(int p){
	seg[p]=seg[p<<1]*seg[p<<1|1];
}
void update(int p,int l,int r,int pos,Matrix k){
	if(l==r) {
		seg[p]=k;
		return ;
	}
	int mid=l+r>>1;
	if(pos<=mid) update(p<<1,l,mid,pos,k);
	else update(p<<1|1,mid+1,r,pos,k);
	pushup(p);
}
Matrix query(int p,int l,int r,int L,int R){
	if(L>R) return bas;
	if(l>=L&&r<=R) return seg[p];
	int mid=l+r>>1;
	Matrix res=bas;
	if(L<=mid) res=res*query(p<<1,l,mid,L,R);
	if(R>mid) res=res*query(p<<1|1,mid+1,r,L,R);
	return res;
}
int main(){
	bas.a[0][0]=bas.a[1][1]=1;
	n=read();
	const int inv100=qpow(100,mod-2);
	for(int i=1;i<=n;++i){
		pos[i]=read(),v[i]=read();
		int x=read();
		p[i][1]=1ll*x*inv100%mod;p[i][0]=(mod+1-p[i][1])%mod;
	}
	Matrix pre;pre.a[0][0]=p[1][0],pre.a[0][1]=p[1][1];
	update(1,1,n,1,pre);
	auto ed=[&](int i,int j,int k,int l,double d,int D){
		edge res;
		res.u=i,res.fu=j,res.v=k,res.fv=l,res.d=d,res.D=D;return res;
	};
	for(int i=1;i<n;++i){
		e[++cnt]=ed(i,0,i+1,0,v[i+1]<=v[i]?1e10:(pos[i+1]-pos[i])*1.0/(v[i+1]-v[i]),v[i+1]<=v[i]?0:1ll*(pos[i+1]-pos[i])*qpow(v[i+1]-v[i],mod-2)%mod);
		e[++cnt]=ed(i,1,i+1,1,v[i]<=v[i+1]?1e10:(pos[i+1]-pos[i])*1.0/(v[i]-v[i+1]),v[i]<=v[i+1]?0:1ll*(pos[i+1]-pos[i])*qpow(v[i]-v[i+1],mod-2)%mod);
//		printf("pos:%d %d\n",pos[i+1],pos[i]);
//		printf("V:%d %d\n",v[i+1],v[i]);printf("%lf\n",(pos[i+1]-pos[i])*1.0/(v[i+1]+v[i]));
		e[++cnt]=ed(i,0,i+1,1,1e10,0);
		e[++cnt]=ed(i,1,i+1,0,(pos[i+1]-pos[i])*1.0/(v[i+1]+v[i]),1ll*(pos[i+1]-pos[i])*qpow(v[i+1]+v[i],mod-2)%mod);
	}
	sort(e+1,e+cnt+1);
	int ans=0;
	for(int i=1;i<=cnt;++i){
		int u=e[i].u;
		Matrix tmp=query(1,1,n,u+1,u+1);
		tmp.a[e[i].fu][e[i].fv]=1ll*p[u+1][e[i].fv]%mod;
		update(1,1,n,u+1,tmp);if(e[i].D==0) continue ;
		Matrix res;res.a[e[i].fu][e[i].fv]=1ll*p[u+1][e[i].fv]%mod;
		res=query(1,1,n,1,u)*res;
		res=res*query(1,1,n,u+2,n);
		(ans+=1ll*(res.a[0][0]+res.a[0][1])%mod*e[i].D%mod)%=mod;
	}
	printf("%d\n",ans);
}