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
int n;
int p[200010];
int f[2000010];
int cnt[2000010];
bool guanjian[2000010];
void prework(int x){
	for(int i=2;i<=x;++i){
		if(!f[i]){
			f[i]=i;
			for(int j=i*2;j<=x;j+=i) if(!f[j]) f[j]=i;
		}
	}
}
bool u[200010];
const int mod=1e9+7;
inline int qpow(int x,int k=mod-2){
	int res=1;
	while(k){ if(k&1) res=1ll*res*x%mod; x=1ll*x*x%mod; k>>=1;}
	return res;
}
int main(){
	prework(2000000);
	n=read();
	bool flag=0;
	for(int i=1;i<=n;++i) p[i]=read();
	sort(p+1,p+n+1);
	reverse(p+1,p+n+1);
	for(int i=1;i<=n;++i){
		if(cnt[p[i]]){
			u[i]=1;
			int tmp=p[i]-1;
			int lst=-1,t=0;
			bool fl=0;
			while(tmp!=1){
				int p=f[tmp];
				if(p!=lst){
					if(lst!=-1){
						if(cnt[lst]<t) guanjian[lst]=1;
						else if(cnt[lst]==t) guanjian[lst]=0;
						cnt[lst]=max(cnt[lst],t);
					}
					t=1;lst=p;
				}
				else ++t;
				tmp/=p;
			}
			if(lst!=-1){
				if(cnt[lst]<t) guanjian[lst]=1;
				else if(cnt[lst]==t) guanjian[lst]=0;
				cnt[lst]=max(cnt[lst],t);
			}
		}
		else cnt[p[i]]=1;
	}
	int ans=1;
	for(int i=1;i<=2000000;++i) ans=1ll*ans*qpow(i,cnt[i])%mod;
	for(int i=1;i<=n;++i) if(u[i]){
		int tmp=p[i]-1;
		int lst=-1,t=0;
		bool fl=0;
		while(tmp!=1){
			int p=f[tmp];
			if(p!=lst){
				if(lst!=-1){
					if(guanjian[lst]&&cnt[lst]==t) fl=1;
				}
				t=1;lst=p;
			}
			else ++t;
			tmp/=p;
		}
		if(lst!=-1){
			if(guanjian[lst]&&cnt[lst]==t) fl=1;
		}
		if(!fl) flag=1;
	}
	printf("%d\n",ans+flag);
}