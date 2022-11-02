#include<bits/stdc++.h>
using namespace std;
int n , m , q , x;
string a[100] , b[100];
int main()
{
	scanf("%d%d" , &n , &m);
	for(int i = 1 ; i <= n ; i++ )
	{
		cin >> a[i];
	}
	for(int i = 1 ; i <= m ; i++ )
	{
		cin >> b[i];
	}
	scanf("%d" , &q);
	for(int i = 1 ; i <= q ; i++ )
	{
		scanf("%d" , &x);
		cout << a[(x - 1) % n + 1] << b[(x - 1) % m + 1] << endl;
	}
	return 0;
}