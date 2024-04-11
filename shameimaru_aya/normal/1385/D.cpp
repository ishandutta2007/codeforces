#include<bits/stdc++.h>
using namespace std;
int T , n;
string s;
int solve( int l , int r , char c , bool type )
{
	if(l == r)
	{
		if(s[l - 1] == c) return 0;
		return 1;
	}
	int mid = l + r >> 1;
	if(type)
	{
		int a1 = solve(l , mid , c , 0) , a2 = solve(l , mid , c + 1 , 1);
		int b1 = solve(mid + 1 , r , c , 0) , b2 = solve(mid + 1 , r , c + 1 , 1);
		return min(a1 + b2 , a2 + b1);
	}
	else
	{
		int tot = 0;
		for(int i = l ; i <= r ; i++ )
			if(s[i - 1] != c) tot++;
		return tot;
	}
}
int main()
{
	scanf("%d" , &T);
	while(T--)
	{
		scanf("%d" , &n);
		cin >> s;
		printf("%d\n" , solve(1 , n , 'a' , 1));
	}
    return 0;
}