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
int a[50010];
int X;
long long pr[50010];
long long b[50010];
int tre[50010];
void upd(int x,int k){
	while(x){
		tre[x]=max(tre[x],k);x-=x&-x;
	}
}
int m;
int query(int x){
	int res=-1;
	while(x<=m){
		res=max(res,tre[x]);x+=x&-x;
	}
	return res;
}
int main(){
	T=read();
	while(T--){
		n=read();for(int i=1;i<=n;++i) a[i]=read();X=read();
		pr[0]=0;
		for(int i=1;i<=n;++i) a[i]-=X,pr[i]=pr[i-1]+a[i],b[i]=pr[i];b[n+1]=0;
		sort(b+1,b+n+2);m=unique(b+1,b+n+2)-b-1;
		// for(int i=0;i<=n;++i) printf("%d ",pr[i]);
		for(int i=0;i<=n;++i) pr[i]=lower_bound(b+1,b+m+1,pr[i])-b;
		for(int i=1;i<=m;++i) tre[i]=-1;
		int ans=0;
		int L=0,R=n+2;
		// for(int i=0;i<=n;++i) printf("%d ",pr[i]);
		for(int i=2;i<=n;++i){
			upd(pr[i-2],i-2);
			int p=query(pr[i]+1);
			if(p!=-1){
				// printf("i:%d,p:%d\n",i,p);
				L=max(L,p+1);R=min(R,i);
				if(L>R){
					++ans;L=p+1,R=i;
				}
			}
		}
		if(L!=0||R!=n+2) ++ans;
		printf("%d\n",n-ans);
	}
}