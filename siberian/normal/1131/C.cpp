#include <bits/stdc++.h>

using namespace std;

#define int long long
vector <int> a;
int n;
void read() {
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++) 
	{
		cin >> a[i];
	}
	sort(a.begin(), a.end());
}

int check(){
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans = max(ans, abs(a[i] - a[(i + 1) % n]));
	}
	return ans;
}
deque <int> ans;

void run() {
	reverse(a.begin(), a.end());
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			ans.push_back(a[i]);
		}
		else
		{
			ans.push_front(a[i]);
		}
	}
}

void write() {
	for (auto i : ans) {
		cout << i << " ";
	}
	cout << endl;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	read();
	run();
	write();
	return 0;
}