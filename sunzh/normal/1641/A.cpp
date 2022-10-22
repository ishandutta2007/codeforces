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
int n,X;
int a[1000010];
map<long long,int>exi;
int main(){
	T=read();
	while(T--){
		exi.clear();
		n=read(),X=read();
		for(int i=1;i<=n;++i) a[i]=read(),exi[a[i]]++;
		sort(a+1,a+n+1);
		int ans=n;
		for(int i=1;i<=n;++i){
			if(1ll*a[i]*X>a[n]) break ;
			int t=min(exi[a[i]],exi[a[i]*X]);
			ans-=t*2;exi[a[i]*X]-=t;exi[a[i]]-=t;
		}
		printf("%d\n",ans);
	}
}