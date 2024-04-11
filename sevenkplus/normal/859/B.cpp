#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

int n, S;

int main() {
	cin >> n;
	S = 2*(n+1);
	for (int i = 1; i <= 10000; i ++) {
		if (i*i >= n) S = min(S, i*4);
		if (i*(i+1) >= n) S = min(S, 2*(2*i+1));
	}
	cout << S << endl;
	return 0;
}