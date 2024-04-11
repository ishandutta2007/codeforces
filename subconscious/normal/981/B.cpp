#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
using namespace std;
const int N=1e5+5;
struct node{int x,y;}a[N<<1];
bool cmp(node x,node y){return x.x<y.x;}
int n,m;long long ans=0;
int main(){
	scanf("%d",&n);
	rep(i,n)scanf("%d%d",&a[i].x,&a[i].y);
	scanf("%d",&m);
	rep(i,m)scanf("%d%d",&a[i+n].x,&a[i+n].y);
	sort(a+1,a+n+m+1,cmp);
	//rep(i,n+m)printf("%d %d\n",a[i].x,a[i].y);
	rep(i,n+m)if(a[i].x!=a[i-1].x){
		if(a[i].x==a[i+1].x)ans+=max(a[i].y,a[i+1].y);
		else ans+=a[i].y;
	}
	printf("%lld\n",ans);
	//system("pause");
	return 0;
}