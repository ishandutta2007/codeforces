#include<bits/stdc++.h>
using namespace std;


int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		int mn = 1123456789;
		int mx = 0;
		int a1;
		int a2;
		for(int i = 0; i < n; i++)
		{		
			int x;	
			scanf("%d", &x);
			if(x < mn)
			{
				mn = x;
				a1 = i;
			}
			if(x > mx)
			{
				mx = x;
				a2 = i;
			}
		}
		printf("%d %d\n", a1 + 1, a2 + 1);
	}
	return 0;
}