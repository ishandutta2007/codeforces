#include <bits/stdc++.h>

using namespace std;
#define int long long

int n;
vector<pair <pair <int, int>, int> > a;
vector<pair <pair <int, int>, int> > b;
void read() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		if (x < y)
			a.push_back({{x, y}, i + 1});
		if (x > y)
			b.push_back({{x, y}, i + 1});
	}
}

bool cmp1(pair <pair <int, int>, int> a, pair <pair <int, int>, int> b) {
	return a.first.second > b.first.second;
}


bool cmp2(pair <pair <int, int>, int> a, pair <pair <int, int>, int> b) {
	return a.first.first < b.first.first;
}


void run() {
	sort(a.begin(), a.end(), cmp1);
	sort(b.begin(), b.end(), cmp2);
	if (a.size() < b.size())
		swap(a, b);
	cout << a.size() << endl;
	for (auto i : a)
		cout << i.second << " ";
	cout << endl;
}

void write() {

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