#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

int main() {
	int k, a, b;
	cin >> k >> a >> b;
	if (a > b) swap(a, b);
	if (a < k && b < k || a < k && b%k != 0) puts ("-1");
	else cout << a/k+b/k << endl;
	return 0;
}