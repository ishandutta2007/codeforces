#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;
const int N=1000005;
int n,m,v;
int a[N];
struct triple
{
	int a,b,c;
};
bool operator < (triple a,triple b)
{
	if (a.a!=b.a)
		return a.a<b.a;
	if (a.b!=b.b)
		return a.b<b.b;
	return a.c<b.c;
}
map <triple,int> s[N];
int cmin(int a,int b,int c)
{
	return min(min(a,b),c);
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&v);
		a[v]++;
	}
	s[3][(triple){a[1],a[2],a[3]}]=0;
	for (int i=3;i<=m+2;i++)
	{
		for (map <triple,int>::iterator it=s[i].begin();it!=s[i].end();it++)
		{
			triple cur=it->first;
			int val=it->second;
			for (int j=min(2,cmin(cur.a,cur.b,cur.c));j>=0;j--)
				s[i+1][(triple){cur.b-j,cur.c-j,a[i+1]}]=
				max(s[i+1][(triple){cur.b-j,cur.c-j,a[i+1]}],
					val+(cur.a-j)/3+j);
		}
	}
	printf("%d\n",s[m+3][(triple){0,0,0}]);
	return 0;
}