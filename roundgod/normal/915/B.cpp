#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
int n,pos,l,r;
int main()
{
	scanf("%d%d%d%d",&n,&pos,&l,&r);
	if(l==1&&r==n)
		printf("0\n");
	else if(l==1)
		printf("%d\n",max(pos-r,r-pos)+1);
	else if(r==n)
		printf("%d\n",max(pos-l,l-pos)+1);
	else
		printf("%d\n",min(max(pos-l,l-pos)+r-l,max(pos-r,r-pos)+r-l)+2);
	return 0;
}