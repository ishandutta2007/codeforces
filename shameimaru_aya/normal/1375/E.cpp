#include<bits/stdc++.h>
using namespace std;
struct item
{
	int num , id;
	bool operator < ( const item &x ) const
	{
		if(num == x.num) return id < x.id;
		return num < x.num;
	}
} node[1100];
int n , a[1100] , q[1100] , tot , x[1100000] , y[1100000];
int main()
{
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; i++ ) scanf("%d" , &node[i].num) , node[i].id = i;
	sort(node + 1 , node + n + 1);
	for(int i = 1 ; i <= n ; i++ ) a[node[i].id] = i , q[i] = node[i].id;
	for(int i = n ; i >= 1 ; i-- )
	{
		int u;
		for(int j = 1 ; j <= n ; j++ )
			if(q[j] == i) u = j;
		for(int j = u ; j < i ; j++ )
		{
			swap(q[j] , q[j + 1]);
			x[++tot] = q[j] , y[tot] = q[j + 1];
		}
	}
	printf("%d\n" , tot);
	for(int i = 1 ; i <= tot ; i++ ) printf("%d %d\n" , x[i] , y[i]);
    return 0;
}
/*
*/