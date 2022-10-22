#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define debug(x)                    cerr << #x << ": " <<  x << endl;

ll poww(ll a, ll b, ll md) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int qr = 0;

inline int Query(int ind) {
	qr++;
	cout << "? " << ind << endl;
	int x;
	cin >> x;
	return x;
}

inline void Answer(int ind) {
	cout << "! " << ind << endl;
	exit(0);
}

int A[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	int L = 1, R = n;
	while (L < R - 10) {
		int mid = (L + R) >> 1;
		int midL = mid - 1, midR = mid + 1;
		int m = Query(mid), mL = Query(midL), mR = Query(midR);
		if (m < mL && m < mR) Answer(mid);
		else if (mL < m) R = mid;
		else L = mid;
	}

	memset(A, 63, sizeof A);
	for (int i = L; i <= R; i++) A[i] = Query(i);
	for (int i = L; i <= R; i++) if (A[i] < A[i + 1] && A[i] < A[i - 1]) Answer(i);
	Answer(n);
	return 0;
}