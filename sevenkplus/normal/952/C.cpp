#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

int n, a[20], b[20], m;

void end_no() {
	puts ("NO");
	exit(0);
}

void end_yes() {
	puts ("YES");
	exit(0);
}

bool chk() {
	for (int i = 0; i < n-1; i ++)
		if (abs(a[i]-a[i+1]) >= 2) return false;
	return true;
}

bool good() {
	for (int i = 0; i < n-1; i ++)
		if (b[i] < b[i+1]) return false;
	return true;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i ++) cin >> a[i];
	if (!chk()) end_no();
	m = n;
	for (int k = 0; k < m; k ++) {
		int p = 0;
		for (int i = 0; i < n; i ++)
			if (a[i] > a[p]) p = i;
		b[k] = a[p];
		n--;
		for (int i = p; i < n; i ++) a[i] = a[i+1];
		if (!chk()) end_no();
	}
	n = m;
	if (!good()) end_no(); else end_yes();
	return 0;
}