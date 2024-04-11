#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	vector<string> arr(n - k + 1);
	for (auto& x : arr)
		cin >> x;
	vector<string> list;
	for (int i = 0; i < 26; ++i)
		for (int j = 0; j < 3; ++j)
		{
			string s;
			s.push_back('A' + i);
			s.push_back('a' + j);
			list.push_back(s);
		}
	vector<string> ans;
	for (int i = 0; i < k - 1; ++i)
		ans.push_back(list[i]);
	for (int i = k - 1; i < n; ++i)
		if (arr[i - k + 1] == "NO")
			ans.push_back(ans[i - k + 1]);
		else
			ans.push_back(list[i]);
	for (string s : ans)
		cout << s << ' ';
	cout << endl;
}