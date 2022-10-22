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
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){ if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:~x+1;
}
inline void print(int x){
	if(x<0) putchar('-'),x=~x+1;
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
const int mod=998244353;
const int inv2=998244354>>1;
int qpow(int x,int k){
	int res=1;
	while(k){
		if(k&1) res=1ll*res*x%mod;
		x=1ll*x*x%mod;
		k>>=1;
	}
	return res;
}
void FWT(std::vector<int>&s,int op,int n){
	for(int i=1;i<(1<<n);i<<=1){
		for(int p=i<<1,j=0;j<(1<<n);j+=p){
			for(int k=0;k<i;++k){
				int x=s[j+k],y=s[i+j+k];
				s[j+k]=(x+y)%mod,s[i+j+k]=(x-y+mod)%mod;
				if(op==-1) s[j+k]=1ll*s[j+k]*inv2%mod,s[i+j+k]=1ll*s[i+j+k]*inv2%mod;
			}
		}
	}
}
int n,m;
std::vector<int>vec[100010];
std::vector<int>A(512);
std::set<int>st[100010];
int SG[100010],in[100010],out[100010];
void getSG(){
	std::queue<int>Q;
	for(int i=1;i<=n;++i) if(out[i]==0) Q.push(i),SG[i]=0;
	while(!Q.empty()){
		int u=Q.front();Q.pop();
		for(int v:vec[u]){
			st[v].insert(SG[u]);
			if(--out[v]==0){
				Q.push(v);
				for(int i=0;i<512;++i){
					if(!st[v].count(i)){
						SG[v]=i;break ;
					}
				}
			}
		}
	}
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=m;++i){
		int u=read(),v=read();vec[v].pb(u);++in[v],++out[u];
	}
	getSG();
	for(int i=1;i<=n;++i){
		++A[SG[i]];
	}
	int invn1=qpow(n+1,mod-2);
	for(int i=0;i<512;++i) A[i]=1ll*A[i]*invn1%mod;
//	for(int i=0;i<20;++i) printf("%d\n",A[i]);
	FWT(A,1,9);
//	FWT(A,-1,9);
//	printf("%d\n\n",qpow(3,mod-2));
//	for(int i=0;i<20;++i) printf("%d\n",A[i]);
	int ans=0;
	for(int i=0;i<512;++i){/*n*invn1%mod*/
		(ans+=qpow((1ll-A[i]+mod)%mod,mod-2))%=mod;//printf("%d\n",ans);
	}
	ans=1ll*ans*qpow(512ll*(n+1)%mod,mod-2)%mod;
	printf("%d\n",(1-ans+mod)%mod);
}