#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define maxn 20000

using namespace std;

int a[maxn],b[maxn],n; 
bool f,g;

int main()
{
	f=true;g=true;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
	    scanf("%d%d",&a[i],&b[i]);
	    if (a[i]!=b[i]) f=false;
	    if (i>1&&a[i]>a[i-1]) g=false;
	}
	if (f&&g) printf("maybe\n");
	else if (f) printf("unrated\n");
	else printf("rated\n");
	return 0;
}