#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,k;
char s[N];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%s",&n,&k,s+1);
		int f=1;
		for(int i=1,j=n;i<j;i++,j--)
			if(s[i]!=s[j])
				f=0;
		if(f||!k)
			puts("1");
		else
			puts("2");
	}
	return 0;
}