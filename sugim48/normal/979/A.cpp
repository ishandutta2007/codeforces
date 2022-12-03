#include <bits/stdc++.h>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back

typedef long long ll;

int main() {
	ll N; cin >> N;
	N++;
	if (N == 1) cout << 0 << endl;
	else cout << (N % 2 == 0 ? N / 2 : N) << endl;
}