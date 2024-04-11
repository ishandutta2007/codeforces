#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;

int A[46] = {0, 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 19 , 29 , 39 , 49 , 59 , 69 , 79 , 89 , 189 , 289 , 389 , 489 , 589 , 689 , 789 , 1789 , 2789 , 3789 , 4789 , 5789 , 6789 , 16789 , 26789 , 36789 , 46789 , 56789 , 156789 , 256789 , 356789 , 456789 , 1456789 , 2456789 , 3456789 , 13456789 , 23456789 , 123456789};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int x;
		cin >> x;
		cout << A[x] << endl;
	}
	return 0;
}