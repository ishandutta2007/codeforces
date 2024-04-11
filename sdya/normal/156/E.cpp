#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

vector < int > primes;

bool isPrime(int n) {
	for (int i = 2; i * i <= n; ++i) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

const int maxN = 11000;
int n;
long long a[maxN];
vector < vector < int > > p;
vector < long long > mod;

long long getDivisor(long long x, vector < int > primes) {
	int res = 101;
	for (int i = 0; i < primes.size(); ++i) {
		if (x % (long long)(primes[i]) == 0) {
			res = min(res, primes[i]);
		}
	}
	return (res == 101 ? -1 : res);
}

map < long long, vector < long long > > M;

long long pw[16];
int d;
string s;
long long c;
int visited[maxN], c_visited;
int id;

inline int getValue(char c) {
	if (c >= '0' && c <= '9') {
		return c - '0';
	}
	return 10 + c - 'A';
}

int pr[20][20];
int vl[20];

int prmod[maxN][5];

void rec(int index, int value) {
	if (value >= n) {
		return;
	}
	if (index < 0) {
		visited[c_visited++] = value;
		return;
	}

	if (vl[index] != -1) {
		rec(index - 1, value + pr[index][vl[index]]);
	} else {
		for (int i = 0; i < d; ++i) {
			rec(index - 1, i * pw[index] + value);
		}
	}
}

void solve() {
	pw[0] = 1LL;
	for (int i = 1; i < 16; ++i) {
		pw[i] = (pw[i - 1] * (long long)(d));
	}
	for (int i = 0; i < 16; ++i) {
		for (int j = 0; j < d; ++j) {
			pr[i][j] = pw[i] * j;
		}
	}
	while (s.size() > 14) {
		if (s[0] == '0' || s[0] == '?') {
			s = s.substr(1);
		} else {
			break;
		}
	}
	while (!s.empty() && s[0] == '0') {
		s = s.substr(1);
	}
	if (s.size() > 14) {
		long long value = (c + 1);
		cout << getDivisor(value, primes) << endl;
		return ;
	}

	while (!s.empty()) {
		if (pw[s.size() - 1] >= n) {
			if (s[0] != '?' && s[0] != '0') {
				long long value = (c + 1);
				cout << getDivisor(value, primes) << endl;
				return ;
			}
			s = s.substr(1);
		} else {
			break;
		}
	}
	
	reverse(s.begin(), s.end());
	for (int i = 0; i < s.size(); ++i) {
		vl[i] = getValue(s[i]);
		if (s[i] == '?') {
			vl[i] = -1;
		}
	}
	c_visited = 0;
	rec((int)(s.size()) - 1, 0);
	long long hash = 0;
	for (int i = 0; i < c_visited; ++i) {
		hash = hash * 137LL + (visited[i] + 1);
	}
	if (M.count(hash)) {
		vector < long long > cur = M[hash];
		long long res = 101;
		for (int i = 0; i < cur.size(); ++i) {
			if (getDivisor(cur[i] + c, p[i]) != -1) {
				res = min(getDivisor(cur[i] + c, p[i]), res);
			}
		}
		if (res == 101) {
			res = -1;
		}
		cout << res << endl;
		return ;
	}
	vector < long long > values(p.size());
	for (int i = 0; i < mod.size(); ++i) {
		long long score = 1LL;
		for (int j = 0; j < c_visited; ++j) {
			score = (score * prmod[visited[j]][i]) % mod[i];
		}
		values[i] = score;
	}
	M[hash] = values;
	long long res = 101;
	for (int i = 0; i < values.size(); ++i) {
		if (getDivisor(values[i] + c, p[i]) != -1) {
			res = min(getDivisor(values[i] + c, p[i]), res);
		}
	}
	if (res == 101) {
		res = -1;
	}
	cout << res << endl;
}

void gen() {
	int n = 10000;
	cout << n << endl;
	for (int i = 0; i < n; ++i) {
		cout << rand() << " ";
	}
	cout << endl;
	int m = 30000;
	cout << m << endl;
	for (int i = 0; i < m; ++i) {
		int d = 2;
		string s;
		for (int i = 0; i < 13; ++i) {
			s += (rand() % 100 < 99 ? '?' : (rand() % 2) + '0');
		}
		int c = rand();
		cout << d << " " << s << " " << c << endl;
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	//gen();

	for (int i = 2; i <= 100; ++i) {
		if (isPrime(i)) {
			primes.push_back(i);
		}
	}
	p.resize(4);
	mod.assign(4, 1);
	for (int i = primes.size() - 1; i >= 0; --i) {
		int index = 0;
		for (int j = 0; j < 4; ++j) {
			if (mod[j] < mod[index]) {
				index = j;
			}
		}
		p[index].push_back(primes[i]);
		mod[index] *= primes[i];
	}
	/*for (int i = 0; i < primes.size();) {
		long long start = 1;
		vector < int > current;
		while (i < primes.size() && start * (long long)(primes[i]) <= 2000000000LL) {
			current.push_back(primes[i]);
			start *= (long long)(primes[i]);
			++i;
		}
		p.push_back(current);
		mod.push_back(start);
	}*/
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		for (int j = 0; j < mod.size(); ++j) {
			prmod[i][j] = a[i] % mod[j];
		}
	}

	int m;
	cin >> m;
	for (int i = 0; i < m; ++i) {
		cin >> d >> s >> c;
		solve();
	}

	cerr << clock() << endl;

	return 0;
}