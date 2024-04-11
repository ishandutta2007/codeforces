#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define N 10010
int n;
int f[N];

int fa(int x) {
	if (f[x] == x) return x;
	return f[x] = fa(f[x]);
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i ++) f[i] = i;
	for (int i = 0; i < n; i ++) {
		int x;
		cin >> x;
		x --;
		f[fa(x)] = fa(i);
	}
	int S = 0;
	for (int i = 0; i < n; i ++) if (fa(i) == i) S++;
	cout << S << endl;
	return 0;
}