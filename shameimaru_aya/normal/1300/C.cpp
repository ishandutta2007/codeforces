#include<bits/stdc++.h>
using namespace std;
struct item
{
	int id , num;
	bool operator < ( const item &x ) const
	{
		return num > x.num;
	}
} node[300000];
int n , p[50] , s;
int main()
{
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; i++ )
	{
		scanf("%d" , &node[i].id); node[i].num = node[i].id;
		int v = node[i].id , s = 0;
		while(v)
		{
			p[s] += (v & 1);
			v >>= 1;
			s++;
		}
	}
	for(int i = 0 ; i <= 30 ; i++ )
	{
		if(p[i] == 1) s += 1 << i;
	}
	for(int i = 1 ; i <= n ; i++ )
	{
		node[i].num &= s;
	}
	sort(node + 1 , node + n + 1);
	for(int i = 1 ; i <= n ; i++ ) printf("%d " , node[i].id);
	return 0;
}
//2 3 4 5 8 13 13 16 17 20