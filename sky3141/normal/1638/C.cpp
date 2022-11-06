#include<iostream>
#include<algorithm>
#define MAXN 100005
using namespace std;

int t;
int n;
int a[MAXN];
int ans, maxnum; 

int main()
{
	cin >> t;
	while(t--)
	{
		cin >> n;
		ans = 0; maxnum = 0;
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i];
			maxnum = max(a[i], maxnum);
			if(maxnum == i) ans++;
		}
		cout << ans << endl;
	}
	return 0;
}