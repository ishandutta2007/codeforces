#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 1012345678;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N, A, B, C;
	cin >> N >> A >> B >> C;
	if (A > B) swap(A, B);
	if (A > C) swap(A, C);
	if (B > C) swap(B, C);
	vector<int> V(N);
	for (int i = 0; i < N; ++i) cin >> V[i];
	sort(V.begin(), V.end());
	if (V.back() > A + B + C) {
		cout << -1 << endl;
	}
	else {
		int ans = 0;
		while (!V.empty() && V.back() > B + C) {
			V.pop_back();
			++ans;
		}
		int ptr = lower_bound(V.begin(), V.end(), A + 1) - V.begin() - 1;
		vector<bool> used(V.size());
		while (!V.empty() && V.back() > A + C) {
			V.pop_back();
			if (ptr >= 0) used[ptr] = true, --ptr;
			++ans;
		}
		ptr = lower_bound(V.begin(), V.end(), B + 1) - V.begin() - 1;
		while (!V.empty() && V.back() > max(A + B, C)) {
			V.pop_back();
			while (ptr != -1 && used[ptr]) --ptr;
			if (ptr >= 0) used[ptr] = true, --ptr;
			++ans;
		}
		vector<int> newv;
		for (int i = 0; i < V.size(); ++i) {
			if (!used[i]) newv.push_back(V[i]);
		}
		V = newv;
		used = vector<bool>(V.size());
		int ca = 0, cb = 0, cc = 0;
		for (int i : V) {
			if (i <= A) ++ca;
			if (i <= B) ++cb;
			if (i <= C) ++cc;
		}
		int sub = inf;
		int ptrab = int(V.size()) - 1, ptrc = int(V.size()) - 1;
		if (ptrab <= 0 || V[ptrab - 1] <= C) sub = max({ cc - cb, (cc - ca + 1) / 2, (cc + 2) / 3 });
		for (int i = 1; ptrab != -1 || ptrc != -1; ++i) {
			while (ptrab != -1 && (used[ptrab] || V[ptrab] > A + B)) --ptrab; if (ptrab != -1) used[ptrab] = true;
			while (ptrc != -1 && (used[ptrc] || V[ptrc] > C)) --ptrc; if (ptrc != -1) used[ptrc] = true;
			if (ptrab != -1) {
				if (V[ptrab] <= A) --ca;
				if (V[ptrab] <= B) --cb;
				if (V[ptrab] <= C) --cc;
			}
			if (ptrc != -1) {
				if (V[ptrc] <= A) --ca;
				if (V[ptrc] <= B) --cb;
				if (V[ptrc] <= C) --cc;
			}
			if (ptrab != 0 && V[ptrab - 1] > C) continue;
			int subsub = max({ cc - cb, (cc - ca + 1) / 2, (cc + 2) / 3 });
			sub = min(sub, subsub + i);
		}
		ans += sub;
		cout << ans << endl;
	}
	return 0;
}