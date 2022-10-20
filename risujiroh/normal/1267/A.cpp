#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const long long inf = 1LL << 61;
class state {
public:
	long long cnt, ptr;
	explicit state() : cnt(0), ptr(0) {};
	explicit state(long long cnt_, long long ptr_) : cnt(cnt_), ptr(ptr_) {};
	bool operator<(const state& s) const {
		return cnt != s.cnt ? cnt < s.cnt : ptr > s.ptr;
	}
	bool operator>(const state& s) const {
		return cnt != s.cnt ? cnt > s.cnt : ptr < s.ptr;
	}
	bool operator==(const state& s) const {
		return cnt == s.cnt && ptr == s.ptr;
	}
};
long long solve(int N, vector<long long> A, vector<long long> B, vector<long long> T) {
	vector<long long> comp;
	for (int i = 0; i < N; ++i) {
		comp.push_back(A[i]);
		comp.push_back(B[i]);
	}
	sort(comp.begin(), comp.end());
	comp.erase(unique(comp.begin(), comp.end()), comp.end());
	int S = comp.size();
	state cur(0, 0);
	vector<state> dp(S);
	for (int i = 0; i < N; ++i) {
		int ptr = lower_bound(comp.begin(), comp.end(), A[i]) - comp.begin();
		dp[ptr] = max(dp[ptr], state(1, A[i] + T[i]));
	}
	for (int i = S - 2; i >= 0; --i) {
		dp[i] = max(dp[i], dp[i + 1]);
	}
	vector<vector<pair<state, long long> > > jumpin(S);
	vector<vector<int> > GA(S), GB(S);
	vector<int> perm(N);
	for (int i = 0; i < N; ++i) {
		int ptr = lower_bound(comp.begin(), comp.end(), A[i] + T[i]) - comp.begin();
		long long t = (comp[ptr] - A[i]) / T[i];
		jumpin[ptr].push_back(make_pair(state(t, A[i] + t * T[i]), A[i]));
		int pa = lower_bound(comp.begin(), comp.end(), A[i]) - comp.begin();
		int pb = lower_bound(comp.begin(), comp.end(), B[i]) - comp.begin();
		GA[pa].push_back(i);
		GB[pb].push_back(i);
		perm[i] = i;
	}
	sort(perm.begin(), perm.end(), [&](int i, int j) {
		return B[i] - T[i] < B[j] - T[j];
	});
	set<pair<long long, int> > sta;
	set<pair<long long, int> > stb;
	int ptra = 0, ptrb = 0;
	for (int i = 1; i < S; ++i) {
		for (int j : GA[i - 1]) {
			if (cur.ptr <= B[j] - T[j]) {
				stb.insert(make_pair(T[j], j));
			}
		}
		for (int j : GB[i - 1]) {
			sta.erase(make_pair(T[j], j));
		}
		if (cur.ptr > comp[i]) continue;
		state nxt = cur;
		while (ptra != S && comp[ptra] <= cur.ptr) {
			for (int j : GA[ptra]) {
				if (B[j] >= comp[i]) {
					sta.insert(make_pair(T[j], j));
				}
			}
			++ptra;
		}
		if (!sta.empty()) {
			int pos = sta.begin()->second;
			long long t = (comp[i] - cur.ptr) / T[pos];
			nxt = max(nxt, state(cur.cnt + t, cur.ptr + t * T[pos]));
		}
		for (pair<state, long long> j : jumpin[i]) {
			if (j.second > cur.ptr) {
				nxt = max(nxt, state(cur.cnt + j.first.cnt, j.first.ptr));
			}
		}
		cur = nxt;
		if (cur == state(0, 0)) continue;
		while (ptrb != N && cur.ptr > B[perm[ptrb]] - T[perm[ptrb]]) {
			stb.erase(make_pair(T[perm[ptrb]], perm[ptrb]));
			++ptrb;
		}
		if (!stb.empty()) {
			int pos = stb.begin()->second;
			nxt = max(nxt, state(cur.cnt + 1, cur.ptr + T[pos]));
		}
		if (dp[i].cnt != 0) {
			nxt = max(nxt, state(cur.cnt + 1, dp[i].ptr));
		}
		cur = nxt;
	}
	return cur.cnt;
}
long long solve_easy(int N, vector<long long> A, vector<long long> B, vector<long long> T) {
	vector<long long> comp;
	for (int i = 0; i < N; ++i) {
		comp.push_back(A[i]);
		comp.push_back(B[i]);
	}
	sort(comp.begin(), comp.end());
	comp.erase(unique(comp.begin(), comp.end()), comp.end());
	int S = comp.size();
	state cur = state(0, 0);
	for (int i = 0; i < S; ++i) {
		while (true) {
			state nxt = cur;
			for (int j = 0; j < N; ++j) {
				long long pl = max(cur.ptr, A[j]);
				long long pr = min(comp[i], B[j]);
				if (pl < pr) {
					long long cnt = (pr - pl) / T[j];
					nxt = max(nxt, state(cur.cnt + cnt, pl + T[j] * cnt));
				}
			}
			if (cur.cnt == nxt.cnt && cur.ptr == nxt.ptr) break;
			cur = nxt;
		}
	}
	return cur.cnt;
}
#include <random>
#include <string>
mt19937 mt(1912011750);
int rand_rng(int l, int r) {
	uniform_int_distribution<int> p(l, r - 1);
	return p(mt);
}
string to_string(vector<long long> arr) {
	string res = "[";
	for (int i = 0; i < arr.size(); ++i) {
		if (i) res += ", ";
		res += to_string(arr[i]);
	}
	res += "]";
	return res;
}
void random_gen() {
	for (int N = 1; N <= 100; ++N) {
		for (int rep = 1; rep <= 1000; ++rep) {
			vector<long long> A(N), B(N), T(N);
			for (int i = 0; i < N; ++i) {
				while (A[i] >= B[i]) {
					A[i] = rand_rng(1, 11);
					B[i] = rand_rng(1, 11);
				}
				T[i] = rand_rng(1, B[i] - A[i] + 1);
			}
			long long res1 = solve(N, A, B, T);
			long long res2 = solve_easy(N, A, B, T);
			if (res1 != res2) {
				cout << "N = " << N << " / Case #" << rep << ":" << endl;
				cout << "A = " << to_string(A) << endl;
				cout << "B = " << to_string(B) << endl;
				cout << "T = " << to_string(T) << endl;
				cout << "Returns: " << res1 << endl;
				cout << "Answer: " << res2 << endl;
				cout << endl;
			}
		}
		cout << "N = " << N << " Completed!" << endl;
	}
}
int main() {
	//random_gen();
	int N;
	cin >> N;
	vector<long long> A(N), B(N), T(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i] >> B[i] >> T[i];
	}
	long long ans = solve(N, A, B, T);
	cout << ans << endl;
	return 0;
}