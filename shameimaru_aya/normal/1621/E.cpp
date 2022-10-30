#include <bits/stdc++.h> 
using namespace std;
int T , n , m , a[110000] , k[110000] , rk[110000] , L[110000] , R[110000] , D[110000] , id[110000];
vector< int > b[110000];
struct item
{
	long long s , t; int id;
	bool operator < ( const item &a ) const
	{
		if(s * a.t == a.s * t) return id < a.id;
		return s * a.t < a.s * t;
	}
} node[110000];
set< item > s;
set< item >::iterator it;
int main()
{
//	freopen("1.in" , "r" , stdin);
//	freopen("1.out" , "w" , stdout);
	scanf("%d" , &T);
	while(T--)
	{
		scanf("%d%d" , &n , &m); s.clear(); 
		for(int i = 1 ; i <= n ; i++ ) scanf("%d" , &a[i]); a[n + 1] = 0;
		sort(a + 1 , a + n + 1); reverse(a + 1 , a + n + 1); reverse(a + 1 , a + m + 1); 
		for(int i = 1 ; i <= m ; i++ )
		{
			scanf("%d" , &k[i]); b[i].clear(); b[i].resize(k[i]);
			node[i] = (item){0 , k[i] , i};
			for(int j = 0 ; j < k[i] ; j++ ) scanf("%d" , &b[i][j]) , node[i].s += b[i][j];
			s.insert(node[i]); 
		}
		int t = 0;
		for( it = s.begin() ; it != s.end() ; it++ )
		{
			rk[(*it).id] = ++t; id[t] = (*it).id;
		}
		for(int i = 1 ; i <= m ; i++ )
		{
			int u = id[i];
			if(node[u].s <= node[u].t * a[i]) D[i] = 1;
			else D[i] = 0;
			if(node[u].s <= node[u].t * a[i - 1]) L[i] = 1;
			else L[i] = 0;
			if(node[u].s <= node[u].t * a[i + 1]) R[i] = 1;
			else R[i] = 0;
			D[i] += D[i - 1]; L[i] += L[i - 1]; R[i] += R[i - 1]; 
		}
		for(int i = 1 ; i <= m ; i++ )
		{
			s.erase(node[i]); 
			for(int j : b[i])
			{
				item qwq = node[i]; qwq.t--; qwq.s -= j;
				it = s.upper_bound(qwq); int r;
				if(it == s.end()) r = m + 1;
				else r = rk[(*it).id];
				if(r > rk[i]) r--;
//				cerr << (it == s.end()) << ' ' << r << ' ' << rk[i] << endl;
				if(r < rk[i]) 
				{
//					cerr << '(' << (R[rk[i] - 1] - R[r - 1] == rk[i] - r) << ' ' 
//						 << (D[r - 1] == r - 1) << ' '
//						 << (D[m] - D[rk[i]] == m - rk[i]) << ' '
//						 << (a[r] * qwq.t >= qwq.s) << ')' << endl;
					if(R[rk[i] - 1] - R[r - 1] == rk[i] - r && D[r - 1] == r - 1
					 && D[m] - D[rk[i]] == m - rk[i] && a[r] * qwq.t >= qwq.s) printf("1");
					else printf("0");
				}
				else
				{
					if(L[r] - L[rk[i]] == r - rk[i] && D[rk[i] - 1] == rk[i] - 1
					 && D[m] - D[r] == m - r && a[r] * qwq.t >= qwq.s) printf("1");
					else printf("0");
				}
			}
			s.insert(node[i]);
		}
		printf("\n");
	}
    return 0;
} 
/*
2
1 1
30
3
25 16 37
4 2
5 5 5 12
2
4 5
3
111 11 11
*/