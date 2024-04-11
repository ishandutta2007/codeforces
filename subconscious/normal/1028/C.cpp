#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
using namespace std;
const int N=2e5+5,P=1e9+7;
typedef long double ld;
typedef long long ll;
int n;
struct mi{
	int a[N],ua[N],va[N];
	void init(){
		ua[0]=va[n+1]=-1e9-1;
		rep(i,n)ua[i]=max(ua[i-1],a[i]);
		for(int i=n;i;--i)va[i]=max(va[i+1],a[i]);
	}
	int que(int x){
		return max(ua[x-1],va[x+1]);
	}
}X1,Y1;
struct ma{
	int a[N],ua[N],va[N];
	void init(){
		ua[0]=va[n+1]=1e9+1;
		rep(i,n)ua[i]=min(ua[i-1],a[i]);
		for(int i=n;i;--i)va[i]=min(va[i+1],a[i]);
	}
	int que(int x){
		return min(ua[x-1],va[x+1]);
	}
}X2,Y2;
int main(){
	scanf("%d",&n);
	rep(i,n)scanf("%d%d%d%d",&X1.a[i],&Y1.a[i],&X2.a[i],&Y2.a[i]);
	X1.init();Y1.init();X2.init();Y2.init();
	rep(i,n){
		int UX=X1.que(i),VX=X2.que(i),UY=Y1.que(i),VY=Y2.que(i);
		//printf("%d %d %d %d\n",UX,VX,UY,VY);
		if(UX<=VX&&UY<=VY){printf("%d %d\n",UX,UY);return 0;}
	}
	return 0;
}