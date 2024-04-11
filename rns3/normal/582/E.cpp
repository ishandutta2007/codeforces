#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

#define N 505
#define M 65536

const int MOD = 1000000007;

char s[N];
vector <int> V;
vector <int> x, y;

void add(int &x, int y) {
	x += y;
	if (x >= MOD) x -= MOD;
}

void sub(int &x, int y) {
	x -= y;
	if (x < 0) x += MOD;
}

void mul(int &x, int y) {
	x = 1LL * x * y % MOD;
}

vector <int> operator & (const vector <int> &a, const vector <int> &b) {
	x = a, y = b;
	for (int i = 0; i < 16; i ++) {
		for (int j = 0; j < M; j ++) if ((j & (1 << i)) == 0) {
			add(x[j], x[j + (1 << i)]);
			add(y[j], y[j + (1 << i)]);
		}
	}
	for (int i = 0; i < M; i ++) mul(x[i], y[i]);
	for (int i = 0; i < 16; i ++) {
		for (int j = 0; j < M; j ++) if ((j & (1 << i)) == 0) {
			sub(x[j], x[j + (1 << i)]);
		}
	}
	return x;
}

vector <int> operator | (const vector <int> &a, const vector <int> &b) {
	x = a, y = b;
	for (int i = 0; i < 16; i ++) {
		for (int j = 0; j < M; j ++) if ((j & (1 << i))) {
			add(x[j], x[j - (1 << i)]);
			add(y[j], y[j - (1 << i)]);
		}
	}
	for (int i = 0; i < M; i ++) mul(x[i], y[i]);
	for (int i = 0; i < 16; i ++) {
		for (int j = 0; j < M; j ++) if ((j & (1 << i))) {
			sub(x[j], x[j - (1 << i)]);
		}
	}
	return x;
}

vector <int> operator + (const vector <int> &a, const vector <int> &b) {
	vector <int> x(M);
	for (int i = 0; i < M; i ++) {
		x[i] = a[i] + b[i];
		if (x[i] >= MOD) x[i] -= MOD;
	}
	return x;
}

void calc(int l, int r, vector <int> &V) {
	V.clear(), V.resize(M);
	for (int i = 0; i < M; i ++) V[i] = 0;
	if (l == r) {
		if (s[l] == 'A' || s[l] == '?') V[65280] ++; //1111111100000000
		if (s[l] == 'B' || s[l] == '?') V[61680] ++; //1111000011110000
		if (s[l] == 'C' || s[l] == '?') V[52428] ++; //1100110011001100
		if (s[l] == 'D' || s[l] == '?') V[43690] ++; //1010101010101010
		if (s[l] == 'a' || s[l] == '?') V[255] ++;   //0000000011111111
		if (s[l] == 'b' || s[l] == '?') V[3855] ++;  //0000111100001111
		if (s[l] == 'c' || s[l] == '?') V[13107] ++; //0011001100110011
		if (s[l] == 'd' || s[l] == '?') V[21845] ++; //0101010101010101
		return;
	}
	int pos, cur = 0;
	for (int i = l; i <= r; i ++) {
		if (s[i] == '(') cur ++;
		else if (s[i] == ')') cur --;
		else if (!cur) {
			pos = i;
			break;
		}
	}
	vector <int> a, b;
	calc(l + 1, pos - 2, a);
	calc(pos + 2, r - 1, b);
	if (s[pos] == '&') V = a & b;
	else if (s[pos] == '|') V = a | b;
	else V = (a & b) + (a | b);
}

int a[M], b[M];

main() {
	scanf("%s", s);
	int len = strlen(s), q;
	calc(0, len - 1, V);
	scanf("%d", &q);
	for (int i = 0; i < q; i ++) {
		int state = 0, val;
		for (int j = 0; j < 4; j ++) {
			scanf("%d", &val);
			state = state << 1 | val;
		}
		a[i] = state;
		scanf("%d", b + i);
	}
	int rlt = 0;
	for (int i = 0, j; i < M; i ++) {
		for (j = 0; j < q; j ++) {
			if (((i >> a[j]) & 1) != b[j]) break;
		}
		if (j == q) add(rlt, V[i]);
	}
	printf("%d\n", rlt);
}