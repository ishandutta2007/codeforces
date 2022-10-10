#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;
int prime[MAXN];

void sieve() {
	for(int p = 2; p < MAXN; p++) {
		if(prime[p])
			continue;
		for(int q = p; q < MAXN; q += p)
			prime[q] = p;
	}
}

ll mpow(ll b, ll e, ll m) {
	ll res = 1;
	for(ll k = 1; k <= e; k *= 2) {
		if(k & e) res = (res * b) % m;
		b = (b * b) % m;
	}
	return res;
}

int main() {
	sieve();
	int n;
	cin >> n;
	if(n == 1) {
		cout << "YES\n1\n";
		return 0;
	}
	if(n == 4) {
		cout << "YES\n1 3 2 4\n";
		return 0;
	}
	if(prime[n] != n) {
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	vector<int> pd;
	int t = n - 1;
	while(t > 1) {
		int p = prime[t];
		pd.push_back(p);
		while(t % p == 0)
			t /= p;
	}
	vector<int> perm(n - 1);
	for(int i = 0; i < n - 1; i += 2)
		perm[i] = i;
	for(int i = n - 2; i >= 1; i -= 2)
		perm[i] = n - 1 - i;
	ll g;
	for(g = 1;;g++) {
		bool pr = true;
		for(auto p : pd)
			if(mpow(g, (n - 1)/p, n) == 1) {
				pr = false;
				break;
			}
		if(pr)
			break;
	}
	for(int i = 0; i < n - 1; i++)
		cout << mpow(g, perm[i], n) << " ";
	cout << n << '\n';
}