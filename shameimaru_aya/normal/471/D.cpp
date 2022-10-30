#include <bits/stdc++.h>
using namespace std;
int n , m , a[220000] , b[220000] , kmp[220000] , it , ans;
int main()
{
	scanf("%d%d" , &n , &m);
	for(int i = 1 ; i <= n ; i++ ) scanf("%d" , &a[i]);
	for(int i = 1 ; i <= m ; i++ ) scanf("%d" , &b[i]);
	for(int i = 1 ; i < n ; i++ ) a[i] = a[i + 1] - a[i]; a[n] = -1e9;
	for(int i = 1 ; i < m ; i++ ) b[i] = b[i + 1] - b[i]; b[m] = -1e9;
	if(m == 1)
	{
		printf("%d" , n);
		return 0;
	}
	kmp[1] = it = 0;
	for(int i = 2 ; i < m ; i++ ) 
	{
		while(it && b[i] != b[it + 1]) it = kmp[it];
		if(b[i] == b[it + 1]) it++;
		kmp[i] = it;
	}
	it = 0;
	for(int i = 1 ; i < n ; i++ )
	{
		while(it && a[i] != b[it + 1]) it = kmp[it];
		if(a[i] == b[it + 1]) it++;
		if(it == m - 1) ans++ , it = kmp[it];
	}
	printf("%d" , ans);
	return 0;
}
/*
1 1
1 1
*/