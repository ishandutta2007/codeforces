#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define MOD
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

i64 gcd(i64 a, i64 b)
{
	while (b) {
		i64 tmp = a % b;
		a = b;
		b = tmp;
	}
	return a;
}

struct rational
{
	i64 a, b;

	rational(i64 a = 0, i64 b = 1) : a(a), b(b) {
		normalize();
	}

	void normalize()
	{
		if (b < 0) {
			a = -a;
			b = -b;
		}
		i64 g = gcd(a, b);
		a /= g;
		b /= g;
	}

	inline bool operator==(const rational& other) const {
		return a == other.a && b == other.b;
	}
	inline bool operator<(const rational& other) const {
		return a < other.a || (a == other.a && b < other.b);
	}

};
int N, K;
i64 A[101010], B[101010], C[101010];

bool is_cross(int i, int j)
{
	i64 det = (A[i] * B[j] - A[j] * B[i]);
	return det != 0;
}

pair<rational, rational> cross(int i, int j)
{
	i64 det = (A[i] * B[j] - A[j] * B[i]);
	return{ rational(B[j] * C[i] - B[i] * C[j], det), rational(-A[j] * C[i] + A[i] * C[j], det) };
}

vector<pair<int, int> > ans;

vector<pair<rational, int> > digest(int rt, vector<int> &tg)
{
	vector<pair<rational, int> > ret;
	for (int i : tg) if (i != rt) {
		if (is_cross(i, rt)) {
			auto pt = cross(i, rt);
			if (A[rt] == 0) ret.push_back({ pt.first, i });
			else ret.push_back({ pt.second, i });
		}
	}
	return ret;
}

bool solve(vector<int> &rem, int k)
{
	//printf("%d: ", k);
	//for (int a : rem) printf("%d ", a);
	//puts("");

	if (rem.size() == 0) return true;
	if (k == 0) return rem.size() == 0;

	if (rem.size() <= k * k) {
		auto dig = digest(rem[0], rem);
		sort(dig.begin(), dig.end());
		//printf("%d\n", dig.size());
		////for (auto a : dig) printf("%lld/%lld,%d ", a.first.a, a.first.b, a.second);
		//puts("");
		if (dig.size() == 0) {
			ans.push_back({ rem[0] + 1, -1 });
			vector<int> rem2;
			for (int i = 1; i < rem.size(); ++i) rem2.push_back(rem[i]);
			if (solve(rem2, k - 1)) return true;
			ans.pop_back();
			return false;

		}
		int ch = 1;
		for (int j = 0; j < dig.size(); ++j) {
			if (j == dig.size() - 1 || !(dig[j].first == dig[j + 1].first)) {
				ans.push_back({ rem[0] + 1, dig[j].second + 1 });
				vector<int> rem2;
				for (int k = 0; k < j + 1 - ch; ++k) rem2.push_back(dig[k].second);
				for (int k = j + 1; k < dig.size(); ++k) rem2.push_back(dig[k].second);
				for (int k = 0; k < rem.size(); ++k) if (k != 0 && !is_cross(rem[0], rem[k])) rem2.push_back(rem[k]);
				if (solve(rem2, k - 1)) return true;
				ans.pop_back();
				ch = 1;
			} else ++ch;
		}

		return false;
	}
	for (int i = 0; i <= k * k; ++i) {
		auto dig = digest(rem[i], rem);
		sort(dig.begin(), dig.end());

		int ch = 1;
		for (int j = 0; j < dig.size(); ++j) {
			//printf("%d %d: %lld %lld\n", i, j, dig[j].first.a, dig[j].first.b);
			if (j == dig.size() - 1 || !(dig[j].first  == dig[j + 1].first)) {
				if (ch >= k) {
					ans.push_back({ rem[i] + 1, dig[j].second + 1 });
					vector<int> rem2;
					for (int k = 0; k < j + 1 - ch; ++k) rem2.push_back(dig[k].second);
					for (int k = j + 1; k < dig.size(); ++k) rem2.push_back(dig[k].second);
					for (int k = 0; k < rem.size(); ++k) if (k != i && !is_cross(rem[i], rem[k])) rem2.push_back(rem[k]);

					if (solve(rem2, k - 1)) return true;
					ans.pop_back();
					return false;
				}
				ch = 1;
			} else ++ch;
		}
	}
	return false;
}

int main()
{
	scanf("%d%d", &N, &K);
	for (int i = 0; i < N; ++i) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		A[i] = a;
		B[i] = b;
		C[i] = c;
	}

	vector<int> rem;
	for (int i = 0; i < N; ++i) rem.push_back(i);

	if (solve(rem, K)) {
		puts("YES");
		printf("%d\n", ans.size());
		for (auto a : ans) printf("%d %d\n", a.first, a.second);
	} else puts("NO");

	return 0;
}