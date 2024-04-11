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
int cnt[maxn], q[maxn];
bool mark[maxn];
vector<pp> v;
int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	long long k;
	cin >> n >> k;
	for(int i = 1; i <= n; i ++)
	{
		for(int j = i + i; j <= n; j += i)
			cnt[j] ++;
		q[i] = q[i - 1] + cnt[i];
		if(q[i] >= k)
		{
			n = i;
			break;
		}
	}
	if(q[n] < k)
	{
		cout << "No" << endl;
		return 0;
	}
	for(int i = n; i + i > n; i --)
		v.push_back(mp(cnt[i], i));
	sort(v.begin(), v.end());
	int tot = q[n] - k, num = n;
	for(int i = (int)v.size() - 1; i >= 0; i --)
		if(tot >= v[i].first)
		{
			tot -= v[i].first;
			num --;
			mark[v[i].second] = 1;
		}
	cout << "Yes" << endl;
	cout << num << endl;
	for(int i = 1; i <= n; i ++)
		if(!mark[i])
			cout << i << " ";
	cout << endl;
	
	return 0;
}