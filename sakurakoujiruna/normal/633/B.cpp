#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	vector <int> ans;

	int acc = 0;
	for(int i = 1; i <= 1000000; i ++)
	{
		int tmp = i;
		while(tmp % 5 == 0)
		{
			acc ++;
			tmp /= 5;
		}
		if(acc == n)
			ans.push_back(i);
	}
	cout << ans.size() << '\n';
	for(auto &x : ans)
		cout << x << ' ';
	cout << '\n';
	return 0;
}