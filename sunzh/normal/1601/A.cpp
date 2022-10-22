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
int n;
int a[200010];
int cnt[32];
int main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;++i) a[i]=read();
		memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=n;++i){
			for(int j=0;j<=30;++j) cnt[j]+=((a[i]&(1ll<<j))>0);
		}
		int ans=0;
		for(int i=0;i<=30;++i) ans=__gcd(ans,cnt[i]);
		for(int i=1;i<=n;++i) if(ans%i==0) printf("%d ",i);
		printf("\n");
	}
}