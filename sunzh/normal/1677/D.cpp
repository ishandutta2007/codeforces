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
int T;
int n,k;
int p[1000010];
const int mod=998244353;
int main(){
	T=read();
	while(T--){
		n=read(),k=read();
		for(int i=1;i<=n;++i) p[i]=read();
		int ans=1;
		for(int i=1;i<=k;++i) ans=1ll*ans*i%mod;
		for(int i=1;i<=n;++i){
			if(p[i]>=i) ans=0;
			else if(i>n-k){
				if(p[i]>0) ans=0;
			}
			else if(p[i]==0){
				ans=1ll*ans*(k+1)%mod;
			}
			else if(p[i]==-1){
				ans=1ll*ans*(k+i)%mod;
			}
		}
		printf("%d\n",ans);
	}
}