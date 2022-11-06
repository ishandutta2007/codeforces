#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
int n,u,v;

int main()
{
	scanf("%d",&n);
	if (n==1){
		printf("YES\n2 1\n1 2\n");
	}
	else if (n%2==0) printf("NO\n");
	else {
		printf("YES\n");
		printf("%d %d\n",2*(n+2),n*(n+2));
		for (int i=1;i<=n/2;i++)
		    for (int j=0;j<n+2;j++)
		    {
		    	u=j;v=(j+i)%(n+2);
		    	printf("%d %d\n",u+1,v+1);
		    	printf("%d %d\n",u+n+3,v+n+3);
		    }
		for (int i=1;i<=n/2+1;i++)
		{
			u=i,v=i+n/2+1;
		    printf("%d %d\n",u+1,v+1);
		    printf("%d %d\n",u+n+3,v+n+3);
		}
		printf("%d %d\n",1,n+3);
	}
	return 0;
}