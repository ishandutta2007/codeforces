#include <bits/stdc++.h>

using namespace std;

int possibleContinuation(vector<int> &fragment, vector<int> &pcont, int n) {
//	printf("testing cont");
//	for (int x : pcont) printf(" %d", x);
//	printf("\n");
	vector<bool> inCont(n, false);
	for (int x : pcont) inCont[x] = true;
	for (int i = fragment.size() - 1; i > 0; --i) {
		if (inCont[fragment[i-1]] && !inCont[fragment[i]]) return -1;
	}
	vector<bool> inFragment(n, false);
	for (int x : fragment) inFragment[x] = true;
	int outside = 0, exempt = -1;
	for (int x : pcont) {
		if (!inFragment[x]) {
			outside++; exempt = x;
		}
	}
	if (outside == 1) return exempt;
	else return -1;
}

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		vector<vector<int>> segs(n - 1);
		for (int i = 1; i < n; ++i) {
			int k; scanf("%d", &k);
			for (int elem = 0; elem < k; ++elem) {
				int x; scanf("%d", &x);
				segs[i - 1].push_back(x - 1);
			}
		}
		vector<vector<int>> startPoints;
		for (vector<int> &st : segs) {
			if (st.size() != 2) continue;
			startPoints.push_back(st);
			swap(st[0], st[1]);
			startPoints.push_back(st);
			swap(st[0], st[1]);
		}
		for (vector<int> st : startPoints) {
			vector<int> sagot = st;
//			printf("test %d %d\n", st[0], st[1]);
			while (sagot.size() < n) {
				vector<int> patuloy;
				for (vector<int> &pcont : segs) {
					int toAdd = possibleContinuation(sagot, pcont, n);
					if (toAdd > -1) patuloy.push_back(toAdd);
//					if (toAdd > -1) printf("%d might cont\n", patuloy.back());
				}
				if (patuloy.size() == 1) sagot.push_back(patuloy[0]);
				else break;
			}
			if (sagot.size() == n) {
				for (int x : sagot) printf("%d ", x + 1);
				printf("\n");
				break;
			} else {
//				printf("cont broke\n");
			}
		}
	}
	return 0;
}