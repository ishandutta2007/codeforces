#include <bits/stdc++.h>
#include <random>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back

typedef long long ll;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
struct edge { int v, w; };
const int INF = INT_MAX / 2;
const int MOD = 1e9 + 7;

map<int, int> mp1;

bool check1(vector<int> p) {
	int N = p.size() - 1;
	for (int i = 1; i <= N; i++)
		if (p[i] == i || (p[i] & i))
			return false;
	return true;
}

void f(int N) {
	if (!N) return;
	int n;
	for (n = 1; n * 2 <= N; n *= 2);
	for (int x = n; x <= N; x++) {
		int y = n * 2 - 1 - x;
		mp1[x] = y, mp1[y] = x;
	}
	N -= (N - n + 1) * 2;
	f(N);
}

void solve1(int N) {
	if (N % 2) {
		cout << "NO" << endl;
		return;
	}
	cout << "YES" << endl;
	f(N);
	vector<int> p(N + 1);
	for (int x = 1; x <= N; x++) {
		p[x] = mp1[x];
		printf("%d ", p[x]);
	}
	cout << endl;
	if (!check1(p)) cout << "ERR" << endl;
}

bool check2(vector<int> p) {
	int N = p.size() - 1;
	for (int i = 1; i <= N; i++)
		if (p[i] == i || !(p[i] & i))
			return false;
	return true;
}

vector<int> unko(int N) {
	vector<int> p(N + 1);
	rep(i, N + 1) p[i] = i;
	do {
		if (check2(p)) return p;
	} while (next_permutation(p.begin() + 1, p.end()));
	return {};
}

void solve2(int N) {
	int n;
	for (n = 1; n * 2 <= N; n *= 2);
	if (n == N) {
		cout << "NO" << endl;
		return;
	}
	if (N <= 10) {
		vector<int> p = unko(N);
		if (p.empty()) cout << "NO" << endl;
		else {
			cout << "YES" << endl;
			for (int i = 1; i <= N; i++) cout << p[i] << ' ';
			cout << endl;
		}
		return;
	}
	vector<int> p = unko(7);
	p.resize(N + 1);
	for (int x = 8; x <= N;) {
		if (x + 2 == N) {
			p[x] = x + 1, p[x + 1] = x + 2, p[x + 2] = x;
			x += 3;
		}
		else {
			p[x] = x + 1, p[x + 1] = x;
			x += 2;
		}
	}
	cout << "YES" << endl;
	for (int i = 1; i <= N; i++) printf("%d ", p[i]);
	cout << endl;
	if (!check2(p)) cout << "ERR" << endl;
}

int main() {
	int N; cin >> N;
	solve1(N), solve2(N);
}