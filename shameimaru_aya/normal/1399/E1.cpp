#include<bits/stdc++.h>
using namespace std;
int T , n , cnt[110000] , e[110000] , a , b , c , d , ans;
int fst[220000] , nex[220000] , v[220000] , cst[220000] , tot;
long long s , val[220000] , sum;
priority_queue< pair< long long , int > > q;
inline void add( int a , int b , int c )
{
	nex[++tot] = fst[a]; fst[a] = tot;
	v[tot] = b; val[tot] = c;
	return ;
}
void dfs( int u , int fa )
{
	for(int i = fst[u] ; i ; i = nex[i] )
	{
		if(v[i] == fa) continue;
		dfs(v[i] , u);
		cnt[u] += cnt[v[i]];
		q.push(make_pair((val[i] - val[i] / 2) * cnt[v[i]] , v[i]));
		sum += val[i] * cnt[v[i]];
		e[v[i]] = i;
	}
	if(!cnt[u]) cnt[u] = 1;
	return ;
}
int main()
{
	scanf("%d" , &T);
	while(T--)
	{
		while(!q.empty()) q.pop();
		tot = sum = ans = 0; 
		scanf("%d%lld" , &n , &s);
		for(int i = 1 ; i < n ; i++ )
		{
			scanf("%d%d%d" , &a , &b , &c);
			add(a , b , c); add(b , a , c);
		}
		dfs(1 , 0);
		while(sum > s)
		{
//			cerr << sum << ' ' << s << endl;
			pair< long long , int > u = q.top();
			q.pop();
			sum -= u.first;
			long long qwq = -u.first / cnt[u.second] + val[e[u.second]];
			val[e[u.second]] = qwq;
			q.push(make_pair((qwq - qwq / 2) * cnt[u.second] , u.second));
			ans++;
		}
		printf("%d\n" , ans);
		for(int i = 1 ; i <= n ; i++ ) cnt[i] = fst[i] = 0;
	}
	return 0;
}
/*
200
10 120
3 1 8
5 2 10
8 1 5
2 1 6
7 2 8
10 7 7
6 4 10
4 3 10
9 7 9

10 97
3 1 1
5 1 9
6 3 6
4 3 5
2 1 4
7 6 10
10 6 8
9 8 3
8 5 1

10 119
5 4 9
10 8 1
4 3 10
6 5 1
3 2 1
8 7 7
2 1 2
9 7 4
7 6 9

10 28
8 2 8
5 1 4
6 1 10
10 2 7
7 2 1
9 2 1
2 1 5
4 1 9
3 2 5

*/