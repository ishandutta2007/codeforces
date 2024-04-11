#include <cstdio>

using namespace std;

typedef long long ll;

const ll MOD = 1E9 + 7;

const int MAXC = 20;

int ar[MAXC];
int M;

int numluck(int x) {
	int sum = 0;
	while (x > 0) {
		int tmp = x % 10;
		if (tmp == 4 || tmp == 7) {
			sum++;
		}
		x /= 10;
	}
	return sum;
}
int chz(int a, int b) {
	int s = 1;
	for(int i = 0; i < b; ++i) {
		s *= (a - i);
		s /= (i + 1);
	}
	return s;
}
int gay[10][10];
int exp(int a, int b) {
	int s = 1;
	for(int i = 0; i < b; ++i) {
		s *= a;
	}
	return s;
}

void compgay() {
	for(int i = 0; i < 10; ++i) {
		for(int j = 0; j <= i; ++j) {
			gay[i][j] = chz(i, j) * (1 << j) * exp(8, i - j);
		}
	}
}
void comp() {
//	for(int i = 1; i <= M; ++i) {
//		ar[numluck(i)]++;
//	}
//	return;
	compgay();
//	for(int i = 0; i < 10; ++i) {
//		printf("len = %d\n", i);
//		for(int j = 0; j <= i; ++j) {
//			printf("num = %d val = %d ", j, gay[i][j]);
//		}
//		printf("\n\n");
//	}
	int md = 1E9;
	int x = M;
	int s = 0;
	int len = 9;
	while (md > 0) {
		int f = x / md;
//		printf("f = %d, len = %d\n", f, len);
		for(int i = 0; i < f; ++i) {
			int p = (i == 4 || i == 7) ? 1 : 0;
			for(int a = 0; a <= len; ++a) {
				ar[a + p + s] += gay[len][a];
			}
		}
		if (f == 4 || f == 7) {
			s++;
		}
		x %= md;
		md /= 10;
		len--;
	}
	ar[s]++;
	ar[0]--; // can't be 0
//	for(int i = 0; i < 10; ++i) {
//		printf("ar[%d] = %d\n", i, ar[i]);
//	}

}

const ll inv[] = {1, 500000004, 333333336, 250000002, 400000003, 166666668};

ll choose(ll a, int b) {
	ll prod = 1;
	for(int x = 0; x < b; ++x) {
		(prod *= (a - x)) %= MOD;
		(prod *= inv[x]) %= MOD;
	}
	return prod;
}	

ll ways = 0;
int tmp[MAXC];
int cur = 0;
void rec(int n) {
	if (n == MAXC) {
		if (cur != 6) {
			return;
		}
		int s = 0;
		for(int i = 0; i < MAXC; ++i) {
			s += tmp[i] * i;
		}
		ll w = 1;
		ll poss = 0;
		for(int x = s + 1; x < MAXC; ++x) {
			poss += ar[x] - tmp[x];
		}
		for(int i = 0; i < MAXC; ++i) {
			(w *= choose(ar[i], tmp[i])) %= MOD;
		}
		(w *= 720) %= MOD;
		(w *= poss) %= MOD;
		(ways += w) %= MOD;	
	} else {
		if (cur < 6 && tmp[n] < ar[n]) {
			tmp[n]++;
			cur++;
			rec(n);
			cur--;
			tmp[n]--;
		}
		rec(n + 1);
	}
}
int main() {
	scanf("%d", &M);
	comp();
	rec(0);
	printf("%I64d\n", ways);
//	printf("%lld\n", ways);
	return 0;
}