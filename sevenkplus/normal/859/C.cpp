#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define N 55

int n;
int a[N], s[N];
int f[N];

int main() {
	cin >> n;
	for (int i = 0; i < n; i ++) cin >> a[i];
	s[n] = 0;
	for (int i = n-1; i >= 0; i --) s[i] = s[i+1] + a[i];
	f[n] = 0;
	for (int i = n-1; i >= 0; i --)
		f[i] = max(f[i+1], s[i]-f[i+1]);
	cout << s[0]-f[0] << " " << f[0] << endl;
	return 0;
}