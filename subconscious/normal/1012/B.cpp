#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
typedef long double ld;
const int N=2e5+5;
struct node{int x,y;}a[N];
int n,m,q;
bool cmp(node x,node y){return x.y==y.y?x.x<y.x:x.y<y.y;}
int f[N<<1];bool is[N<<1];
int fa(int x){return f[x]==x?x:f[x]=fa(f[x]);}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	rep(i,q)scanf("%d%d",&a[i].x,&a[i].y);
	sort(a+1,a+q+1,cmp);
	rep(i,n+m)f[i]=i;
	rep(i,q){
		int x=fa(a[i].x),y=fa(a[i].y+n);
		f[x]=y;
	}
	int ans=-1;
	rep(i,n+m){
		int x=fa(i);
		if(!is[x])++ans,is[x]=1;
	}
	printf("%d\n",ans);
	//system("pause");
	return 0;
}