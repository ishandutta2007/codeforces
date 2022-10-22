#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){	if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)) {x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
int n;
int step=0;
char stra[100010],strb[100010];
int a[100010],b[100010];
long long odd,ou;
inline long long aabs(long long x){ return x<0?-x:x;}
void dfs(int x,int k){
	if(a[x+1]+k<=9&&a[x+1]+k>=0){
		a[x+1]+=k;a[x]+=k;++step;if(step<=1e5)printf("%d %d\n",x,k);
	}
	else {
		while(a[x+1]+k>9){
			dfs(x+1,-1);
		}
		while(a[x+1]+k<0){
			dfs(x+1,1);
		}
		a[x]+=k;a[x+1]+=k;++step;if(step<=1e5)printf("%d %d\n",x,k); 
	}
}
void solve(int x){
	if(step>1e5) return ;
	while(a[x]-b[x]!=0){
		if(a[x]-b[x]>0){
			dfs(x,-1);
		}
		else dfs(x,1);
//		for(int i=1;i<=n;++i) printf("%d ",a[i]);putchar('\n');
		if(step>1e5) return ;
	}
}
int main(){
	n=read();
	scanf("%s",stra+1);scanf("%s",strb+1);
	for(int i=1;i<=n;++i){
		a[i]=stra[i]-'0';b[i]=strb[i]-'0';
		if(i&1) odd+=a[i]-b[i];
		else ou+=a[i]-b[i];
	}
	if(odd!=ou) {
		printf("-1\n");return 0;
	}
	long long ans=0;
	for(int i=1;i<=n;++i){
		long long det=b[i]-a[i];
		a[i+1]+=det;
		ans+=aabs(det);
	}
	if(a[n+1]!=0){
		printf("-1\n");return 0;
	}
	for(int i=1;i<=n;++i) a[i]=stra[i]-'0';
	printf("%lld\n",ans);
	for(int i=1;i<n;++i) solve(i);
	return 0;
}