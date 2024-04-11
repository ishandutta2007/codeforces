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
int a[400010];
int T;
int main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;++i) a[i]=read();
		a[0]=a[n+1]=0;
		long long ans=0;
		for(int i=1;i<=n+1;++i){
			ans+=abs(a[i]-a[i-1]);
		}
		for(int i=1;i<=n;++i){
			if(a[i]>a[i-1]&&a[i]>a[i+1]){
				int t=min(a[i]-a[i-1],a[i]-a[i+1]);
				ans-=t;
			}
		}
		printf("%lld\n",ans);
	}
}