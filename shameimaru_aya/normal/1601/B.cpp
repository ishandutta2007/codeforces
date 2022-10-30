#include <bits/stdc++.h>
using namespace std;
int n , a[330000] , b[330000] , ta[330000] , tb[330000] , va[330000] , vb[330000] , noww , ans[330000] , tot;
set< int > s;
set< int >::iterator it;
queue< int > q , tp;
int main()
{
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; i++ ) scanf("%d" , &a[i]);
	for(int i = 1 ; i <= n ; i++ ) scanf("%d" , &b[i]);
	for(int i = 1 ; i <= n ; i++ ) s.insert(i);
	memset(ta , 0x7f / 3 , sizeof(ta)); 
	memset(tb , 0x7f / 3 , sizeof(tb)); 
	q.push(n); tp.push(1); s.erase(n); tb[n] = 0;
	while(!q.empty())
	{
		int u = q.front() , d = tp.front(); q.pop(); tp.pop();
//		cerr << u << ' ' << d << endl;
//		cerr << u << ' ' << u - a[u] << endl;
		if(u - a[u] <= 0 && d == 1) 
		{
//			cerr << u << endl;
			noww = u;
			break;
		}
		if(d == 0)
		{
//			cerr << u << ' ' << u + b[u] << ' ' << tb[u + b[u]] << endl;
			if(tb[u + b[u]] > ta[u]) 
			{
				tb[u + b[u]] = ta[u]; vb[u + b[u]] = u;
				q.push(u + b[u]); tp.push(1);
			}
		}
		else
		{
			it = s.lower_bound(u - a[u]);
			while(it != s.end())
			{
				ta[*it] = tb[u] + 1; va[*it] = u;
				q.push(*it); tp.push(0);
				s.erase(it);
				it = s.lower_bound(u - a[u]);
			}
		}
	}
	if(!noww)
	{
		printf("-1\n");
		return 0;
	}
	ans[++tot] = 0;
	while(noww != n)
	{
//		cerr << noww << ' ';
		noww = vb[noww];
		if(noww == n) break;
		ans[++tot] = noww;
		noww = va[noww];
	}
	printf("%d\n" , tot);
	for(int i = tot ; i >= 1 ; i-- ) printf("%d " , ans[i]);
	return 0;
}