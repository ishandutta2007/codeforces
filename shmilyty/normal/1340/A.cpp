#include<bits/stdc++.h>
using namespace std;
int t,n,p;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int cnt=0;
		for(int i=n;n--;i=p)
		{
			scanf("%d",&p);
			cnt|=(p-i>1); 
		}
		if(cnt)
			puts("NO");
		else
			puts("YES"); 
	}
	return 0;
}