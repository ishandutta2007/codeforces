#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pct __builtin_popcount

#define N 1000010
int n, f[N];

int ask(int x) {
	int S = 0;
	while (x) {
		S += f[x];
		x -= x&-x;
	}
	return S;
}

void add(int x) {
	while (x <= n) {
		f[x] ++;
		x += x&-x;
	}
}

int main() {
	cin >> n;
	int S = 0;
	for (int i = 0; i < n; i ++) {
		int x;
		cin >> x;
		x = n-x+1;
		(S += ask(x)) %= 2;
		add(x);
	}
	if ((S+n)&1) puts ("Um_nik"); else puts ("Petr");
	return 0;
}