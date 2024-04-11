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
int main()
{
	std::ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t --)
	{
		int n;
		cin >> n;
		string a, b;
		cin >> a >> b;
		int l = 0, r = n - 1;
		bool rev = 0;
		vector<int> ans;
		ans.clear();
		for(int i = n - 1; i >= 0; i --)
		{
			if((a[l] == b[i]) ^ rev)
				ans.push_back(1);
			ans.push_back(i + 1);
			rev ^= 1;
			l < r ? l ++ : l --;
			swap(l, r);
		}
		cout << ans.size() << " ";
		for(int i = 0; i < ans.size(); i ++)
			cout << ans[i] << " ";
		cout << endl;
	}
	
	return 0;
}