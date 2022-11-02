#include<bits/stdc++.h>
using namespace std;
int T , n , a[110];
priority_queue< int > q;
int main()
{
	scanf("%d" , &T);
	while(T--)
	{
		scanf("%d" , &n);
		for(int i = 1 ; i <= n ; i++ ) scanf("%d" , &a[i]) , q.push(a[i]);
		while(!q.empty())
		{
			int x = q.top(); q.pop(); x--;
			if(q.empty())
			{
				printf("T\n");
				break;
			}
			int y = q.top(); q.pop(); y--;
			if(x) q.push(x);
			if(q.empty())
			{
				printf("HL\n");
				break;
			}
			if(y) q.push(y);
		}
	}
    return 0;
}