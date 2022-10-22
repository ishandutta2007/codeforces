#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){ if(c=='-') f=-1; c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48); c=getchar();}
	return x*f;
}
struct node{
	int a,b;
}num[100010],a[100010];
int pos[100010];
int sum[100010];
int T;
int n,m;
int ans;
bool cmp(node x,node y){
	return x.a>y.a;
}
int binary_search(int x){
	int l=1,r=m;
	while(l<=r){
		int mid=l+r>>1;
		if(a[mid].a<x) r=mid-1;
		else if(a[mid].a==x||(a[mid].a>x&&a[mid+1].a<=x)) return mid;
		else l=mid+1; 
	}
}
signed main(){
	T=read();
	while(T--){
		memset(sum,0,sizeof(sum));
		memset(num,0,sizeof(num));
		ans=0;
		n=read(),m=read();
		for(int i=1;i<=m;++i){
			num[i].a=a[i].a=read();
			a[i].b=i;
			num[i].b=read();
		}
		sort(a+1,a+m+1,cmp);
		for(int i=1;i<=m;++i){
			pos[a[i].b]=i;
			sum[i]=sum[i-1]+a[i].a;
		}
		for(int i=1;i<=m;++i){
			int p=binary_search(num[i].b);
			if(p>=n) ans=max(ans,sum[n]);
			else {
				ans=max(ans,sum[p]+(n-p-(pos[i]<=p?0:1))*num[i].b+(pos[i]<=p?0:num[i].a));
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}