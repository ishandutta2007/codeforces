#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

int n, x, pos;
int A, B, C;

int main() {
	cin >> n >> x >> pos;
	int st = 0, en = n;
	while (st < en) {
		int mi = (st + en) / 2;
		if (mi <= pos) {
			if (mi == pos) C ++;
			else A ++;
			st = mi + 1;
		}
		else {
			en = mi;
			B ++;
		}
	}
	int rlt = 1;
	for (int i = x - 1; i >= max(0, x - A); i --) rlt = 1LL * rlt * i % mod;
	A = x - 1 - A;
	for (int i = n - x; i >= max(0, n - x - B + 1); i --) rlt = 1LL * rlt * i % mod;
	B = n - B - x;
	for (int i = 1; i <= A + B; i ++) rlt = 1LL * rlt * i % mod;
	cout << rlt << endl;
}