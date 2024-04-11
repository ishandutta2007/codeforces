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
using namespace std;
const int maxn = 10005;
int a[maxn], b[maxn];
vector<int> v;
bool f1[maxn], f2[maxn];
int q[maxn];
int main()
{
	std::ios::sync_with_stdio(false);
	int n, l, r;
	cin >> n >> l >> r;
	for(int i = 1; i <= n; i ++)
		cin >> a[i];
	for(int i = 1; i <= n; i ++)
		cin >> b[i];
	f1[0] = 1;
	int pos1 = l == 0 ? 0 : maxn, pos2 = maxn;
	for(int i = 1; i <= n; i ++)
	{
		if(b[i] == 0)
		{
			for(int j = r - a[i]; j >= 0; j --)
				if(f1[j])
				{
					f1[j + a[i]] = 1;
					if(j + a[i] >= l && j + a[i] < pos1)
						pos1 = j + a[i];
				}
		}
		else
			v.push_back(a[i]);
	}
	sort(v.begin(), v.end());
	for(int i = 1; i <= v.size(); i ++)
		q[i] = q[i - 1] + v[i - 1];
	for(int i = (int)v.size() - 1; i >= 0; i --)
	{
		if(pos2 + q[i + 1] <= r)
		{
			cout << i + 2 << endl;
			return 0;
		}
		if(pos1 + q[i + 1] <= r)
		{
			cout << i + 1 << endl;
			return 0;
		}
		for(int j = r - v[i]; j >= 0; j --)
			if(f2[j])
			{
				f2[j + v[i]] = 1;
				if(j + v[i] >= l && j + v[i] < pos2)
					pos2 = j + v[i];
			}
		for(int j = r; j >= 0; j --)
			if(f1[j])
			{
				f2[j] = 1;
				if(j >= l && j < pos2)
					pos2 = j;
			}
		for(int j = r - v[i]; j >= 0; j --)
			if(f1[j])
			{
				f1[j + v[i]] = 1;
				if(j + v[i] >= l && j + v[i] < pos1)
					pos1 = j + v[i];
			}
	}
	cout << (pos2 <= r) << endl;
	
	return 0;
}