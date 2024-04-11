#include <random>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const long long large_prime_1 = (1LL << 61) - 1;
const long long large_prime_2 = (1LL << 61) + 15;
mt19937 mt(2003071902);
long long rand_rng(long long l, long long r) {
	uniform_int_distribution<long long> p(l, r - 1);
	return p(mt);
}
long long gcd(long long x, long long y) {
	if (y == 0) return x;
	return gcd(y, x % y);
}
long long solve(int N, int M, vector<long long> C, vector<int> A, vector<int> B) {
	vector<pair<long long, long long> > p(N);
	for (int i = 0; i < N; ++i) {
		p[i] = make_pair(rand_rng(0, large_prime_1), rand_rng(0, large_prime_2));
	}
	vector<pair<long long, long long> > q(N);
	for (int i = 0; i < M; ++i) {
		q[B[i]].first += p[A[i]].first;
		if (q[B[i]].first >= large_prime_1) q[B[i]].first -= large_prime_1;
		q[B[i]].second += p[A[i]].second;
		if (q[B[i]].second >= large_prime_2) q[B[i]].second -= large_prime_2;
	}
	vector<pair<long long, long long> > sq = q;
	sort(sq.begin(), sq.end());
	sq.erase(unique(sq.begin(), sq.end()), sq.end());
	vector<long long> h(sq.size());
	for (int i = 0; i < N; ++i) {
		int ptr = lower_bound(sq.begin(), sq.end(), q[i]) - sq.begin();
		h[ptr] += C[i];
	}
	long long g = 0;
	for (int i = 0; i < sq.size(); ++i) {
		if (sq[i] == make_pair(0LL, 0LL)) continue;
		if (g == -1) {
			g = h[i];
		}
		else {
			g = gcd(g, h[i]);
		}
	}
	return g;
}
long long solve_easy(int N, int M, vector<long long> C, vector<int> A, vector<int> B) {
	vector<long long> seq;
	for (int i = 0; i < 1 << N; ++i) {
		int bit = 0;
		for (int j = 0; j < M; ++j) {
			if ((i >> A[j]) & 1) bit |= 1 << B[j];
		}
		long long sum = 0;
		for (int j = 0; j < N; ++j) {
			if ((bit >> j) & 1) sum += C[j];
		}
		seq.push_back(sum);
	}
	long long g = seq[0];
	for (int i = 1; i < seq.size(); ++i) {
		g = gcd(g, seq[i]);
	}
	return g;
}
#include <string>
string to_string(vector<int> A) {
	string res = "[";
	for (int i = 0; i < A.size(); ++i) {
		if (i) res += ", ";
		res += to_string(A[i]);
	}
	res += "]";
	return res;
}
string to_string(vector<long long> A) {
	string res = "[";
	for (int i = 0; i < A.size(); ++i) {
		if (i) res += ", ";
		res += to_string(A[i]);
	}
	res += "]";
	return res;
}
void random_gen() {
	const int samples = 10000;
	int N = 3;
	for (int i = 0; i < samples; ++i) {
		vector<long long> C(N);
		for (int j = 0; j < N; ++j) {
			C[j] = rand_rng(1, 101);
		}
		int M = 0;
		vector<int> A, B;
		for (int j = 0; j < N; ++j) {
			for (int k = 0; k < N; ++k) {
				if (rand_rng(0, 2) == 0) {
					A.push_back(j);
					B.push_back(k);
					++M;
				}
			}
		}
		long long res1 = solve(N, M, C, A, B);
		long long res2 = solve_easy(N, M, C, A, B);
		if (res1 != res2) {
			cout << "Case #" << i << ":" << endl;
			cout << "N = " << N << " / M = " << M << endl;
			cout << "C = " << to_string(C) << endl;
			cout << "A = " << to_string(A) << endl;
			cout << "B = " << to_string(B) << endl;
			cout << "Returns: " << res1 << endl;
			cout << "Answer: " << res2 << endl;
			cout << endl;
		}
	}
}
int main() {
	// random_gen();
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int Q;
	cin >> Q;
	while (Q--) {
		int N, M;
		cin >> N >> M;
		vector<long long> C(N);
		for (int i = 0; i < N; ++i) {
			cin >> C[i];
		}
		vector<int> A(M), B(M);
		for (int i = 0; i < M; ++i) {
			cin >> A[i] >> B[i];
			--A[i], --B[i];
		}
		long long res = solve(N, M, C, A, B);
		cout << res << '\n';
	}
	return 0;
}