#include <bits/stdc++.h>
using namespace std;
int T , n , a[550] , p[550] , tot , op[2][5500000] , sum;
vector< int > pl[550];
deque< int > t , tt;
void reverse( int len , int d )
{
//	cerr << len << endl;
	for(int i = 1 ; i <= len ; i++ ) 
	{
		++tot; op[0][tot] = d + len; op[1][tot] = p[a[i]];
		d++;
	}
	t.push_back(2 * len);
	sum = d + len;
	reverse(a + 1 , a + len + 1);
}
int main()
{
//	freopen("1.in" , "r" , stdin);
//	freopen("1.out" , "w" , stdout);
	scanf("%d" , &T);
	while(T--)
	{
		scanf("%d" , &n); tot = sum = 0;
		while(!t.empty()) t.pop_back();
		while(!tt.empty()) tt.pop_back();
		for(int i = 1 ; i <= n ; i++ ) pl[i].clear() , scanf("%d" , &a[i]) , p[i] = a[i];
		sort(p + 1 , p + n + 1);
		for(int i = 1 ; i <= n ; i++ )
		{
			a[i] = lower_bound(p + 1 , p + n + 1 , a[i]) - p;
			pl[a[i]].push_back(i);
		}
		int gg = 0;
		for(int i = 1 ; i <= n ; i++ )
		{
			if(pl[i].size() & 1)
			{
				printf("-1\n");
				gg = 1;
				break;
			}
		}
		if(gg) continue;
		for(int i = n ; i >= 1 ; i -= 2 )
		{
			int y = 0;
			for(int j = i - 1; j >= 1 ; j-- )
			{
				if(a[j] == a[i])
				{
					y = j;
					break;
				}
			}
			reverse(y , sum); reverse(i - 1 , sum);
			tt.push_back(2);
		}
		printf("%d\n" , tot);
		for(int i = 1 ; i <= tot ; i++ ) printf("%d %d\n" , op[0][i] , op[1][i]);
		int qwq = t.size() + tt.size();
		printf("%d\n" , qwq);
		while(!t.empty())
		{
			printf("%d " , t.front()); t.pop_front();
		}
		while(!tt.empty())
		{
			printf("%d " , tt.back()); tt.pop_front();
		}
		printf("\n");
	}
	return 0;
}
/*
1
6
1 3 1 2 2 3
*/