#include<algorithm>
#include<iostream>
#include<numeric>
#include<iomanip>
#include<cassert>
#include<chrono>
#include<string>
#include<vector>
#include<random>
#include<cmath>
#include<ctime>
#include<deque>
#include<queue>
#include<set>
#include<map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	int mx = 0, idx = -1;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] > mx) {
			mx = a[i];
			idx = i;
		}
	}
	for (int i = 1; i < idx; i++) {
		if (a[i] < a[i - 1]) {
			cout << "NO";
			return 0;
		}
	}
	for (int i = n - 2; i > idx; --i) {
		if (a[i] < a[i + 1]) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}