#include <map>
#include <set>
#include <random>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
mt19937 mt(1904262252);
int get_difference(int m, vector<int> v) {
	if (v.size() * 2 > m) {
		vector<int> nxtv;
		for (int i = 0; i < m; ++i) {
			if (!binary_search(v.begin(), v.end(), i)) {
				nxtv.push_back(i);
			}
		}
		v = nxtv;
	}
	if (v.size() <= 1) return 1;
	int inv2 = (m + 1) / 2;
	uniform_int_distribution<int> p(0, v.size() - 1);
	int rep = 3000000;
	int opt = -1;
	map<int, int> sols;
	for (int i = 0; i < rep; ++i) {
		int a = v[p(mt)], b = v[p(mt)];
		if (a == b) continue;
		int cnt = 0;
		while (true) {
			int z = 1LL * (a + b) * inv2 % m;
			if (!binary_search(v.begin(), v.end(), z)) break;
			++cnt;
			b = z;
		}
		if (opt < cnt) {
			opt = cnt;
			sols.clear();
		}
		if (opt == cnt) ++sols[(b - a + m) % m];
	}
	int ans = -1, freq = -1;
	for (pair<int, int> i : sols) {
		if (freq < i.second) {
			freq = i.second;
			ans = i.first;
		}
	}
	return ans;
}
int main() {
	int M, N;
	cin >> M >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	if (A.front() == A.back()) {
		cout << A.front() << ' ' << 0 << endl;
	}
	else {
		int pre = 0;
		vector<int> v;
		for (int i = 1; i <= N; ++i) {
			if (i == N || A[i] != A[i - 1]) {
				if ((i - pre) == N / M + 1) {
					v.push_back(A[i - 1]);
				}
			}
		}
		int d = get_difference(M, A);
		multiset<int> st;
		for (int i = 0; i < N; ++i) {
			st.insert(A[i]);
		}
		int cur = A[0];
		while (true) {
			st.erase(st.lower_bound(cur));
			cur = (cur - d + M) % M;
			if (st.find(cur) == st.end()) {
				cur = (cur + d) % M;
				break;
			}
		}
		vector<int> ra;
		for (int i = 0; i < N; ++i) {
			ra.push_back((cur + 1LL * i * d) % M);
		}
		sort(ra.begin(), ra.end());
		if (ra == A) {
			cout << cur << ' ' << d << endl;
		}
		else {
			cout << -1 << endl;
		}
	}
	return 0;
}