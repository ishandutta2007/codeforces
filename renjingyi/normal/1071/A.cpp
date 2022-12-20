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
const int maxn = 1e5 + 5;
bool mark[maxn];
int main()
{
	std::ios::sync_with_stdio(false);
	int a, b;
	cin >> a >> b;
	for(long long i = 100000; i >= 0; i --)
	{
		if(i * (i + 1) / 2 <= a + b)
		{
			vector<int> ans;
			long long now = a;
			for(int j = i; j >= 1; j --)
				if(now >= j)
				{
					now -= j;
					ans.push_back(j);
					mark[j] = 1;
				}
			cout << ans.size() << endl;
			for(int j = 0; j < ans.size(); j ++)
				cout << ans[j] << " ";
			cout << endl;
			cout << i - ans.size() << endl;
			for(int j = 1; j <= i; j ++)
				if(!mark[j])
					cout << j << " ";
			cout << endl;
			break;
		}
	}
	
	return 0;
}