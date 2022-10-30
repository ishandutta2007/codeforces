#include <bits/stdc++.h>
using namespace std;
int T , n , a , b , c , x , y , z , t , it;
long long ans;
char s[330000];
struct item
{
	int len , tp;
	bool operator < ( const item &x ) const
	{
		if(tp == x.tp) return len < x.len;
		return tp < x.tp;
	}
} node[330000];
void solve( int u , int x , int y , int z , int zf , long long s )
{
	ans = max(ans , s);
	if(!u)
	{
		if(y) solve(u ^ 1 , x , y - 1 , z , zf , s + b);
		else return ;
	}
	else
	{
		int las = it;
		while(node[it].len == 1 && it <= t) 
		{
			if(!node[it].tp) z++;
			else zf++;
			it++;
		}
//		cerr << x << ' ' << y << ' ' << z << ' ' << zf << ' ' << s << endl;
		if(x && y)
		{
			node[it].len--; solve(u ^ 1 , x - 1 , y , z , zf , s + a);
			node[it].len++; it = las;
			return ;
		}
		if(x) ans = max(ans , s + a);
		if(z)
		{
			solve(u ^ 1 , x , y + 1 , z - 1 , zf , s - c); it = las;
			return ;
		}
		if(zf)
		{
			solve(u ^ 1 , x , y , z , zf - 1 , s - c); it = las;
			return ;
		}
		return ;
	}
} 
int main()
{
//	freopen("1.in" , "r" , stdin);
//	freopen("1.out" , "w" , stdout);
	scanf("%d" , &T);
	for(int ttt = 1 ; ttt <= T ; ttt++ )
	{
		scanf("%d%d%d%d%s" , &n , &a , &b , &c , s + 1); x = y = z = t = ans = 0;
//		if(ttt == 7158 && T == 10000 && n != 4) 
//		{
//			cout << n << '.' << a << '.' << b << '.' << c << '.';
//			printf("%s\n" , s + 1);
//			continue;
//		}
		int las = 1;
		for(int i = 1 ; i <= n ; i++ )
		{
			if(s[i] != s[las])
			{
				if(s[las] == '0') node[++t] = (item){i - las , las == 1} , x += i - las - 1;
				else y += i - las - 1;
				las = i;
			}
		}
		if(s[las] == '0') node[++t] = (item){n + 1 - las , 1} , x += n - las;
		else y += n - las;
		sort(node + 1 , node + t + 1);
		it = 1;
		solve(0 , x , y , 0 , 0 , 0);
		solve(1 , x , y , 0 , 0 , 0);
		printf("%lld\n" , ans);
	}
	return 0;
}
/*
1
5 100000000 200000000 100000000
00101
*/