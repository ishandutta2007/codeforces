#include <queue>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class rollinghash {
private:
	string S;
	vector<unsigned long long> pw;
	vector<unsigned long long> hval;
public:
	rollinghash() : pw(vector<unsigned long long>()), hval(vector<unsigned long long>()) {};
	rollinghash(string S_) : S(S_) {
		pw.resize(S.length() + 1);
		hval.resize(S.length() + 1);
		pw[0] = 1;
		for (int j = 0; j < S.length(); ++j) {
			pw[j + 1] = 311LL * pw[j];
			hval[j + 1] = (311LL * hval[j] + S[j]);
		}
	}
	unsigned long long gethash(int l, int r) {
		return hval[r] - hval[l] * pw[r - l];
	}
};
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N, M, K; string S, T;
	cin >> N >> M >> K >> S >> T;
	rollinghash hs(S), ht(T);
	bool found = false;
	for (int i = 0; i <= N - M; ++i) {
		if (hs.gethash(i, i + M) == ht.gethash(0, M)) {
			int lp = max(i + M - 2 * K, 0);
			if (lp + 2 * K <= N) {
				found = true;
				cout << "Yes\n";
				cout << lp + 1 << ' ' << lp + K + 1 << '\n';
				break;
			}
		}
	}
	if (!found) {
		vector<int> lv(N + 1), rv(N + 1);
		for (int i = 0; i < N; ++i) {
			int l = 0, r = min(min(M, K), N - i) + 1;
			while (r - l > 1) {
				int m = (l + r) >> 1;
				if (hs.gethash(i, i + m) == ht.gethash(0, m)) l = m;
				else r = m;
			}
			lv[i] = l;
		}
		for (int i = 1; i <= N; ++i) {
			int l = 0, r = min(min(M, K), i) + 1;
			while (r - l > 1) {
				int m = (l + r) >> 1;
				if (hs.gethash(i - m, i) == ht.gethash(M - m, M)) l = m;
				else r = m;
			}
			rv[i] = l;
		}
		vector<vector<int> > gl(N + 1), gr(N + 1);
		for (int i = 0; i <= N; ++i) {
			gl[i + lv[i]].push_back(i);
			gr[i - rv[i]].push_back(i);
		}
		int opt = -1, pos = -1;
		for (int i = K; i <= N - K && !found; ++i) {
			for (int j : gl[i]) {
				if (opt < min(i - j, K)) {
					opt = min(i - j, K);
					pos = i;
				}
			}
			for (int j : gr[i]) {
				if (opt + min(j - i, K) >= M) {
					int diff = opt + min(j - i, K) - M;
					found = true;
					cout << "Yes\n";
					cout << pos - K + 1 << ' ' << i + 1 + diff << '\n';
					break;
				}
			}
		}
	}
	if (!found) {
		cout << "No\n";
	}
	return 0;
}