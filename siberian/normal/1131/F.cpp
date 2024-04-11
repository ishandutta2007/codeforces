#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 150010;
int parent[MAXN], size[MAXN];
vector <int> fans[MAXN];
 
int find_set (int v) {
	if (v == parent[v])
		return v;
	return parent[v] = find_set (parent[v]);
}
void make_set (int v) {
	parent[v] = v;
	size[v] = 1;
	fans[v] = {v};
}
 
void union_sets (int a, int b) {
	a = find_set (a);
	b = find_set (b);
	if (a != b) {
		if (size[a] < size[b])
			swap (a, b);
		for (auto i : fans[b]) {
			fans[a].push_back(i);
		}

		parent[b] = a;
		size[a] += size[b];
	}
}

int n;
vector <pair<int, int> > a;
void read() {
	cin >> n;
	a.resize(n - 1);
	for (int i = 0; i < n - 1; i++) {
		cin >> a[i].first >> a[i].second;
	}
	for (int i = 1; i <= n; i++) {
		make_set(i);
	}
}

void run() {
	for (auto i : a) {
		union_sets(i.first, i.second);
	}
}

void write() {
	int ax = find_set(1);
	for (auto i : fans[ax]) {
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