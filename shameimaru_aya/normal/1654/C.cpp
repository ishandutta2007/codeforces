#include<bits/stdc++.h>
using namespace std;
int T , n , a[220000] , it , gg;
long long s;
queue< long long > q;
map< long long , long long >  mp;
int main()
{
	scanf("%d" , &T);
	while(T--)
	{
		while(!q.empty()) q.pop(); mp.clear(); gg = 0;
		scanf("%d" , &n); s = 0; it = 1;
		for(int i = 1 ; i <= n ; i++ ) scanf("%d" , &a[i]) , s += a[i];
		sort(a + 1 , a + n + 1); reverse(a + 1 , a + n + 1);
		q.push(s); mp[s] = 1;
		while(!q.empty())
		{
			long long w = q.front() , num = mp[q.front()]; q.pop();
			while(a[it] == w  && it <= n && num) 
			{
				it++; num--;
			}
			if(num == 0 && a[it] == w && it <= n)
			{
				printf("NO\n"); gg = 1;
				break;
			}
			if(!num || w == 1) continue;
			if(!mp[(w + 1) / 2]) q.push((w + 1) / 2); 
			mp[(w + 1) / 2] += num;
			if(!mp[(w) / 2]) q.push((w) / 2); 
			mp[(w) / 2] += num;
		}
		if(it != n + 1 && !gg) 
		{
			printf("NO\n"); gg = 1;
		}
		if(!gg) printf("YES\n");
	}
	return 0;
}
/*
*/