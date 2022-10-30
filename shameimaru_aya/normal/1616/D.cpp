#include <bits/stdc++.h> 
#define lson (id << 1)
#define rson (id << 1 | 1)
using namespace std;
int T , n , m , a[55000] , l[55000] , it , dp[55000];
long long s[55000];
priority_queue< long long > q , del;
int main()
{
//	freopen("1.in" , "r" , stdin);
//	freopen("1.out" , "w" , stdout);
	scanf("%d" , &T);
	while(T--)
	{
		memset(dp , 0 , sizeof(dp));
		scanf("%d" , &n); 
		for(int i = 1 ; i <= n ; i++ ) scanf("%d" , &a[i]);
		scanf("%d" , &m);
		for(int i = 1 ; i <= n ; i++ ) s[i] = s[i - 1] + a[i] - m;
		l[1] = 1; it = 1; q.push(0); 
		for(int i = 2 ; i <= n ; i++ )
		{
			while(1)
			{
				while(!del.empty())
				{
					if(del.top() == q.top()) del.pop() , q.pop();
					else break;
				}
				if(q.empty() || (q.top() <= s[i])) 
				{
					l[i] = it;
					q.push(s[i - 1]);
					break;
				}
				else del.push(s[it - 1]) , it++;
			}
//			cerr << l[i] << ' ';
		}
//		cerr << endl;
		dp[1] = 1;
		for(int i = 2 ; i <= n ; i++ )
		{
			dp[i] = max(dp[i - 1] , dp[i - 2] + 1);
			int qwq = (i - l[i] + 1);
			if(l[i] >= 2) qwq += dp[l[i] - 2];
			dp[i] = max(dp[i] , qwq);
		}
		printf("%d\n" , dp[n]);
		while(!del.empty()) del.pop();
		while(!q.empty()) q.pop();
	}
    return 0;
} 
/*
*/