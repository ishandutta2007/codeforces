#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define N 1000010
int n, k;
int f[N];

void add(int x) {
	x++;
	while (x <= n) {
		f[x] ++;
		x += x&-x;
	}
}

int ask(int x) {
	x ++;
	int S = 0;
	while (x) {
		S += f[x];
		x -= x&-x;
	}
	return S;
}

int ask(int x, int y) {
	if (y < x) {
		return ask(x, n-1) + ask(0, y);
	} else {
		return ask(y)-ask(x-1);
	}
}

int main() {
	cin >> n >> k;
	if (k > n-k) k = n-k;
	ll S = 1;
	int now = 0;
	int la = 0;
	bool first = true;
	while (true) {
		int next = (now+k)%n;
		S += la;
		if (next == 0) la = ask(now, n-1);
		else la = ask(now, next-1);
		S += la;
		S++;
		if (first) first = false;
		else printf(" ");
		printf ("%I64d", S);
		add(now);
		now = next;
		if (now == 0) break;
	}
	puts("");
	return 0;
}