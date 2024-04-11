#include <string>
#include <vector>
#include <iostream>
using namespace std;
pair<string, string> getlast(int K, string S, string T) {
	int N = T.size();
	string L(K, '?');
	string finl;
	for (int i = 0; i < N; ++i) {
		for (char j = 'a'; j < T[i] + (i + 1 == N ? 1 : 0); ++j) {
			if (L[S[i] - 'a'] != j && (L[S[i] - 'a'] != '?' || L.find(j) != string::npos)) {
				continue;
			}
			string candl = L;
			candl[S[i] - 'a'] = j;
			vector<bool> used(K);
			for (int k = 0; k < K; ++k) {
				if (candl[k] != '?') {
					used[candl[k] - 'a'] = true;
				}
			}
			int ptr = K - 1;
			for (int k = i + 1; k < N; ++k) {
				while (ptr >= 0 && used[ptr]) --ptr;
				if (candl[S[k] - 'a'] == '?') {
					candl[S[k] - 'a'] = ptr + 'a', --ptr;
				}
			}
			for (int k = 0; k < K; ++k) {
				while (ptr >= 0 && used[ptr]) --ptr;
				if (candl[k] == '?') candl[k] = ptr + 'a', --ptr;
			}
			finl = candl;
		}
		if (L[S[i] - 'a'] != T[i] && (L[S[i] - 'a'] != '?' || L.find(T[i]) != string::npos)) break;
		L[S[i] - 'a'] = T[i];
	}
	if (finl.empty()) return make_pair(string(), string());
	string ans;
	for (int i = 0; i < N; ++i) {
		ans += finl[S[i] - 'a'];
	}
	return make_pair(ans, finl);
}
#include <random>
#include <algorithm>
pair<string, string> getlast_easy(int K, string S, string B) {
	vector<int> p(K);
	for (int i = 0; i < K; ++i) p[i] = i;
	int N = S.size();
	string curmax, curfunc;
	do {
		string trans(N, '?');
		for (int i = 0; i < N; ++i) trans[i] = p[S[i] - 'a'] + 'a';
		string func;
		for (int i = 0; i < K; ++i) func += p[i] + 'a';
		if (trans <= B && curmax < trans || (curmax == trans && curfunc < func)) {
			curmax = trans;
			curfunc = func;
		}
	} while (next_permutation(p.begin(), p.end()));
	return make_pair(curmax, curfunc);
}
int main() {
	/*
	std::random_device rd;
	int K = 3;
	uniform_int_distribution<int> p(0, K - 1);
	for (int N = 3; N <= 10; ++N) {
		for (int rep = 1; rep <= 10000; ++rep) {
			string S, B;
			for (int i = 0; i < N; ++i) S += p(rd) + 'a';
			for (int i = 0; i < N; ++i) B += p(rd) + 'a';
			pair<string, string> res1 = getlast(K, S, B);
			pair<string, string> res2 = getlast_easy(K, S, B);
			if (res1 != res2) {
				cout << "N = " << N << " / Case #" << rep << " / S = " << S << " / B = " << B << " / Returns = (" << res1.first << ", " << res1.second << ") / Answer = (" << res2.first << ", " << res2.second << ")" << endl;
			}
		}
	}
	*/
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int Q;
	cin >> Q;
	while (Q--) {
		int K;
		cin >> K;
		string S, A, B;
		cin >> S >> A >> B;
		pair<string, string> last = getlast(K, S, B);
		cout << (last.first >= A ? string("YES\n") + last.second : "NO") << '\n';
	}
	return 0;
}