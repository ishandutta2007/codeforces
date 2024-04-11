#include <bits/stdc++.h> 
#define lowbit(x) (x & (-x))
using namespace std;
int T , n , c[220000];
char s[220000] , t[220000];
long long ans , sum;
vector< int > pl[30];
void add( int x , int a )
{
	while(x <= n)
	{
		c[x] += a;
		x += lowbit(x);
	}
}
int ask( int x )
{
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
//	freopen("1.in" , "r" , stdin);
//	freopen("1.out" , "w" , stdout);
	scanf("%d" , &T);
	while(T--)
	{
		memset(c , 0 , sizeof(c)); ans = 1e18; sum = 0;
		scanf("%d%s%s" , &n , s + 1 , t + 1); 
		for(int i = 0 ; i < 26 ; i++ ) pl[i].clear();
		for(int i = n ; i >= 1 ; i-- ) pl[s[i] - 'a'].push_back(i);
		for(int i = 1 ; i <= n ; i++ )
		{
			int c = t[i] - 'a';
			for(int j = 0 ; j < c ; j++ )
				if(pl[j].size()) ans = min(ans , sum + pl[j].back() - ask(pl[j].back()) - 1);
			if(pl[c].size())
			{
				sum += pl[c].back() - ask(pl[c].back()) - 1; add(pl[c].back() , 1); pl[c].pop_back();
			}
			else break;
		}
		if(ans > 1e17) printf("-1\n");
		else printf("%lld\n" , ans);
	}
    return 0;
} 
/*
*/