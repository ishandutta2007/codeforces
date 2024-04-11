#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
long long gcd(long long x, long long y) {
	if (y == 0) return x;
	return gcd(y, x % y);
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<long long> W(N), H(N), C(N);
	map<long long, vector<pair<long long, long long> > > D;
	for (int i = 0; i < N; ++i) {
		cin >> W[i] >> H[i] >> C[i];
		D[W[i]].push_back(make_pair(H[i], C[i]));
	}
	vector<long long> fixed_seq;
	bool okay = true;
	vector<vector<long long> > seqs;
	int S = -1;
	for (pair<long long, vector<pair<long long, long long> > > i : D) {
		vector<pair<long long, long long> > v = i.second;
		sort(v.begin(), v.end());
		vector<long long> vf(v.size()), vs(v.size());
		for (int i = 0; i < v.size(); ++i) {
			vf[i] = v[i].first;
			vs[i] = v[i].second;
		}
		S = v.size();
		if (fixed_seq.empty()) fixed_seq = vf;
		else if (fixed_seq != vf) okay = false;
		seqs.push_back(vs);
	}
	long long gcd_everything = -1;
	if (okay) {
		vector<long long> G(S);
		for (int i = 0; i < S; ++i) G[i] = seqs[0][i];
		for (int i = 1; i < seqs.size(); ++i) {
			for (int j = 0; j < S; ++j) {
				G[j] = gcd(G[j], seqs[i][j]);
			}
		}
		gcd_everything = G[0];
		for (int i = 1; i < S; ++i) {
			gcd_everything = gcd(gcd_everything, G[i]);
		}
		for (int i = 0; i < seqs.size() && okay; ++i) {
			long long val = seqs[i][0] / G[0];
			for (int j = 1; j < S; ++j) {
				if (val != seqs[i][j] / G[j]) {
					okay = false;
					break;
				}
			}
		}
	}
	if (!okay) {
		cout << 0 << endl;
	}
	else {
		int ans = 0;
		for (int i = 1; (long long)(i)* i <= gcd_everything; ++i) {
			if (gcd_everything % i == 0) {
				++ans;
				if ((long long)(i)* i < gcd_everything) {
					++ans;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}