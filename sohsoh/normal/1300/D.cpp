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

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

pll A[MAXN];
int n;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	if (n & 1) return cout << "NO" << endl, 0;
	for (int i = 1; i <= n; i++) cin >> A[i].X >> A[i].Y;
	int n2 = n >> 1;
	for (int i = 1; i <= n2; i++) 
		if (A[i].X + A[n2 + i].X != A[1].X + A[n2 + 1].X || A[i].Y + A[n2 + i].Y != A[1].Y + A[n2 + 1].Y)
		       return cout << "NO" << endl, 0;
	cout << "YES" << endl;	
	return 0;
}