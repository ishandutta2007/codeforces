#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;
typedef std::vector<std::vector<ll>> matrix;

const ll Mod = 1000*1000*1000+7;

int N, B, K, X;

void add(ll &a, ll b) {
	a += b;
	if (a >= Mod) a -= Mod;
}
matrix make(int N) {
	std::vector<std::vector<ll>> v(N);
	for (auto &w : v) w.resize(N);
	return v;
}
void init(matrix &m) {
	for (int i = 0; i < sz(m); i++) m[i][i] = 1;
}
matrix operator*(const matrix &m, const matrix &n) {
	int N = sz(m); matrix p = make(N);
	for (int y = 0; y < N; y++) for (int x = 0; x < N; x++) for (int k = 0; k < N; k++)
		add(p[y][x], (m[y][k] * n[k][x]) % Mod);
	return p;
}
matrix modexp(matrix b, int e) {
	matrix m = make(sz(b)); init(m);
	while (e) {
		if (e&1) m = m*b;
		e >>= 1;
		b = b*b;
	}
	return m;
}

int main()
{
	scanf("%d%d%d%d", &N, &B, &K, &X);
	matrix m = make(X);
	for (int i = 0; i < N; i++) {
		int a; scanf("%d", &a);
		for (int y = 0; y < X; y++) m[y][(10*y + a) % X]++;
	}
	m = modexp(m, B);
	printf("%lld\n", m[0][K]);
}