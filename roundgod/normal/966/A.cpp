#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,t1,t2,v,q;
int a[MAXN],b[MAXN];
int abx(int x) {return max(-x,x);}
int main()
{
	scanf("%d%d%d%d%d",&n,&m,&t1,&t2,&v);
	for(int i=0;i<t1;i++) scanf("%d",&a[i]);
	a[t1]=m+1;
	for(int i=0;i<t2;i++) scanf("%d",&b[i]);
	b[t2]=m+1;
	scanf("%d",&q);
	for(int i=0;i<q;i++)
	{
		int x1,y1,x2,y2,ans=INF;
		scanf("%d%d%d%d",&y1,&x1,&y2,&x2);
		if(y1==y2) {printf("%d\n",abx(x1-x2)); continue;}
		int id=lower_bound(a,a+t1+1,x1)-a;
		if(id!=t1) ans=min(ans,abx(a[id]-x1)+abx(a[id]-x2)+abx(y1-y2));
		if(id!=0) ans=min(ans,abx(a[id-1]-x1)+abx(a[id-1]-x2)+abx(y1-y2));
		id=lower_bound(b,b+t2+1,x1)-b;
		if(id!=t2) ans=min(ans,abx(b[id]-x1)+abx(b[id]-x2)+(abx(y1-y2)-1)/v+1);
		if(id!=0) ans=min(ans,abx(b[id-1]-x1)+abx(b[id-1]-x2)+(abx(y1-y2)-1)/v+1);
		printf("%d\n",ans);
	}
	return 0;
}