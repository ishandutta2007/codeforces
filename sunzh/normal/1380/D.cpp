#include<iostream>
#include<cstdio>
#include<algorithm>
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){ if(c=='-') f=-1; c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48); c=getchar();}
	return x*f;
}
int n,m;
int x,k,y;
int a[200010],b[200010];
int lft[200010],rgt[200010];
int pos[200010];
int cnt;
long long ans;
signed main(){
	n=read(),m=read();
	x=read(),k=read(),y=read();
	for(int i=1;i<=n;++i) a[i]=read(),pos[a[i]]=i;
	for(int i=1;i<=m;++i) b[i]=read();
	int lst=0;
	for(int i=1;i<=m;++i){
		if(pos[b[i]]>lst){
			lft[++cnt]=lst+1;
			rgt[cnt]=pos[b[i]]-1;
			if(lft[cnt]>rgt[cnt]) --cnt; 
			lst=pos[b[i]];
		}
		else {
			printf("-1\n");
			return 0; 
		}
	}
	if(lst<n) lft[++cnt]=lst+1,rgt[cnt]=n;
	for(int i=1;i<=cnt;++i){
		int maxn=0,l=a[lft[i]-1],r=a[rgt[i]+1],len=rgt[i]-lft[i]+1;
		for(int j=lft[i];j<=rgt[i];++j) maxn=max(maxn,a[j]);
		if(len<k&&l<maxn&&r<maxn){
			printf("-1\n");
			return 0;
		}
		if(x<=y*k) ans=ans+(len/k)*x+(len%k)*y;
		else{
			if(l>maxn||r>maxn) ans=ans+y*len;
			else{
				ans=ans+y*(len-k)+x;
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}