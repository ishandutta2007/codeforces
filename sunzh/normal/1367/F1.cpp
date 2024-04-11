#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#define PII pair<int,int>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9') { if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9') { x=(x<<3)+(x<<1)+(c^48); c=getchar();}
	return f==1?x:-x;
}
inline void print(int x){
	if(x<0) x=~x+1,putchar('-');
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int T;
int n;
int dp[300010][3];
int a[300010],b[300010];
int pos[300010];
int num[300010],tar[300010];
int l[300010];
int main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;++i) a[i]=b[i]=read();
		sort(b+1,b+n+1);
		int m=unique(b+1,b+n+1)-b-1;
		for(int i=1;i<=m;++i) pos[i]=l[i]=num[i]=tar[i]=0;
		for(int i=1;i<=n;++i) a[i]=lower_bound(b+1,b+m+1,a[i])-b,tar[a[i]]++,dp[i][0]=dp[i][1]=dp[i][2]=0;
		for(int i=1;i<=n;++i) if(!l[a[i]]) l[a[i]]=i;
		int res=0;
		for(int i=1;i<=n;++i){
			dp[i][0]=dp[pos[a[i]]][0]+1;
			dp[i][1]=max(max(dp[pos[a[i]-1]][0],dp[pos[a[i]-1]][2]),dp[pos[a[i]]][1])+1; 
			++num[a[i]];pos[a[i]]=i;
			if(num[a[i]]==tar[a[i]]){
				dp[i][2]=dp[l[a[i]]][1]+num[a[i]]-1;
			}
			res=max(res,max(dp[i][0],max(dp[i][1],dp[i][2])));
		}
		printf("%d\n",n-res);
	}
	return 0;
}