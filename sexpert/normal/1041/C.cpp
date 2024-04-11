#include<bits/stdc++.h>
using namespace std;


vector<int> a;
int n, m, d;

int bs(int start, int target)
{
	int low = start, high = n - 1;
	while(low < high)
	{
		int mid = (low + high + 1)/2;
		if(a[mid] <= target) low = mid;
		else high = mid - 1;
	}
	return low;
}

int main()
{
	cin >> n >> m >> d;
	vector<int> orig;
	for(int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		orig.push_back(x);
		a.push_back(x);
	}
	sort(a.begin(), a.end());
	int ans = 1;
	map<int, int> days;
	for(int i = 0; i < n; i++)
	{
		ans = max(ans, bs(i, a[i] + d) - i + 1);
	}
	cout << ans << endl;
	int counter = 0;
	for(int i = 0; i < n; i++)
	{
		days[a[i]] = counter + 1;
		counter = (counter + 1)%ans;
	}
	for(int i = 0; i < n; i++)
	{
		cout << days[orig[i]] << " ";
	}
	cout << endl;
}