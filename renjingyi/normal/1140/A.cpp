#include <bits/stdc++.h>
using namespace std;
int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int cnt = 0;
	int mx = 0;
	for(int i = 1; i <= n; i ++)
	{
		int x;
		cin >> x;
		if(i > mx)
			cnt ++;
		mx = max(mx, x);
	}
	cout << cnt << endl;
	
	return 0;
}