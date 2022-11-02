#include<bits/stdc++.h>
using namespace std;
int T , n , k , a[330000] , pre[330000] , nex[330000] , num[3] , f;
string s;
queue< int > q;
inline void upd( int k )
{
	int u = k;
	while(~u)
	{
		a[u] = a[k];
		u = pre[u];
	}
	u = k;
	while(~u)
	{
		a[u] = a[k];
		u = nex[u];
	}
}
int main()
{
	scanf("%d" , &T);
	while(T--)
	{
		f = 0;
		while(!q.empty()) q.pop();
		scanf("%d%d" , &n , &k);
		cin >> s;
		for(int i = 1 ; i <= n ; i++ ) 
		{
			if(s[i - 1] == '?') a[i] = 2;
			else a[i] = s[i - 1] - '0';
			pre[i] = nex[i] = -1;
		}
		num[0] = num[1] = num[2] = 0;
		for(int i = 1 ; i <= k ; i++ )
		{
			num[a[i]]++;
			if(a[i] == 2) q.push(i);
		}
		for(int i = k + 1 ; i <= n ; i++ )
		{
			if(num[0] > k / 2 || num[1] > k / 2)
			{
				printf("NO\n");
				f = 1;
				break;
			}
			if(num[2] == 1) 
			{
				a[q.front()] = (num[0] == k / 2 ? 1 : 0);
				num[2]--;
				num[a[q.front()]]++;
				upd(q.front());
				q.pop();
			}
			if(a[i - k] == 2 && a[i] == 2)
			{
				nex[i - k] = i , pre[i] = i - k;
				q.pop();
				q.push(i);
				continue;
			}
			if(a[i - k] != 2 && a[i] == 2)
			{
				a[i] = a[i - k];
				upd(i);
				continue;
			}
			if(a[i - k] == 2 && a[i] != 2)
			{
				num[2]--; num[a[i]]++;
				a[i - k] = a[i];
				q.pop();
				upd(i - k);
				continue;
			}
			if(a[i - k] != 2 && a[i] != 2 && a[i - k] != a[i])
			{
				printf("NO\n");
				f = 1;
				break;
			}
		}
		if(f) continue;
		if(num[0] > k / 2 || num[1] > k / 2)
		{
			printf("NO\n");
			f = 1;
			continue;
		}
		printf("YES\n");
	}
    return 0;
}