#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

#define repi(i, a) for(typeof((a).begin()) i = (a).begin(), _##i = (a).end(); i != _##i; ++i)
#define sz(x) int((x).size())
const int MAXN = 11;
const int inf = 1 << 30;
string S;
int N;
string strs[MAXN];
char buf[12345678];

bool match(string &str, int a, int b) {
	int z = sz(str);
	if (a + z > b) {
		return false;
	}
	for(int i = 0; i < z; ++i) {
		if (str[i] != S[a + i]) {
			return false;
		}
	}
	return true;
}

int bad(int a, int b) {
	int m = inf;
	for(int i = 0; i < N; ++i) {
		if (match(strs[i], a, b)) {
			m = min(m, sz(strs[i]));
		}
	}
	if (m == inf) m = -1;
	return m;
}
#define p(x) cout << #x << ": " << x << endl;
int main() {
	scanf("%s", buf);
	S = string(buf);
	scanf("%d", &N);
	for(int i = 0; i < N; ++i) {
		scanf("%s", buf);
		strs[i] = string(buf);
	}
//	p(S);
//	p(sz(S));
//	p(N);
	int M = 0;
	int ans = 0;

	int L = sz(S);
	int end = L;
	for(int start = L; start >= 0; --start) {
		int b = bad(start, end);
		if (b != -1) {
			end = start + b - 1;
		}
//		p(start);
//		p(end);
		int l = end - start;
		if (l > M) {
			M = l;
			ans = start;
		}
	}
	printf("%d %d\n", M, ans);
	return 0;
}