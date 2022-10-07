#include <cstdio>
#include <iostream>

using namespace std;

typedef long long ll;

const int MAXN = 200100;

bool working[MAXN];
bool nosol[MAXN];
ll dp[MAXN];
ll ar[MAXN];

int N;

ll get(int k) {
	if (nosol[k]) return 0;
	ll &ret = dp[k];
	if (ret) {
		if (working[k]) {
			nosol[k] = true;
			return 0;
		}
		return ret - 1;
	}

	bool &w = working[k];
	bool &ns = nosol[k];
	w = true;

	ret += ar[k];
	k += ar[k];
	if (k < -1 || k >= N) {
		w = false;
		return ret++;
	}

	ret += ar[k];
	k -= ar[k];

	if (k < -1 || k >= N) {
		w = false;
		return ret++;
	}
	if (k == -1) {
		ns = true;
		return 0;
	}
	ret += get(k);
	if (nosol[k]) {
		ns = true;
		return 0;
	}

	w = false;
	return ret++;
}


int main() {
	scanf("%d", &N);
	--N;
	for(int i = 0; i < N; ++i) {
		cin >> ar[i];
	}

	for(int i = 0; i < N; ++i) {
		int xinit = i;
		ll yinit = i + 1;
		yinit += ar[i];
		xinit -= ar[i];
		if (xinit == -1) {
			yinit = -1;
		} else if (xinit >= 0) {
			yinit += get(xinit);
			if (nosol[xinit]) yinit = -1;
		}
		cout << yinit << "\n";
	}

	return 0;
}