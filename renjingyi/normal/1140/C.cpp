#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>
#include <vector>
#include <complex>
#include <queue>
#include <stack>
#include <sstream>
#define mp(a, b) make_pair(a, b)
using namespace std;
typedef pair<int, int> pp;
const int maxn = 3e5 + 5;
pp a[maxn];
int main()
{
	std::ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; i ++)
		cin >> a[i].second >> a[i].first;
	sort(a + 1, a + n + 1);
	priority_queue<int, vector<int>, greater<int> > q;
	int cnt = 0;
	long long ans = 0, tot = 0;
	for(int i = n; i >= 1; i --)
	{
		cnt ++;
		tot += a[i].second;
		q.push(a[i].second);
		if(cnt > k)
		{
			cnt --;
			tot -= q.top();
			q.pop();
		}
		ans = max(ans, tot * a[i].first);
	}
	cout << ans << endl;
	
	return 0;
}