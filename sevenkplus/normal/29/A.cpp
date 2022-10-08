#include<cstdio>
#include<algorithm>
using namespace std;
#define N 111
int n,x[N],y[N];bool F=0;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d%d",x+i,y+i);
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			if(x[i]+y[i]==x[j]&&x[j]+y[j]==x[i])F=1;
	puts(F?"YES":"NO");
	return 0;
}