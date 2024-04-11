#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> arr(n);
	for (auto &x : arr)
		cin >> x;
	int cnt = 0;
	for (auto x : arr)
		cnt += (x & 1);
	if (cnt & 1)
		cout << "First" << endl;
	else
		if (cnt <= 0)
			cout << "Second" << endl;
		else
			cout << "First" << endl;
}