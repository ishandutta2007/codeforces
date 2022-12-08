#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll n, k;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;
	cout << (n+k-1LL)/n << endl;
}