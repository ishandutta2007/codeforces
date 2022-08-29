#include <algorithm>
#include <iostream>
#include <cstdio>
#define rep(i,n) for(int i=1;i<=n;++i)
#define N 200005
using namespace std;
typedef long long ll;
struct node{int x,y,k;}a[N];
struct line{int x,y;}b[N];
int n;ll ans=0;
bool cmp_x(node x,node y){return x.x<y.x||x.x==y.x&&x.y<y.y;}
bool cmp_y(node x,node y){return x.y<y.y;}
int main(){
	scanf("%d",&n);
	rep(i,n)scanf("%d%d",&a[i].x,&a[i].y),a[i].k=i;
	sort(a+1,a+n+1,cmp_x);ll p=0;
	rep(i,n-1){
		if(a[i].x==a[i+1].x&&a[i].y==a[i+1].y)++p;
		else ans-=p*(p+1)/2,p=0;
	}
	ans-=p*(p+1)/2;p=0;
	rep(i,n-1)if(a[i].x==a[i+1].x)++p;
	else ans+=p*(p+1)/2,p=0;
	ans+=p*(p+1)/2;p=0;
	sort(a+1,a+n+1,cmp_y);
	rep(i,n-1)if(a[i].y==a[i+1].y)++p;else ans+=p*(p+1)/2,p=0;
	ans+=p*(p+1)/2;p=0;
	cout<<ans<<endl;
	return 0;
}