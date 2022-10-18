#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vi allInds[100];
unsigned long long oldInds[100];
unsigned long long allInds2[100];
int numNewInds[100];
int K;

void rec(unsigned long long vals, int at) {
	if (at == K) {
		if (vals & (vals+1)) {
			cout << "REJECTED" << endl;
			exit(0);
		}
		return;
	}

	int ones = (int)__builtin_popcountll(oldInds[at] & vals);
	rep(nones,0,numNewInds[at]) {
		int o = ones + nones;
		unsigned long long mask = 0;
		trav(i, allInds[at]) {
			if (o > 0) {
				mask |= 1ULL << i;
			}
			o--;
		}
		unsigned long long nvals = (vals & ~allInds2[at]) | mask;
		rec(nvals, at + 1);
	}
}

int main() {
	cin.sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	int N;
	cin >> N >> K;
	vector<unsigned long long> inds(K);
	vi seen(N);
	rep(i,0,K) {
		int s;
		cin >> s;
		rep(j,0,s) {
			int x;
			cin >> x;
			--x;
			allInds[i].push_back(x);
			allInds2[i] |= 1ULL << x;
			if (seen[x]++) {
				oldInds[i] |= 1ULL << x;
			} else {
				numNewInds[i]++;
			}
		}
		numNewInds[i]++;
		sort(all(allInds[i]));
	}
	if (N == 1) {
		cout << "ACCEPTED" << endl;
		return 0;
	}
	rep(i,0,N) if (!seen[i]) {
		cout << "REJECTED" << endl;
		return 0;
	}
	rec(0, 0);
	cout << "ACCEPTED" << endl;
}