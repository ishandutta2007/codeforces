#include <iostream>
#include <cstdio>
#include <queue>
#define heap priority_queue
using namespace std;
const int maxn = 100000;
int n,k;
int x[maxn+1];
int a;
int c[maxn+1];
heap<int,vector<int>,greater<int> > H;

long long res;

int main()
{
	ios_base::sync_with_stdio(0);
	
	cin >> n >> k;
	for (int i=1; i<=n; i++)
		cin >> x[i];
	cin >> a;
	for (int i=1; i<=n; i++)
		cin >> c[i];
	
	res = 0;
	for (int i=1; i<=n; i++)
	{
		H.push(c[i]);
		if (k<x[i])
		{
			int drink = (x[i] - k) / a + ((x[i] - k)%a!=0);
			if (drink>H.size())
			{
				cout << -1;
				return 0;
			}
			
			while (drink>0)
			{
				int p=H.top();
				res+=p;
				k+=a;
				H.pop();
				drink--;
			}
		}
	}
	
	cout << res;
	return 0;	
}