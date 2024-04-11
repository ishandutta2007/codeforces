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
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==-1?~x+1:x;
}
int T;
int n;
int p[5010];
int sum[5010];
signed main(){
	T=read();
	while(T--){
		n=read();
		int ans=0;
		for(int i=1;i<=n;++i) p[i]=read(),sum[i]=0;
		for(int i=n-1;i>1;--i){
			for(int j=p[i+1]+1;j<=n;++j) ++sum[j];
			int nws=0;
			for(int j=i-1;j>1;--j){
				nws+=sum[p[j]];
				if(p[j-1]<p[i]) ans+=nws;
			}
		}
		printf("%lld\n",ans);
	}
}