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
int r,c;
char str[2010][2010];
const int mod=998244353;
vector<int>vec[4010];
int fa[4010],sum[4010],siz[4010],xsum[4010];
int sumr[4010],sumc[4010];
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
inline int qpow(int x,int k=mod-2){
	int res=1;
	while(k){ if(k&1) res=1ll*res*x%mod; x=1ll*x*x%mod; k>>=1;}
	return res;
}
int main(){
	r=read(),c=read();
	for(int i=1;i<=r;++i) scanf("%s",str[i]+1);
	if(r%2==0&&c%2==0){
		int ans=1;
		for(int i=1;i<=r;++i){
			for(int j=1;j<=c;++j) if(str[i][j]=='?') ans=(ans+ans)%mod;
		}
		printf("%d\n",ans);
	}
	else if(r%2==0||c%2==0){
		int ans0=1,ans1=1;
		if(r%2==0){
			for(int i=1;i<=r;++i){
				int cnt=0;
				int p=0;
				for(int j=1;j<=c;++j) cnt+=(str[i][j]=='?'),p^=(str[i][j]=='1');
				if(!cnt){
					if(p==0) ans1=0;else ans0=0;
				}
				else ans0=1ll*qpow(2,cnt-1)*ans0%mod,ans1=1ll*ans1*qpow(2,cnt-1)%mod;
			}
		}
		else{
			for(int i=1;i<=c;++i){
				int cnt=0;
				int p=0;
				for(int j=1;j<=r;++j) cnt+=(str[j][i]=='?'),p^=(str[j][i]=='1');
				if(!cnt){
					if(p==0) ans1=0;else ans0=0;
				}
				else ans0=1ll*qpow(2,cnt-1)*ans0%mod,ans1=1ll*ans1*qpow(2,cnt-1)%mod;
			}
		}
		printf("%d\n",(ans0+ans1)%mod);
	}
	else{
		for(int i=1;i<=r+c;++i) fa[i]=i,sum[i]=siz[i]=0;
		for(int i=1;i<=r;++i){
			for(int j=1;j<=c;++j) if(str[i][j]=='?'){
				int fx=find(i),fy=find(j+r);
				if(fx!=fy) fa[fx]=fy,sum[fy]+=sum[fx];++sum[fy];
			}
			else{
				sumr[i]^=(str[i][j]=='1');sumc[j]^=(str[i][j]=='1');
			}
		}
		int ans0=1,ans1=1;
		for(int i=1;i<=r+c;++i){
			siz[find(i)]++;
			if(i<=r) xsum[find(i)]^=sumr[i];
			else xsum[find(i)]^=sumc[i-r];
		}
		for(int i=1;i<=r+c;++i) if(find(i)==i){
			if(siz[i]&1){
				if(xsum[i]==0) ans1=0,ans0=1ll*ans0*qpow(2,sum[i]-siz[i]+1)%mod;
				else ans0=0,ans1=1ll*ans1*qpow(2,sum[i]-siz[i]+1)%mod;
			}
			else if(xsum[i]==0){
				ans0=1ll*ans0*qpow(2,sum[i]-siz[i]+1)%mod;
				ans1=1ll*ans1*qpow(2,sum[i]-siz[i]+1)%mod;
			}
			else ans0=ans1=0;
		}
		printf("%d\n",(ans0+ans1)%mod);
	}
}