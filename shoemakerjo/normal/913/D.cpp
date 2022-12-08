#include <bits/stdc++.h>

using namespace std;
#define pii pair<int, int>
#define ll long long
#define maxn 200010
#define maxt 10010
int n, T;
int a[maxn];
int t[maxn];
vector<pii> cur;
bool check(int val) {
	cur.clear();
	for (int i = 0; i < n; i++) {
		if (val <= a[i]) {
			cur.push_back(pii(t[i], i));
		}
	}
	if (cur.size() < val) return false;

	sort(cur.begin(), cur.end());
	int sum = 0;
	for (int i = 0; i < val; i++) {
		sum += cur[i].first;

	}
	if (sum > T) return false;
	return true;
	// if (cur.size() )
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> T;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> t[i];
	}
	int low = 0;
	int high = n;
	while (low < high) {
		int mid = (low+high+1)/2;
		if (check(mid)) {
			low = mid;
		}
		else {
			high = mid-1;
		}
	}
	check(low);
	cout << low << endl;
	cout << low << endl;
	for (int i = 0; i < low; i++) {
		cout << cur[i].second+1 << " ";
	}
	cout << endl;
	cin >> n;
}