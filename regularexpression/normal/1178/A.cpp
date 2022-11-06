#include<algorithm>
#include<iostream>
#include<numeric>
#include<iomanip>
#include<cassert>
#include<chrono>
#include<string>
#include<vector>
#include<cmath>
#include<ctime>
#include<deque>
#include<queue>
#include<set>
#include<map>

using namespace std;

typedef long long ll;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<ll> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	ll sum = 0;
	vector<int> c;
	for (int i = 1; i < n; ++i) {
		if (a[i] * 2 <= a[0]) {
			sum += a[i];
			c.push_back(i);
		}
	}
	sum += a[0];
	ll allSum = 0;
	for (int i = 0; i < n; ++i) {
		allSum += a[i];
	}
	if ((allSum - sum) < sum) {
		cout << (int)c.size() + 1 << '\n';
		cout << 1 << " ";
		for (auto v : c) {
			cout << v + 1 << " ";
		} 
	} else {
		cout << 0;
	}
	return 0;
}