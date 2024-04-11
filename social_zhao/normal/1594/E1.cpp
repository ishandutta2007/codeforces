#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int P = 1e9 + 7;	
int k, n;

int qpow(int x, int y) {
	int res = 1;
	while(y) res = res * ((y & 1)? x : 1) % P, x = x * x % P, y >>= 1;
	return res;
}

main() {
	k = get();
//	n = qpow(2, k) - 1;
	int n = 1;
	for(int i = 1; i <= k; i++) n = n * 2;
	n--;
	cout << 6 * qpow(4, n - 1) % P << endl;
	return 0;
}