// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 100010
using namespace std;
struct P {
	int id,w;
	P( int _id=0, int _w=0 ):id(_id),w(_w){}
} p1[N],p2[N];
bool cp( P a, P b ) { return a.w>b.w; }
int w[N],sol[N];
int main()
{
	int n,m,v,i,j,n1=0,n2=0,ans=0,w1,w2,last=-1;
	scanf("%d%d",&n,&m);
	for ( i=1; i<=n; i++ ) {
		scanf("%d%d",&v,w+i);
		if ( v==1 ) p1[n1++]=P(i,w[i]);
		else if ( v==2 ) p2[n2++]=P(i,w[i]);
		else puts("QQ");
	}
	sort(p1,p1+n1,cp);
	sort(p2,p2+n2,cp);
	i=j=0;
	while ( m>0 ) {
		w1=w2=-1;
		if ( i<n1 ) w1=p1[i].w;
		if ( i>0 && j<n2 ) w2=p2[j].w-p1[i-1].w;
		if ( w1==-1 && w2==-1 ) break;
		m--;
		if ( w1>w2 ) {
			sol[p1[i++].id]=1;
		} else {
			sol[p1[--i].id]=0;
			sol[p2[j++].id]=1;
		}
	}
	while ( m>=2 && j<n2 ) {
		m--;
		sol[p2[j++].id]=1;
	}
	for ( i=1; i<=n; i++ )
		if ( sol[i] ) {
			ans+=w[i];
			last=i;
		}
	printf("%d\n",ans);
	for ( i=1; i<=n; i++ )
		if ( sol[i] ) printf("%d%c",i,i==last?'\n':' ');
	return 0;
}