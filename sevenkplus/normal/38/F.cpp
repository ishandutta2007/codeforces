#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pct __builtin_popcount

#define N 33
int n;
string s[N];

map<string, pair<bool, PII> > F;

int cnt(string x) {
	int S = 0;
	for (int i = 0; i < n; i ++)
		if (s[i].find(x) != -1) S++;
	return S;
}

pair<bool, PII> ff(string x) {
	if (F.find(x) != F.end()) return F[x];
	pair<bool, PII> S;
	int ss = 0, ma = 0;
	for (auto c : x) {
		ss += c-'a'+1;
		ma = max(ma, c-'a'+1);
	}
	for (int i = 0; i < 26*2; i ++) {
		string y;
		int c = i%26;
		if (i < 26) {
			y = string(1, (char)('a'+c)) + x;
		} else {
			y = x + string(1, (char)('a'+c));
		}
		int z = cnt(y);
		if (!z) continue;
		int score = (ss + c+1) * max(ma, c+1) + z;
		auto T = ff(y);
		auto U = mp(!T.fi, mp(T.se.se + score, T.se.fi));
		if (S.fi < U.fi || S.fi == U.fi && S.se.fi < U.se.fi || S.fi == U.fi && S.se.fi == U.se.fi && S.se.se > U.se.se) {
			S = U;
		}
	}
	return F[x] = S;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i ++) cin >> s[i];
	auto S = ff("");
	puts(S.fi? "First" : "Second");
	printf("%d %d\n", S.se.fi, S.se.se);
	return 0;
}