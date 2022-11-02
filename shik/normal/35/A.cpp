// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int a[4]={},x,y;
	scanf("%d",&x); a[x]=1;
	scanf("%d%d",&x,&y); swap(a[x],a[y]);
	scanf("%d%d",&x,&y); swap(a[x],a[y]);
	scanf("%d%d",&x,&y); swap(a[x],a[y]);
	for ( int i=1; i<=3; i++ )
		if ( a[i] ) printf("%d\n",i);
	return 0;
}