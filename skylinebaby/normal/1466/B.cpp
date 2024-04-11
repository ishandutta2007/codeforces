#include<bits/stdc++.h>
using namespace std;
int a[112345];
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		
		set<int> s;
		for(int i = 0; i < n; i++)
		{		
			scanf("%d", &a[i]);
			if(i)
			{
				if(a[i] <= a[i-1]) a[i]++;
			}
			s.insert(a[i]);
		}
		printf("%d\n", (int)s.size());
	}

	return 0;
 }