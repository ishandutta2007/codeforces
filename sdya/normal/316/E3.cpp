#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <string>
#include <cstring>
#include <cmath>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const long long P = 1000000000LL;
const int maxN = 210000;
int n, m, a[maxN];
long long f[maxN];
long long s[maxN];

struct State {
	long long a0, a1, b;
	State() {
	}
	State(long long a0, long long a1, long long b) : a0(a0), a1(a1), b(b) {
	}
};

State Merge(State A, State B) {
	long long a0 = A.a0 + f[A.b - 1] * B.a0 + f[A.b] * B.a1;
	long long a1 = A.a1 + f[A.b] * B.a0 + f[A.b + 1] * B.a1;
	return State(a0 % P, a1 % P, A.b + B.b);
}

State Merge(State A, long long value) {
	long long a0 = A.a0 + s[A.b - 1] * value;
	long long a1 = A.a1 + s[A.b] * value;
	return State(a0 % P, a1 % P, A.b);
}

State t[4 * maxN];
long long values[4 * maxN];

State get(int i, int cl, int cr, int l, int r, long long add) {
	if (l > r) {
		return State(0, 0, 0);
	}
	add = (add + values[i]) % P;
	if (cl == l && cr == r) {
		return Merge(t[i], add);
	}

	if (l > (cl + cr) / 2) {
		return get(2 * i + 1, (cl + cr) / 2 + 1, cr, l, r, add);
	}
	if (r <= (cl + cr) / 2) {
		return get(2 * i, cl, (cl + cr) / 2, l, r, add);
	}

	State A = get(2 * i, cl, (cl + cr) / 2, l, (cl + cr) / 2, add);
	State B = get(2 * i + 1, (cl + cr) / 2 + 1, cr, (cl + cr) / 2 + 1, r, add);
	return Merge(A, B);
}

void update(int i, int cl, int cr, int l, int r, long long add) {
	if (cl == l && cr == r) {
		values[i] = (values[i] + add) % P;
		return;
	}

	if (l > (cl + cr) / 2) {
		update(2 * i + 1, (cl + cr) / 2 + 1, cr, l, r, add);
	} else if (r <= (cl + cr) / 2) {
		update(2 * i, cl, (cl + cr) / 2, l, r, add);
	} else {
		update(2 * i, cl, (cl + cr) / 2, l, (cl + cr) / 2, add);
		update(2 * i + 1, (cl + cr) / 2 + 1, cr, (cl + cr) / 2 + 1, r, add);
	}

	State A = Merge(t[2 * i], values[2 * i]);
	State B = Merge(t[2 * i + 1], values[2 * i + 1]);
	t[i] = Merge(A, B);
}

void Build(int i, int l, int r) {
	if (l == r) {
		t[i] = State(0, a[l], 1);
		return;
	}
	Build(2 * i, l, (l + r) / 2);
	Build(2 * i + 1, (l + r) / 2 + 1, r);
	t[i] = Merge(t[2 * i], t[2 * i + 1]);
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}

	f[0] = s[0] = 0;
	f[1] = s[1] = 1;
	for (int i = 2; i < maxN; ++i) {
		f[i] = f[i - 1] + f[i - 2];
		f[i] %= P;
		s[i] = s[i - 1] + f[i];
		s[i] %= P;
	}

	Build(1, 0, n - 1);
	for (int i = 1; i <= m; ++i) {
		int mode;
		scanf("%d", &mode);
		if (mode == 1) {
			int index, value;
			scanf("%d%d", &index, &value);
			--index;
			State current = get(1, 0, n - 1, index, index, 0);
			long long diff = value - current.a1;
			diff = ((diff % P) + P) % P;
			update(1, 0, n - 1, index, index, diff);
		} else if (mode == 2) {
			int left, right;
			scanf("%d%d", &left, &right);
			--left;
			--right;
			State current = get(1, 0, n - 1, left, right, 0);
			long long res = ((current.a1 % P) + P) % P;
			printf("%d\n", (int)(res));
		} else {
			int left, right, add;
			scanf("%d%d%d", &left, &right, &add);
			--left;
			--right;
			update(1, 0, n - 1, left, right, add);
		}
	}


	return 0;
}