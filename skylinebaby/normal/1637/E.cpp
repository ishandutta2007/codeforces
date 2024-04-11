#include<bits/stdc++.h>
using namespace std;
int a[312345];

int v[312345];
int num[312345];
vector<int> need[312345];
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n, m;
		scanf("%d %d", &n, &m);
		for(int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
		}
		sort(a, a + n);
		int cnt = 0;
		v[0] = a[0];
		num[0] = 1;
		for(int i = 1; i < n; i++)
		{
			if(a[i] > v[cnt])
			{
				cnt++;
				v[cnt] = a[i];
				num[cnt] = 1;
			}
			else
			{
				num[cnt] ++;
			}
		}
		int mx = 0;
		for(int i = 0; i <= cnt; i++)
		{
			need[num[i]].push_back(i);
			mx = max(mx, num[i]);
			//printf("%d %d %d \n", i, v[i], num[i]);
		}
		
		set<pair<int, int> > s;
		for(int i = 0; i < m; i++)
		{
			int x, y;
			scanf("%d %d", &x, &y);
			s.insert(make_pair(x, y));
			s.insert(make_pair(y, x));
		}
		long long ans = 0;
		for(int i = mx; i >= 0; i--)
		{
		  	int zi = (int) need[i].size();
		  	if(!zi) continue;
			for(int j = i; j >= 0; j--)
			{
				int zj = (int) need[j].size();	
				if(!zj) continue;
				long long sz = i + j;	
				long long localans = ans / sz;
				if(i == j)
				{
					if(zi < 2) continue;
					for(int k = zi - 1; k >= 0; k--)
					{
						for(int l = k - 1; l >= 0; l--)
						{
							int aa = v[need[i][k]];
							int bb = v[need[j][l]];
							if(aa + bb <= localans) break;
							if(s.find(make_pair(aa, bb)) != s.end()) continue;
							localans = aa + bb;
							ans = max(ans, sz * (aa + bb));
						}
					}
				}
				else
				{
					for(int k = zi - 1; k >= 0; k--)
					{
						for(int l = zj - 1; l >= 0; l--)
						{
							int aa = v[need[i][k]];
							int bb = v[need[j][l]];
							if(aa + bb <= localans) break;
							if(s.find(make_pair(aa, bb)) != s.end()) continue;
							localans = aa + bb;
							ans = max(ans, sz * (aa + bb));
						}
					}					
				}
			}
		}
		printf("%lld\n", ans);
		for(int i = 0; i <= cnt; i++)
		{
			need[num[i]].clear();
		}
	}
	return 0;
}

/*
1
6 0 
3 6 7 3 3 6 
*/