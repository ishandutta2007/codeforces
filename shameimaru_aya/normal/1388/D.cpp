#include<bits/stdc++.h>
using namespace std;
int n , a , du[1100000] , las[1100000] , t , fa[1100000] , anss[1100000] , tot;
long long ans , val[1100000];
queue< int > q;
int main()
{
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; i++ ) scanf("%lld" , &val[i]);
	for(int i = 1 ; i <= n ; i++ )
	{
		scanf("%d" , &a);
		if(a == -1) a = 0;
		du[a]++;
		fa[i] = a;
	}
	for(int i = 1 ; i <= n ; i++ )
		if(du[i] == 0) q.push(i);
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
//		cerr << u << ' ' << val[u] << ' ' << fa[u] << endl;
		du[fa[u]]--;
		if(!du[fa[u]] && fa[u]) q.push(fa[u]);
		if(val[u] < 0)
		{
			las[++t] = u;
			continue;
		}
		anss[++tot] = u;
		ans += val[u];
		val[fa[u]] += val[u];
	}
	reverse(las + 1 , las + t + 1);
	for(int i = 1 ; i <= t ; i++ ) ans += val[las[i]] , val[fa[las[i]]] += val[las[i]];
	printf("%lld\n" , ans);
	for(int i = 1 ; i <= tot ; i++ ) printf("%d " , anss[i]);
	for(int i = 1 ; i <= t ; i++ ) printf("%d " , las[i]);
	return 0;
}