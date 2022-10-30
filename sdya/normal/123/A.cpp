#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <bitset>
#include <ctime>
#include <unordered_map>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

bool isPrime(int n) {
	for (int i = 2; i * i <= n; ++i) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

set < pair < int, int > > S;

const int maxN = 1100;
vector < int > g[maxN];

vector < vector < int > > comps;
bool used[maxN];

void dfs(int v, vector < int > *output) {
	used[v] = true;
	output->push_back(v);
	for (int i = 0; i < g[v].size(); ++i) {
		if (!used[g[v][i]]) {
			dfs(g[v][i], output);
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	string s;
	cin >> s;

	int n = s.size();
	vector < int > primes;
	for (int i = 2; i <= n; ++i) {
		if (isPrime(i)) {
			primes.push_back(i);
		}
	}

	for (int i = 0; i < primes.size(); ++i) {
		for (int j = 2 * primes[i]; j <= n; j += primes[i]) {
			g[j - primes[i] - 1].push_back(j - 1);
			g[j - 1].push_back(j - primes[i] - 1);
		}
	}

	vector < int > cnt(26);
	for (int i = 0; i < n; ++i) {
		++cnt[s[i] - 'a'];
	}

	set < pair < int, int > > T;
	for (int i = 0; i < 26; ++i) {
		if (cnt[i] > 0) {
			T.insert(make_pair(-cnt[i], i));
		}
	}

	for (int i = 0; i < n; ++i) {
		if (!used[i]) {
			vector < int > current;
			dfs(i, &current);
			comps.push_back(current);
		}
	}

	for (int i = 0; i < comps.size(); ++i) {
		S.insert(make_pair(-comps[i].size(), i));
	}

	string res(n, ' ');
	while (!S.empty()) {
		pair < int, int > p = *S.begin();
		S.erase(S.begin());

		if (T.empty()) {
			cout << "NO" << endl;
			return 0;
		}
		pair < int, int > t = *T.begin();
		T.erase(T.begin());

		int x = -p.first;
		int y = -t.first;
		if (x > y) {
			cout << "NO" << endl;
			return 0;
		}

		y -= x;
		for (int i = 0; i < comps[p.second].size(); ++i) {
			res[comps[p.second][i]] = 'a' + t.second;
		}
		T.insert(make_pair(-y, t.second));
	}

	cout << "YES" << endl;
	cout << res << endl;

	return 0;
}