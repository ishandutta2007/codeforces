#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
#define PII pair<int,int>
#define pb push_back
#define ep emplace_back
#define mp make_pair
#define fi first
#define se second
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){ if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:-x;
}
inline void print(int x){
	if(x<0) putchar('-'),x=~x+1;
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int n,I;
int a[4000010],b[4000010];
signed main(){
	n=read(),I=read();
	for(int i=1;i<=n;++i) a[i]=read();
	int sz=(8ll*I)/n;
	int siz=1;
	while(sz){
		siz<<=1ll;
		--sz;
		if(siz>n){
			printf("0\n");return 0;
		}
	}
	sort(a+1,a+n+1);
	memcpy(b,a,sizeof(a));
	int m=unique(b+1,b+n+1)-b-1;
	int ans=0;
	for(int i=1;i<=m;++i){
		int j=upper_bound(a+1,a+n+1,b[i+siz-1>m?m:i+siz-1])-a-1;
		int k=lower_bound(a+1,a+n+1,b[i])-a;
		ans=max(ans,j-k+1);
	}
	printf("%lld\n",n-ans);
}