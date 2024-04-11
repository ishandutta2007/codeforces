#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,i,j,k,a,ans;
int st[100005],top;

int main()
{
	scanf("%d",&n);
	for(;n;--n)
	{
		scanf("%d",&a);
		while(top&&a>st[top])
		{
			if((a^st[top])>ans)ans=a^st[top];
			--top;
		}
		if(top&&(a^st[top])>ans)ans=a^st[top];
		st[++top]=a;
	}
	printf("%d\n",ans);
}