#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int P = 1e18;
int a;

signed main() {
	a = get();
	int st = P % a * 9 % a * 9 % a + 1;
	int l = a - st + 1, r = l + P - 1;
	cout << l << " " << r << endl;
	return 0;
}