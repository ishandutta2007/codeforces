#include<bits/stdc++.h>
using namespace std;
int a[2345];
int b[2345];
int cnt[2345];
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		vector<int> p;
		int n;
		scanf("%d", &n);
		for(int i = 0; i <= n; i++) cnt[i] = 0;
		for(int i = 0; i < n; i++) b[i] = 0;
		for(int i = 0; i < n; i++) 
		{
			scanf("%d", &a[i]);
			if(cnt[a[i]])
			{
				b[i] = 1;
			} 		
			cnt[a[i]] ++;
		}			
		for(int i = 0; i < n; i++)
		{
			if(b[i])
			{
				for(int j = 0; j <= n; j++) if(cnt[j] == 0)
				{
					cnt[a[i]] --;
					a[i] = j;
					cnt[j] ++;
					p.push_back(i);	
					break;				
				}
			}
		}
		int x = 0;
		for(int j = 0; j <= n; j++) if(cnt[j] == 0)
		{
			x = j;	
			break;			
		}
		/*for(int i = 0; i < n; i++) 
		{
			printf("%d ", a[i]);
		}
		printf("\n %d \n", x);*/
		while(true)
		{
			//printf("x = %d\n", x);
			if(x == n)
			{
				int flag = 0;
				for(int i = 0; i < n; i++)  
				{
					if(a[i] != i)
					{
						int tpx = x;
						x = a[i];
						a[i] = tpx;
						p.push_back(i);	
						flag = 1;
						break;	
												
					}
				}
				if (!flag) break;
			}
			else
			{
				int tpx = x;
				int nwx = a[x];
				a[tpx] = tpx;
				x = nwx;
				p.push_back(tpx);				
			}
		}
		int sz = p.size();
		printf("%d\n", sz);
		for(int i = 0; i < sz; i++)
		{
			printf("%d ", p[i] + 1);
		}
		printf("\n");
	}

	return 0;
}