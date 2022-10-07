#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const int MAXN = 10010000;
const int MAXP = 1001000;
const ll MAXANS = 1E13;

#define sz(x) int((x).size())
int sieve[MAXN];
vector<int> primes;
int nump = 0;

void prec() {
	for(int i = 0; i < MAXN; ++i) {
		sieve[i] = -1;
	}
	sieve[0] = sieve[1] = 0;
	for(int i = 0; i < MAXN; ++i) {
		if (sieve[i] == -1) {
			primes.push_back(i);
			sieve[i] = nump;
			for(int j = i; j <= (MAXN - 1) / i; ++j) {
				if (sieve[i * j] == -1) {
					sieve[i * j] = nump;
				}
			}
			++nump;
		}
	}
}

ll ar[MAXN];

void go(int n, int cnt) {
	while (n != 1) {
		int p = sieve[n];
		ar[p] += cnt;
		n /= primes[p];
	}
}

bool works(ll n) {
	for(int i = 0; i < nump; ++i) {
		ll tmp = n;
		ll sum = 0;
		while (tmp) {
			sum += tmp / primes[i];
			tmp /= primes[i];
		}
		if (sum < ar[i]) {
			return false;
		}
	}
	return true;
}

int cnt[MAXN];

int N;

int main() {
	prec();
	scanf("%d", &N);
	for(int i = 0; i < N; ++i) {
		int tmp;
		scanf("%d", &tmp);
		++cnt[tmp];
	}

	int cur = 0;
	for(int i = MAXN - 1; i > 0; --i) {
		cur += cnt[i];
		if (cur)
		go(i, cur);
	}

	ll low = 1;
	ll high = MAXANS;

	while (low < high) {
		ll mid = low + (high - low) / 2;
		if (works(mid)) {
			high = mid;
		} else {
			low = mid + 1;
		}
	}

	cout << low << endl;
	return 0;
}