#include<iostream>
#define MAXN 200005

using namespace std;

int t;
int n;
int map[MAXN];
int num;
int ans;
char c;


int main()
{
	scanf("%d", &t);
	for(int s = 1; s <= t; s++)
	{
		ans = 0;
		scanf("%d", &n);
		map[n+1] = 0;
		for(int i = 1; i <= n; i++)
		{
			c = getchar();
			while(c != '0' && c != '1') c = getchar();
			map[i] = c - '0';
		}
		for(int i = 1; i <= n; i++)
		{
			c = getchar();
			while(c != '0' && c != '1') c = getchar();
			num = c - '0';
			if(num == 0)
			    continue;

			if(!map[i]) ans++;
			else if(map[i-1] == 1) ans++;
			else if(map[i+1] == 1)
			{
				ans++;
				map[i+1] = 2;
			}
		}
		cout << ans << endl;
	}
	return 0;
}