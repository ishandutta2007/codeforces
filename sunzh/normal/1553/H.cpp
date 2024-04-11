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
const int inf=1e9;
int n,k;
int mn[1<<19],mx[1<<19],ans[1<<19];
int main(){
	n=read(),k=read();
	for(int i=0;i<(1<<k);++i) ans[i]=mn[i]=inf,mx[i]=-inf;
	for(int i=1;i<=n;++i){
		int x=read();
		mn[x]=mx[x]=0;
	}
	for(int i=0;i<k;++i){
		for(int j=0;j<(1<<k);++j) if(j>>i&1){
			ans[j]=ans[j^(1<<i)]=min(ans[j],ans[j^(1<<i)]);
			ans[j]=min(ans[j],abs(mn[j^(1<<i)]+(1<<i)-mx[j]));
			ans[j^(1<<i)]=min(ans[j^(1<<i)],abs(mn[j]+(1<<i)-mx[j^(1<<i)]));
			int mn1=mn[j],mn2=mn[j^(1<<i)],mx1=mx[j],mx2=mx[j^(1<<i)];
			mn[j]=min(mn1,mn2+(1<<i));mn[j^(1<<i)]=min(mn2,mn1+(1<<i));
			mx[j]=max(mx1,mx2+(1<<i));mx[j^(1<<i)]=max(mx2,mx1+(1<<i));
		}
	}
	for(int i=0;i<(1<<k);++i) printf("%d ",ans[i]);
}