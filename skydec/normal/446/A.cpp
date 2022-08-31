#include<stdio.h>
#define MAXN 110000
using namespace std;
int fr[MAXN],be[MAXN],data[MAXN];
int n;
void MAX(int &x,int y)
{
	if(y>x)x=y;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&data[i]);
	fr[1]=1;
	for(int i=2;i<=n;i++)
	if(data[i]>data[i-1])fr[i]=fr[i-1]+1;else fr[i]=1;
	be[n]=1;
	for(int i=n-1;i>=1;i--)
	if(data[i]<data[i+1])be[i]=be[i+1]+1;else be[i]=1;
	int ans=1;
	MAX(ans,fr[n-1]+1);
	MAX(ans,be[2]+1);
	for(int i=2;i<n;i++)
	{
		if(data[i+1]-data[i-1]>=2)
		MAX(ans,fr[i-1]+be[i+1]+1);
		else
		{
			MAX(ans,fr[i-1]+1);
			MAX(ans,be[i+1]+1);
		}
	}
	printf("%d\n",ans);
	return 0;
}