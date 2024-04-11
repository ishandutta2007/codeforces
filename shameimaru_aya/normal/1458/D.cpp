#include <bits/stdc++.h>
using namespace std;
int T , sum[550000] , e[1100000];
string s;
void dfs( int u )
{
//	cerr << u << ' ' << e[u] << ' ' << e[u + 1] << endl;
//	system("pause");
	if((!e[u + 1] || e[u] >= 2) && e[u])
	{
		e[u]--; printf("0"); dfs(u - 1);
		return ;
	}
	if(e[u + 1])
	{
		e[u + 1]-- , printf("1") , dfs(u + 1);
		return ;
	}
	if(e[u])
	{
		e[u]-- , printf("0") , dfs(u);
		return ;
	}
}
int main()
{
	scanf("%d" , &T);
	while(T--)
	{
		cin >> s;
		for(int i = 0 ; i < s.size() ; i++ )
			sum[i + 1] = sum[i] + (s[i] == '1' ? 1 : -1) , e[max(sum[i] , sum[i + 1]) + 500000]++;
		dfs(5e5);
		printf("\n");
	}
	return 0;
}
/*
5 6
3 1 1 3 3 3
*/