#include <bits/stdc++.h>
using namespace std;
const int B = 450;
int n , m , tot , tim[220000] , x[220000] , y[220000] , t[220000] , s[B + 1][B + 1] , l[B + 10] , d[200020] , opt , k;
void add( int a , int val )
{
	l[a / B] += val;
	d[a] += val;
}
int ask( int a )
{
	int pl = a / B , ans = 0;
	for(int i = 0 ; i < pl ; i++ ) ans += l[i];
	for(int i = pl * B ; i <= a ; i++ ) ans += d[i];
	return ans;
}
void add_s( int t , int x , int val , int st )
{
//	cerr << t << ' ' << x << ' ' << st << endl;
	for(int i = (st - 1) % t + 1 , tot = 1 ; tot <= x ; i = i % t + 1 , tot++ ) s[t][i] += val;
//	cerr << endl;
}
int ask_s( int a )
{
	int ans = 0;
	for(int i = 1 ; i <= B ; i++ ) ans += s[i][(a - 1) % i + 1];
	return ans;
}
int main() 
{
//	freopen("1.in" , "r" , stdin);
	scanf("%d%d" , &n , &m);
	for(int i = 1 ; i <= n ; i++ ) scanf("%d%d" , &x[i] , &y[i]) , t[i] = x[i] + y[i];
	for(int i = 1 ; i <= m ; i++ )
	{
		scanf("%d%d" , &opt , &k);
		if(opt == 1) 
		{
			tim[k] = i; tot++;
			if(t[k] > B) 
			{
				for(int j = i ; j <= m ; j += t[k] )
				{
					add(j , 1); add(min(m + 1 , j + x[k]) , -1);
				}
			}
			else add_s(t[k] , x[k] , 1 , i);
		}
		else
		{
			tot--; 
			if(t[k] > B) 
			{
				for(int j = tim[k] ; j <= m ; j += t[k] )
				{
					add(j , -1); add(min(m + 1 , j + x[k]) , 1);
				}
			}
			else add_s(t[k] , x[k] , -1 , tim[k]);
		}
//		cerr << ask(i) << ' ' << ask_s(i) << endl;
		printf("%d\n" , tot - ask(i) - ask_s(i));
	}
	return 0;
}
/*

*/