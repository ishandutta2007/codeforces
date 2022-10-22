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
int n,q;
int a[300010];
int det[300010];
int main(){
	T=read();
	while(T--){
		n=read(),q=read();
		for(int i=1;i<=n;++i) a[i]=read();
		a[n+1]=0;
		long long ans=0;
		for(int i=1;i<=n;++i) det[i]=a[i]-a[i+1];
		for(int i=1;i<=n;++i) ans+=max(0,det[i]);
		printf("%lld\n",ans);
		for(int i=1;i<=q;++i){
			int l=read(),r=read();
			if(l<r-1) ans-=max(0,det[l-1])+max(0,det[l])+max(0,det[r-1])+max(0,det[r]);
			else if(l==r-1) ans-=max(0,det[l-1])+max(0,det[l])+max(0,det[r]);
			else {
				printf("%lld\n",ans);continue ;
			}
			swap(a[l],a[r]);
			if(l>1) det[l-1]=a[l-1]-a[l];
			det[l]=a[l]-a[l+1];
			if(r>1) det[r-1]=a[r-1]-a[r];
			det[r]=a[r]-a[r+1];
			if(l<r-1) ans+=max(0,det[l-1])+max(0,det[l])+max(0,det[r-1])+max(0,det[r]);
			else if(l==r-1) ans+=max(0,det[l-1])+max(0,det[l])+max(0,det[r]);
			printf("%lld\n",ans);
		}
	}
}
//zzakioi