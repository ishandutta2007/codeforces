#include<bits/stdc++.h>
using namespace std;
long long n , a[3000] , b[3000] , mod , qwq , ans = 1e10;
map< int , int > mp , num , num1;
vector< long long > vec[3000] , vec1[3000];
bool check()
{
	for(int i = 1 ; i <= n ; i++ )
	if(num[a[i]] != num1[(a[i] + qwq) % mod])
	return 0;
	return 1;
}
int main()
{
	scanf("%d%d" , &n , &mod);
	for(int i = 1 ; i <= n ; i++ )
	scanf("%d" , &a[i]) , mp[a[i]]++;
	for(int i = 1 ; i <= n ; i++ )
	{
		if(mp[a[i]])
		{
			num[a[i]] = mp[a[i]];
			vec[mp[a[i]]].push_back(a[i]);
//			cerr << mp[a[i]] << " " << a[i] << endl;
			mp[a[i]] = 0;
		}
	}
	for(int i = 1 ; i <= n ; i++ )
	scanf("%d" , &b[i]) , mp[b[i]]++;
	for(int i = 1 ; i <= n ; i++ )
	{
		if(mp[b[i]])
		{
			num1[b[i]] = mp[b[i]];
			vec1[mp[b[i]]].push_back(b[i]);
//			cerr << mp[b[i]] << " " << b[i] << endl;
			mp[b[i]] = 0;
		}
	}
	for(int i = 0 ; i < vec1[num[a[1]]].size() ; i++ )
	{
		qwq = ((vec1[num[a[1]]][i] - a[1]) % mod + mod) % mod;
		if(check()) ans = min(ans , qwq);
	}
	printf("%lld" , ans);
	return 0;
}
/*
5 5
3 3 2 2 1
4 4 0 0 3
*/