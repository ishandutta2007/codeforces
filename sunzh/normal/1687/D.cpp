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
#define int long long
#define pb push_back
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==-1?~x+1:x;
}
int n;
const int mxn=2e6;
int a[1000010];
int pr[2000010],nx[2000010];
int getpr(int x,int dw){
	int y=min(x,mxn);
	return a[pr[y]]>=dw?a[pr[y]]:0;
}
int getnx(int x,int up){
	return x>mxn?up:(a[nx[x]]<up?a[nx[x]]:up);
}
signed main(){
	n=read();
	for(int i=1;i<=n;++i) a[i]=read();
	int it=0;
	for(int i=1;i<=mxn;++i){
		while(a[it+1]==i) ++it;
		pr[i]=it;
	}
	a[n+1]=1e18;
	it=n+1;
	for(int i=mxn;i;--i){
		while(a[it-1]==i) --it;
		nx[i]=it;
	}
	for(int i=1;i<=mxn;++i) if(a[1]<=i*(i+1)){
		int mx=i*(i+1)-a[1];
		int mn=max(0ll,i*i-a[1]),M=max(0ll,i*i-a[1]);
		bool f=0;
		// if(mn<=3999996000000&&mx>=3999996000000) f=1;
		// printf("%d %d\n",mn,mx);
		// int p=1;
		int w=i;
		while(1){
			int L=w*w,R=w*(w+1);
			// printf("w:%d,L:%d,R:%d\n",w,L,R);
			if(L-mx-a[1]-mxn>mxn) break ;
			// printf("%d %d\n",getpr(R-mn,L-mn),getnx(R-mn+1,(w+1)*(w+1)-mn));
			mx=min(mx,R-getpr(R-M,L-M));
			mn=max(mn,(w+1)*(w+1)-getnx(R-M+1,(w+1)*(w+1)-M));
			// if(mn==4000002000001){
			// 	printf("w:%lld,getnx:%lld\n",w,getnx1(R-M+1,(w+1)*(w+1)-M));
			// }
			++w;
		}
		// if(f) printf("%lld %lld\n",mn,mx);
		// printf("%d %d\n",mn,mx);
		if(mn<=mx){
			printf("%lld\n",mn);break ;
		}
	}
}