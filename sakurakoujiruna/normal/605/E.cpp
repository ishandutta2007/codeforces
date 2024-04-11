#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

const int N = 1011;
const double Eps = 1e-8;
int p[N][N];
double acc[N];
double old[N];
double ans[N];
bool vis[N];

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	if(n == 1)
	{
		cout << 0 << '\n';
		return 0;
	}
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= n; j ++)
			cin >> p[i][j];
	ans[n] = 1;
	vis[n] = true;
	for(int i = 1; i <= n; i ++)
	{
		old[i] = 1 - p[i][n] / 100.0;
		acc[i] = 0;
	}
	while(true)
	{
		int tid = -1;
		double tans = 1e60;
		for(int i = 1; i <= n; i ++)
			if(!vis[i] && old[i] + Eps < 1 && (acc[i] + 1) / (1 - old[i]) < tans)
			{
				tid = i;
				tans = (acc[i] + 1) / (1 - old[i]);
			}
		if(tid == 1)
		{
			cout << setprecision(12) << tans << '\n';
			return 0;
		}
		vis[tid] = true;
		for(int i = 1; i <= n; i ++)
			if(!vis[i])
			{
				acc[i] += old[i] * p[i][tid] / 100.0 * tans;
				old[i] *= 1 - p[i][tid] / 100.0;
			}
	}
}