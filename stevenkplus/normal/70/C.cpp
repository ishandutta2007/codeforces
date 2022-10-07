#include <cstdio>
#include <map>

using namespace std;

typedef long long ll;

const int MAXN = 100000;

ll rev[MAXN];

struct cmp {
	bool operator() (const int &a, const int &b) const {
		return a * rev[b] < b * rev[a];
	}
};

map<int, int, cmp> map1, map2;

int X, Y, W;

int reverse(int x) {
	int ret = 0;
	while (x) {
		int dig = x % 10;
		x /= 10;
		ret = 10 * ret + dig;
	}
	return ret;
}

int main() {
	scanf("%d %d %d", &X, &Y, &W);

	for(int i = 0; i < MAXN; ++i) {
		rev[i] = reverse(i);
		if (reverse(rev[i]) != i) rev[i] = 0;
	}

	int a = 0;
	int b = 0;
	ll cnt = 0;
	while (b + 1 < MAXN) {
		++b;
		++map2[b];
	}

	int ansx = -1, ansy;
	ll best = -1;

	while (a < MAXN && b > 0) {
		if (cnt < W) {
			++a;
			if (rev[a]) {
				cnt += map2[rev[a]];
			}
			++map1[a];
		} else {
			if (a <= X && b <= Y) {
				ll prod = a;
				prod *= b;
				if ((best == -1) || prod < best) {
					best = prod;
					ansx = a;
					ansy = b;
				}
			}
			if (rev[b]) {
				cnt -= map1[rev[b]];
			}
			--map2[b];
			--b;
		}
	}

	if (ansx != -1) {
		printf("%d %d\n", ansx, ansy);
	} else {
		printf("-1\n");
	}

	return 0;
}