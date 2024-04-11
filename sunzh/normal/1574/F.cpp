#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<cstring>
#include<map>
#include<cmath>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==-1?~x+1:x;
}
int n,m,k;
int a[300010];
int pre[300010],nxt[300010];
const int mod=998244353;
int x,len,R[10500010];
inline int qpow(int x,int k=mod-2){
	int res=1;
	while(k){ if(k&1) res=1ll*res*x%mod; x=1ll*x*x%mod; k>>=1;}
	return res;
}
typedef vector<int>poly;
void NTT(poly &s,int f){
	for(int i=0;i<x;++i) if(R[i]>i) swap(s[i],s[R[i]]);
	for(int l=1;l<x;l<<=1){
		int w;
		if(f==1) w=qpow(3,(mod-1)/(l<<1));
		else w=qpow(qpow(3),(mod-1)/(l<<1));
		for(int j=0;j<x;j+=(l<<1)){
			int sum=1;
			for(int k=0;k<l;++k){
				int a1=s[j+k],a2=1ll*sum*s[j+k+l]%mod;
				sum=1ll*sum*w%mod;
				s[j+k]=(a1+a2)%mod,s[j+k+l]=(a1-a2+mod)%mod;
			}
		}
	}
	if(f==-1){
		int t=qpow(x);
		for(int i=0;i<x;++i) s[i]=1ll*s[i]*t%mod;
	}
}
poly inv(poly A){
	int n=A.size();
	if(n==1){
		return poly{qpow(A[0])};
	}
	int l=n+1>>1;
	poly son(l,0);
	for(int i=0;i<l;++i) son[i]=A[i];
	son=inv(son);
	x=1,len=0;while(x<n+n) x<<=1,++len;
	for(int i=0;i<x;++i) R[i]=(R[i>>1]>>1)|((i&1)<<len-1);
	son.resize(x);A.resize(x);NTT(son,1);NTT(A,1);
	for(int i=0;i<x;++i) A[i]=1ll*son[i]*(2-1ll*son[i]*A[i]%mod+mod)%mod;
	NTT(A,-1);
	A.resize(n);return A;
}
bool vis[300010];
int main(){
	n=read(),m=read(),k=read();
	for(int i=1;i<=n;++i){
		int c=read();
		for(int j=1;j<=c;++j){
			a[j]=read();
		}
		for(int j=2;j<=c;++j){
			if(!pre[a[j]]) pre[a[j]]=a[j-1];
			else if(pre[a[j]]!=a[j-1]) pre[a[j]]=-1;
		}
		for(int j=1;j<c;++j){
			if(!nxt[a[j]]) nxt[a[j]]=a[j+1];
			else if(nxt[a[j]]!=a[j+1]) nxt[a[j]]=-1;
		}
	}
	for(int i=1;i<=k;++i) if(pre[i]==-1||nxt[i]==-1) vis[i]=1;
	poly A(m+1,0);
	for(int i=1;i<=k;++i) if(!pre[i]&&!vis[i]){
		int cnt=1;
		int p=i;
		while(nxt[p]>0){
			p=nxt[p];
			// printf("p:%d,%d %d\n",p,pre[p],nxt[p]);
			if(pre[p]==-1){
				cnt=-1e9;break ;
			}
			if(nxt[p]==-1){
				cnt=-1e9;break ;
			}
			++cnt;
		}
		if(cnt<0)continue ;
		// if(k==300000) printf("cnt:%d\n",cnt);
		++A[cnt];
	}
	for(int i=0;i<=m;++i)A[i]=(i==0?A[i]+1:mod-A[i]);
	A=inv(A);
	printf("%d\n",A[m]);
}