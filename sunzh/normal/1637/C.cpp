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
int a[100010];
int main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;++i) a[i]=read();
		if(n==3&&a[2]%2!=0){
			printf("-1\n");continue ;
		}
		bool fl=1;long long ans=0;
		for(int i=2;i<n;++i) if(a[i]!=1) fl=0;
		for(int i=2;i<n;++i){
			ans+=(a[i]+1>>1);
		}
		if(fl) printf("-1\n");
		else printf("%lld\n",ans);
	}
}