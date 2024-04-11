#include <list>
#include <vector>
#include <iostream>
using namespace std;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int Q;
	cin >> Q;
	while (Q--) {
		int N;
		cin >> N;
		vector<int> A(N);
		for (int i = 0; i < N; ++i) {
			cin >> A[i];
			if (A[i] != -1) --A[i];
		}
		vector<list<int>::iterator> its(N + 1);
		list<int> s;
		its[N] = s.insert(s.begin(), N);
		for (int i = N - 1; i >= 0; --i) {
			if (A[i] == -1) its[i] = s.insert(s.begin(), i);
			else its[i] = s.insert(its[A[i]], i);
		}
		vector<int> ans(N + 1);
		int cnt = 0;
		for (int i : s) {
			ans[i] = cnt++;
		}
		vector<int> st;
		st.push_back(N);
		bool okay = true;
		for (int i = N - 1; i >= 0; --i) {
			while (ans[i] > ans[st.back()]) st.pop_back();
			if (A[i] != -1 && A[i] != st.back()) okay = false;
			st.push_back(i);
		}
		if (okay) {
			for (int i = 0; i < N; ++i) {
				if (i) cout << ' ';
				cout << ans[i] + 1;
			}
			cout << '\n';
		}
		else {
			cout << "-1\n";
		}
	}
	return 0;
}