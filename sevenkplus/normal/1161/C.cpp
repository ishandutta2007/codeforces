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

#define N 55
int n;
int a[N];

int main() {
	cin >> n;
	for (int i = 0; i < n; i ++) cin >> a[i];
	sort(a, a+n);
	int s = 0;
	for (int i = 0; i < n; i ++)
		if (a[i] == a[0]) s++;
	if (s <= n/2) puts ("Alice");
	else puts ("Bob");
	return 0;
}