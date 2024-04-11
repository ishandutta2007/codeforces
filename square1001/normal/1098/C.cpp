#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N; long long S;
	cin >> N >> S;
	if (S < 2 * N - 1 || S >(long long)(N) * (N + 1) / 2) {
		cout << "No" << endl;
	}
	else {
		int B = 1;
		while (true) {
			int remn = N;
			long long reqs = 0;
			long long mul = 1;
			int depth = 1;
			while(remn > 0) {
				reqs += min((long long)(remn), mul) * depth;
				++depth;
				remn -= min((long long)(remn), mul);
				mul *= B;
			}
			if (reqs <= S) break;
			++B;
		}
		vector<int> seq = { 1 };
		if (B == 1) seq = vector<int>(N, 1);
		else {
			int rem = N - 1;
			long long curs = 1;
			while (rem > 0) {
				int depth = seq.size() + 1;
				int nxt = 1;
				while (true) {
					long long reqs = curs;
					long long mul = nxt;
					int remn = rem;
					int d = depth;
					while (remn > 0) {
						reqs += min((long long)(remn), mul) * d;
						++d;
						remn -= min((long long)(remn), mul);
						mul *= B;
					}
					if (reqs <= S) break;
					++nxt;
				}
				seq.push_back(nxt);
				rem -= nxt;
				curs += (long long)(nxt)* depth;
			}
		}
		vector<int> expansion;
		for (int i = 0; i < seq.size(); ++i) {
			for (int j = 0; j < seq[i]; ++j) {
				expansion.push_back(i + 1);
			}
		}
		vector<int> used(N);
		int ptr = 0;
		cout << "Yes" << endl;
		for (int i = 1; i < N; ++i) {
			if (i >= 2) cout << ' ';
			while (used[ptr] == B || expansion[i] - expansion[ptr] >= 2) ++ptr;
			++used[ptr];
			cout << ptr + 1;
		}
		cout << endl;
	}
	return 0;
}