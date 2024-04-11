#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int a[123];
int n;
int sumof=0,cnt=0;
int l[123],r[123],L=0;
bool zero=true;

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	scanf("%d",&n);
	l[0]=1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i])zero=false;
		sumof+=a[i];
		if(!zero&&!sumof)
		{
			r[L++]=i-1;
			l[L]=i;
			sumof+=a[i];
		}
	}
	if(!zero)
	{
		r[L++]=n;
	}
	else return puts("NO"),0;
	
	for(int i=l[L-1];i<=r[L-1];i++)
	{
		if(a[i]!=0)zero=true;
	}
	if(!zero)
	{
		L--;
		r[L]=n-1;
	}
	puts("YES");
	printf("%d\n",L);
	for(int i=0;i<L;i++)
		printf("%d %d\n",l[i],r[i]);
	return 0;
}