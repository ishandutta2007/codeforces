#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define pb push_back
#define F first
#define S second
#define mp make_pair

int main()
{
	int n;
	cin >> n;
	vector<int> arr(n);
	for (auto &x : arr)
		cin >> x;
	int cnt = 0;
	for (int i = 1; i < n - 1; ++i)
		if ((arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) || (arr[i] < arr[i - 1] && arr[i] < arr[i + 1]))
			++cnt;
	cout << cnt << endl;
}