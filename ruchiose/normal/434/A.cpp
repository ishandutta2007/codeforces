#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<cmath>
#define i64 long long
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

const int MAXN = 100010;
const int MAXM = 100010;

int N, M;
vector<int> nab[MAXN];
int a[MAXM];

int main()
{
	scanf("%d%d", &N, &M);
	int i;
	fortodo(i, 1, M) scanf("%d", &a[i]);
	fortodo(i, 1, N) nab[i].clear();
	fortodo(i, 2, M)
		{
			nab[a[i - 1]].push_back(a[i]);
			nab[a[i]].push_back(a[i - 1]);
		}
	i64 ans = 0, sum;
	fortodo(i, 2, M) ans += abs(a[i - 1] - a[i]);
	sum = ans;
	fortodo(i, 1, N)
		{
			sort(nab[i].begin(), nab[i].end());
			nab[i].erase(lower_bound(nab[i].begin(), nab[i].end(), i), 
						 upper_bound(nab[i].begin(), nab[i].end(), i));
			i64 decrement = 0;
			i64 p, s = nab[i].size();
			fortodo(p, 0, s - 1)
				{
					decrement += abs(nab[i][p] - i);
					decrement -= abs(nab[i][s / 2] - nab[i][p]);
				}
			ans = min(ans, sum - decrement);
		}
	cout << ans << endl;
}