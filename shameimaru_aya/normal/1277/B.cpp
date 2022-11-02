#include<bits/stdc++.h>
using namespace std;
int T , n , a , ans , las;
priority_queue< int > q;
int main()
{
	scanf("%d" , &T);
	while(T--)
	{
		ans = las = 0;
		scanf("%d" , &n);
		for(int i = 1 ; i <= n ; i++ )
		{
			scanf("%d" , &a);
			if(a % 2 == 0) q.push(a);
		}
		while(!q.empty())
		{
			a = q.top();
			q.pop();
			if(a == las)
			{
				if(a % 4 == 0) q.push(a >> 1);
			}
			else
			{
				if(a % 4 == 0)
				{
					q.push(a >> 1);
				}
				las = a;
				ans++;
			}
		}
		printf("%d\n" , ans);
	}
	return 0;
}