#include<bits/stdc++.h>
using namespace std;
int n , a[5500];
int solve( int l , int r )
{
	int minn = 1e9 , las = l , ans = 0;
	for(int i = l ; i <= r ; i++ ) minn = min(minn , a[i]);
	for(int i = l ; i <= r ; i++ ) a[i] -= minn;
	ans = minn;
	if(minn >= r - l + 1) return r - l + 1;
	for(int i = l ; i <= r ; i++ )
	{
		if(!a[i])
		{
			ans += solve(las , i - 1);
			las = i + 1;
		}
	}
	if(las != r + 1) ans += solve(las , r);
	ans = min(r - l + 1 , ans);
	return ans;
}
int main()
{
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; i++ ) scanf("%d" , &a[i]);
	printf("%d" , solve(1 , n));
    return 0;
}