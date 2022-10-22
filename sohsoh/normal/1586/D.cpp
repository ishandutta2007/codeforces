//: // ////: ///  / : //// / :
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;

int A[MAXN], n, D[MAXN], T[MAXN];

inline int ask() {
	cout << "? ";
	for (int i = 1; i <= n; i++) cout << T[i] << sep;
	cout << endl;

	int ans;
	cin >> ans;
	return ans;
}

int main() {
	cin >> n;
	A[0] = n + 1;

	int lst = n + 1;
	for (int i = n; i > 0; i--) {
		if (A[i]) continue;

		int j = 1;
		while (j < n) {
			for (int c = 1; c <= n; c++) T[c] = (A[c] == 0 ? 1 : n);
			T[i] = j + 1;
			int ind = ask();
			
			if (ind == 0) {
				A[i] = lst - j;
				break;
			} else D[ind] = j;

			j++;
		}

		if (j == n) A[i] = 1;
		for (int j = 1; j <= n; j++)
			if (D[j])
				A[j] = A[i] + D[j], D[j] = 0;
		lst = A[i];
	}

	cout << "! ";
	for (int i = 1; i <= n; i++) cout << A[i] << sep;
	cout << endl;
	return 0;
}