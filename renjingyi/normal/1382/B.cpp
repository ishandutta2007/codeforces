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
int a[maxn];
int main()
{
	std::ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t --)
	{
		int n;
		cin >> n;
		int cnt = 0;
		bool check = 1;
		for(int i = 1; i <= n; i ++)
		{
			cin >> a[i];
			if(a[i] == 1 && check)
				cnt ++;
			else if(a[i] > 1)
				check = 0;
		}
		if(cnt == n)
			cout << (cnt & 1 ? "First" : "Second") << endl;
		else
			cout << (cnt & 1 ? "Second" : "First") << endl;
	}
	
	return 0;
}