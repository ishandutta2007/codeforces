#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

int n, k, x;
int num[2][2100];

int main() {
	cin >> n >> k >> x;

	rep(i, n) {
		int a;
		cin >> a;
		num[0][a]++;
	}

	int c = 0, f = 1;
	while (k--) {
		rep(i, 2100) num[f][i] = 0;

		bool la = 0;
		for (int i = 0; i < 2100; ++i) {
			if (num[c][i]) {

				num[f][i ^ x] += num[c][i] / 2;
				num[f][i] += num[c][i] / 2;

				if (num[c][i] & 1) {
					if (!la) {
						++num[f][i^x];
					} else {
						++num[f][i];
					}
					la ^= 1;
				}
			}
		}

		swap(c, f);
	}

	int m, M;
	rep(i, 2100) if (num[c][i] > 0) {
		m = i;
		break;
	}

	for (int i = 2099; i >= 0; --i) if (num[c][i] > 0) {
		M = i;
		break;
	}

	cout << M << " " << m << endl;

	return 0;
}