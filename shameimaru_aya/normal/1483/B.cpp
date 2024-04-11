#include <bits/stdc++.h>
using namespace std;
int T , n , a[110000] , f[110000] , del[110000] , noww , las;
int nex[110000] , pre[110000] , ans[110000] , tot , fst;
queue< int > q[2];
int main()
{
	scanf("%d" , &T);
	while(T--)
	{
		scanf("%d" , &n); tot = noww = las = 0; 
		while(!q[0].empty()) q[0].pop(); 
		while(!q[1].empty()) q[1].pop(); 
		for(int i = 1 ; i <= n ; i++ ) scanf("%d" , &a[i]) , f[i] = del[i] = 0;
		for(int i = 1 ; i <= n ; i++ ) nex[i] = i + 1 , pre[i] = i - 1;
		nex[n] = 1; pre[1] = n;
		for(int i = 1 ; i <= n ; i++ ) q[noww].push(i);
		for(int d = 1 ; d <= n ; d++ )
		{
			las = noww; noww ^= 1;
			while(!q[las].empty())
			{
				int u = q[las].front(); q[las].pop();
				if(del[u]) continue;
				if(__gcd(a[u] , a[nex[u]]) == 1) 
				{
					q[noww].push(u); ans[++tot] = nex[u]; del[nex[u]] = 1;
					pre[nex[nex[u]]] = pre[nex[u]] , nex[pre[nex[u]]] = nex[nex[u]];
				}
			}
		}
		printf("%d " , tot);
		for(int i = 1 ; i <= tot ; i++ ) printf("%d " , ans[i]); printf("\n");
	}
	return 0;
}
/*
5
9
1 2 3 4 5 6 7 8 9
*/