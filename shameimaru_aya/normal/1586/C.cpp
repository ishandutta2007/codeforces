#include <bits/stdc++.h>
using namespace std;
int T , n , m , mp[1100000] , L[1100000] , vis[1100000] , fl[1100000] , fu[1100000] , x , y;
int st[22][1100000] , f[1100000] , ok[1100000];
int fx[2] = {0 , -1} , fy[2] = {-1 , 0};
char ch[1100000];
queue< int > q;
int id( int x , int y )
{
	return (x - 1) * m + y;
}
int ask( int l , int r )
{
	int k = log2(r - l + 1);
	return max(st[k][l] , st[k][r - (1 << k) + 1]);
}
int main()
{
	memset(mp , 0x7f / 3 , sizeof(mp));
	scanf("%d%d" , &n , &m);
	for(int i = 1 ; i <= n ; i++ )
	{
		scanf("%s" , ch);
		for(int j = 1 ; j <= m ; j++ )
		{
			mp[id(i , j)] = (ch[j - 1] == '.');
		}
	}
	for(int i = 2 ; i <= n ; i++ )
	{
		for(int j = 2 ; j <= m ; j++ )
		{
			if(((!mp[id(i - 1 , j)]) && (!mp[id(i , j - 1)]))) 
			{
//				cerr << i << ' ' << j << endl;
				L[j] = j - 1;
			}
		}
	}
	for(int i = 1 ; i <= m ; i++ ) st[0][i] = L[i];
	for(int i = 1 ; i <= 20 ; i++ )
		for(int j = 1 ; j + (1 << (i - 1)) <= m ; j++ ) 
			st[i][j] = max(st[i - 1][j] , st[i - 1][j + (1 << (i - 1))]);
	scanf("%d" , &T);
	while(T--)
	{
		scanf("%d%d" , &x , &y);
		if(ask(x , y) >= x) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}
/*
5 4
X...
.X..
.X..
.X.X
.XX.
4
1 3
2 4
3 3
4 4
*/