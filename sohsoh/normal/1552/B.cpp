// Sohsoh84 :)))
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e5 + 10;

int n;
int R[MAXN][5];

bool Check(int i, int l, int r) {
	while (l <= r) {
		int t = 0;
		for (int j = 0; j < 5; j++)
			if (R[l][j] < R[i][j])
				t++;
		if (t > 2) return false;
		l++;
	}

	return true;
}

int Find(int L, int R) {
	if (L == R) return L;
	
	int mid = (L + R) >> 1;	
	int i1 = Find(L, mid), i2 = Find(mid + 1, R);
	if (Check(i1, L, R)) return i1;
	return i2;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++)
			for (int j = 0; j < 5; j++)
				cin >> R[i][j];
	
		cout << (Check(Find(1, n), 1, n) ? Find(1, n) : -1) << endl;
	}
	return 0;
}