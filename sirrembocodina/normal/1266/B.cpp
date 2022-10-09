#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)

#define pb push_back

const int mod = 1000000007;
const int K = 225;

bool used[50100];
string s[50100];
int a[50100];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	int n;
	cin >> n;
	forn (i, n) {
		long long x;
		cin >> x;
		if (x > 14 && 1 <= (x % 14) && (x % 14) <= 6) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
}