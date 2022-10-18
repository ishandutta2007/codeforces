#include<bits/stdc++.h>
using namespace std;
int a[100];
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		for(int i = 0; i < n; i++)
		{		
			scanf("%d", &a[i]);
		}
		set<int> s;
		for(int i = 0; i < n; i++) for(int j = i + 1; j < n; j++)
		{
			if(a[i]!=a[j])s.insert(abs(a[i] - a[j]));
		}	
		printf("%d\n", (int)s.size());
	}

	return 0;
 }