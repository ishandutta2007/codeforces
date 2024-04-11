#include<bits/stdc++.h>
using namespace std;
struct item
{
	int num , id , rk;
} node[110000];
bool cmp1( item a , item b )
{
	if(a.num == b.num) return a.id < b.id;
	return a.num < b.num;
}
bool cmp2( item a , item b )
{
	return a.id < b.id;
}
int T , n , minn , flag , f[110000];
int main()
{
	scanf("%d" , &T);
	while(T--)
	{
		minn = 2e9; flag = 0;
		scanf("%d" , &n);
		for(int i = 1 ; i <= n ; i++ )
		{
			scanf("%d" , &node[i].num);
			node[i].id = i; minn = min(minn , node[i].num);
		}
		sort(node + 1 , node + n + 1 , cmp1);
		for(int i = 1 ; i <= n ; i++ ) node[i].rk = i;
		sort(node + 1 , node + n + 1 , cmp2);
		for(int i = 1 ; i <= n ; i++ )
		{
			if(__gcd(node[i].num , minn) == minn) f[i] = 1;
			else f[i] = 0;
		}
		for(int i = 1 ; i <= n ; i++ )
		{
			if(node[i].rk == i) continue;
			int qwq = node[i].rk;
			if(f[i] && f[qwq]) swap(node[i] , node[qwq]);
			else
			{
				flag = 1;
				break;
			}
		}
		if(!flag) printf("YES\n");
		else printf("NO\n");
	}
    return 0;
}