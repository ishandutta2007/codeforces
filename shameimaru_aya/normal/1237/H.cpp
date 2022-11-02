#include<bits/stdc++.h>
#define lowbit(x) (x & (-x))
using namespace std;
int T , n , rev[4] = {0 , 2 , 1 , 3} , tot[2][4] , a[2][4400];
int ans[4400] , cnt , bl[2][4400] , d , rg , c[4400];
string s , t;
queue< int > q[4];
inline void opr( int r , int f )
{
	int l = 1;
	if(!f) ans[++cnt] = r * 2;
	while(l < r)
	{
		swap(a[f][l] , a[f][r]);
		a[f][l] = rev[a[f][l]] , a[f][r] = rev[a[f][r]];
		l++ , r--;
	}
	if(l == r) a[f][l] = rev[a[f][l]];
	return ;
}
inline void add( int x , int a )
{
	x = n + 1 - x;
	while(x <= n)
	{
		c[x] += a;
		x += lowbit(x);
	}
	return ;
}
inline int ask( int x )
{
	x = n + 1 - x;
	int ans = 0;
	while(x)
	{
		ans += c[x];
		x -= lowbit(x);
	}
	return ans;
}
int main()
{
	scanf("%d" , &T);
	while(T--)
	{
		memset(tot , 0 , sizeof(tot)); memset(c , 0 , sizeof(c)); cnt = 0;
		cin >> s >> t; n = s.size() - 1; rg = 0;
		q[0] = queue< int >(); q[1] = queue< int >(); 
		q[2] = queue< int >(); q[3] = queue< int >(); 
		for(int i = 0 ; i <= n ; i += 2 )
		{
			a[0][i / 2 + 1] = ((s[i] - '0') << 1) + (s[i + 1] - '0');
			tot[0][a[0][i / 2 + 1]]++ , bl[0][i / 2 + 1] = tot[0][1] - tot[0][2];
		}
		for(int i = 0 ; i <= n ; i += 2 )
		{
			a[1][i / 2 + 1] = ((t[i] - '0') << 1) + (t[i + 1] - '0');
			tot[1][a[1][i / 2 + 1]]++ , bl[1][i / 2 + 1] = tot[1][1] - tot[1][2];
		}
		if(tot[0][0] != tot[1][0] || tot[0][3] != tot[1][3]) 
		{
			printf("-1\n");
			continue;
		}
		n = n / 2 + 1; d = (bl[0][n] + bl[1][n]) / 2;
		if(abs(bl[0][n]) >= abs(bl[1][n]))
		{
			for(int i = 1 ; i <= n ; i++ )
			{
				if(bl[0][i] == d)
				{
					opr(i , 0);
					break;
				}
			}
		}
		else
		{
			for(int i = 1 ; i <= n ; i++ )
			{
				if(bl[1][i] == d)
				{
					opr(i , 1); rg = i;
					break;
				}
			}
		}
		for(int i = 1 ; i <= n ; i++ ) q[a[0][i]].push(i);
		for(int i = n ; i >= 1 ; i-- )
		{
			int u = q[rev[a[1][i]]].front() , o = u; q[rev[a[1][i]]].pop();
			u += ask(u);
//			cerr << u << endl;
			if(u != 1) opr(u - 1 , 0); 
			opr(u , 0);
			add(o , 1);
		}
		if(abs(bl[0][n]) < abs(bl[1][n])) opr(rg , 0);
		printf("%d\n" , cnt);
		for(int i = 1 ; i <= cnt ; i++ ) printf("%d " , ans[i]);
		printf("\n");
	}
	return 0;
}
/*
*/