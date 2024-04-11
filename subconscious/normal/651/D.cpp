#include <algorithm>
#include <cstdio>
#define rep(i,n) for(int i=1;i<=n;++i)
#define N 500005
using namespace std;
int q[N],n,a,b,T,ans=0;char c;
int main(){
	scanf("%d%d%d%d",&n,&a,&b,&T);c=getchar();
	rep(i,n){c=getchar();if(c=='w')q[i]=q[i-1]+1+b;else q[i]=q[i-1]+1;}
	if(T<q[1]){puts("0");return 0;}ans=1;
	if(T>=q[n]+a*(n-1)){printf("%d\n",n);return 0;}
	int x=1,y=2,w=q[n]+a*(n-1);
	while(x-1<n-y+1){
		while(w>T&&y<=n)w-=a+q[y]-q[y-1],++y;
		if(w>T)break;
		ans=max(ans,x+n-y+1);
		++x,w+=2*a+q[x]-q[x-1];
	}
	x=0;while(x+1<=n&&(q[x+1]+a*x<=T))++x;
	ans=max(ans,x);
	x=n-1,y=n,w=q[n]+a*n;
	while(n-y+1<=x-1){
		while(w>T&&x>1)w-=a+q[x]-q[x-1],--x;
		if(w>T)break;
		ans=max(ans,x+n-y+1);
		--y,w+=2*a+q[y]-q[y-1];
	}
	printf("%d\n",ans);
	return 0;
}