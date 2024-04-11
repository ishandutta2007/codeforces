#include<iostream>
#include<algorithm>
#include<cstdio>
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){ if(c=='-') f=-1; c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48); c=getchar();}
	return x*f;
}
int n,h,m,k;
struct node{
	int m,pos;
	bool minus;
}a[100010];
int t[100010];
int ans=0x7f7f7f7f,p,f1,f2;
int head,tail;
bool cmp(node x,node y){
	return x.m<y.m;
}
int opt[100010];
signed main(){
	n=read(),h=read(),m=read(),k=read();
	for(int i=1;i<=n;++i){
		int h1=read();
		a[i].m=read();
		if(a[i].m>=(m>>1)){
			a[i].m-=(m>>1),a[i].minus=1;
		}
		a[i].pos=i;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;++i) t[i]=a[i].m;
	for(int i=1;i<=n;++i){
		if(t[i]>=k){
			int f=upper_bound(t+1,t+n+1,t[i]-k)-t-1;
			if(ans>(i-f-1)){
				ans=i-f-1;
				p=i;
				f1=f;
				f2=-1;
			}
		}
		else{
			int f=upper_bound(t+1,t+n+1,t[i]-k+(m>>1))-t-1;
			if(ans>(i-1+n-f)){
				ans=i-1+n-f;
				p=i;
				f2=f;
				f1=-1;
			}
		} 
	}
	int tim=a[p].m;
	printf("%lld %lld\n",ans,tim);
	int cnt=0;
	if(f1==-1){
		for(int i=1;i<p;++i) opt[++cnt]=a[i].pos;
		for(int i=f2+1;i<=n;++i) opt[++cnt]=a[i].pos;
		sort(opt+1,opt+cnt+1);
		for(int i=1;i<=cnt;++i) printf("%lld ",opt[i]);
		printf("\n");
	}
	else{
		for(int i=f1+1;i<p;++i) opt[++cnt]=a[i].pos;
		sort(opt+1,opt+cnt+1);
		for(int i=1;i<=cnt;++i) printf("%lld ",opt[i]);
		printf("\n");
	}
	return 0;
}