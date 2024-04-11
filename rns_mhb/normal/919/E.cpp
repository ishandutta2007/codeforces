#include <bits/stdc++.h>
using namespace std;
#define ll long long

int p, a, b;
ll x;
ll cnt;

int main() {
	scanf("%d%d%d%I64d", &a, &b, &p, &x);
	ll q = 1ll * p * (p - 1);
	for (int i = p - 2, s = b; i >= 0; i --) {
		s = 1ll * s * a % p;
		ll r = (q + 1ll * p * i - 1ll * (p - 1) * s) % q;
		if (r == 0) r = p;
		if (r <= x) cnt += (x - r) / q + 1;
	}
	cout<<cnt<<endl;
}