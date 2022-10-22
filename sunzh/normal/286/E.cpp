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
int n,m;
int a[1000010];
bool used[1000010];
int F[1<<21];
int x=(1<<21),len=21;
int R[1<<21];
const int mod=998244353;
inline int qpow(int x,int k=mod-2){
	int res=1;
	while(k){ if(k&1) res=1ll*res*x%mod; x=1ll*x*x%mod; k>>=1;}
	return res;
}
void NTT(int *s,int f){
	for(int i=0;i<x;++i) if(R[i]>i) swap(s[i],s[R[i]]);
	for(int l=1;l<x;l<<=1){
		int w;if(f==1) w=qpow(3,(mod-1)/(l<<1));else w=qpow(qpow(3),(mod-1)/(l<<1));
		for(int j=0;j<x;j+=(l<<1)){
			int sum=1;
			for(int k=0;k<l;++k){
				int s1=s[j+k],s2=1ll*s[j+k+l]*sum%mod;
				sum=1ll*sum*w%mod;
				s[j+k]=(s1+s2>=mod?s1+s2-mod:s1+s2);
				s[j+k+l]=(s1>=s2?s1-s2:s1+mod-s2);
			}
		}
	}
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i) a[i]=read(),used[a[i]]=1;
	for(int i=1;i<=m;++i) if(used[i]){
		bool f=1;
		for(int j=i;j<=m;j+=i) f&=used[j];
		if(!f){
			printf("NO\n");return 0;
		}
	}
	for(int i=0;i<x;++i) R[i]=(R[i>>1]>>1)|((i&1)<<len-1);
	for(int i=1;i<=m;++i) F[i]=used[i];
	NTT(F,1);
	for(int i=0;i<x;++i) F[i]=1ll*F[i]*F[i]%mod;
	NTT(F,-1);
	vector<int>ans;
	for(int i=0;i<=m;++i){
		if(used[i]&&!F[i]){
			ans.pb(i);
		}
		if(F[i]&&!used[i]){
			printf("NO\n");return 0;
		}
	}
	printf("YES\n%d\n",ans.size());
	for(int i:ans) printf("%d ",i);
}