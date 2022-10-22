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
int a[200010];
long long b[200010];
signed main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;++i) a[i]=read();
		int ans=0;
		for(int i=1;i<=n;++i){
			int j=i;
			while(j<n&&a[j+1]==a[i]) ++j;
			int tmp=0;
			int res=j-i+1;
			for(int k=j+1;k<=n;k++){
				int lst=lower_bound(a+k,a+n+1,a[k-1]+a[k-1]-a[i])-a;
				if(lst>n) break ;
				// printf("i:%d,j:%d,k:%d,lst:%d\n",i,j,k,lst);
				++res;//tmp=a[lst]-a[k-1];
				k=lst;
				// printf("%d\n",tmp);
			}
			i=j;
			ans=max(ans,res);
		}
		printf("%lld\n",n-ans);
	}
}