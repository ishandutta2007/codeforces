#include<bits/stdc++.h>
using namespace std;
int n,q,a,four,two,num[100001];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a);
		num[a]++;
		if(num[a]%4==0)
			four++;
		if(num[a]%2==0)
			two++;
	}
	scanf("%d",&q);
	while(q--)
	{
		char opt;
		scanf("%s %d",&opt,&a);
		switch(opt)
		{
			case '+':{
				num[a]++;
				if(num[a]%4==0)
					four++;
				if(num[a]%2==0)
					two++; 
				break;
			}
			case '-':{
				num[a]--;
				if(num[a]%4==3)
					four--;
				if(num[a]%2==1)
					two--;
				break;
			}
		}
		if(four&&two>=4)
			puts("Yes");
		else
			puts("No");
	}
	return 0;
}