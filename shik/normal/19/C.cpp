// by shik
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
#define H 124567
using namespace std;
int a[100010],x[100010],s[100010],h[18][100010],y[100010];
map<int,vector<int> > app;
vector<int>::iterator it;
int mat( int p1, int p2, int len ) {
	//printf("mat(%d,%d,%d)\n",p1,p2,len);
	if ( len==0 ) return 1;
	int k=__lg(len);
	if ( h[k][p1]!=h[k][p2] || s[p1+len-1]-s[p1-1]!=s[p2+len-1]-s[p2-1] || (x[p1+len-1]^x[p1-1])!=(x[p2+len-1]^x[p2-1]) ) return 0;
	else return mat(p1+(1<<k),p2+(1<<k),len-(1<<k));
}
int main()
{
	int n,i,j,st=1,L;
	scanf("%d",&n);
	for ( i=1; i<=n; i++ ) {
		scanf("%d",a+i);
		x[i]=x[i-1]^a[i];
		s[i]=s[i-1]+a[i];
		h[0][i]=a[i];
		app[a[i]].push_back(i);
	}
	y[1]=1;
	for ( i=2; i<=n; i++ ) y[i]=y[i-1]*H;
	for ( i=1; (L=(1<<i))<=n; i++ )
		for ( j=1; j+L-1<=n; j++ )
			h[i][j]=h[i-1][j]*y[L]+h[i-1][j+L/2];
	for ( i=1; i<=n; i++ ) {
		//printf("(%d,%d)\n",i,st);
		if ( i<st ) i=st;
		for ( it=app[a[i]].begin(); it!=app[a[i]].end(); it++ ) {
		//	printf("now %d\n",*it);
			if ( *it>i && *it+*it-i-1<=n && mat(i,*it,*it-i) ) st=*it;
		}
	}
	//printf("st=%d\n",st);
	printf("%d\n",n-st+1);
	for ( i=st; i<=n; i++ ) printf("%d%c",a[i],i==n?'\n':' ');
	return 0;
}
//abcab abcab
//abcabcab
//abcab
//sum xor