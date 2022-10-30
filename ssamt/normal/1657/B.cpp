#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	long long i, j, k, l;
	int t, n, m, q;
	int u, v;
	int in;
	cin >> t;
	for(cl=0; cl<t; cl++) {
		long long b, x, y;
		long long answer = 0;
		long long num = 0;
		cin >> n >> b >> x >> y;
		for(i=0; i<n; i++) {
			if(num+x > b) {
				num -= y;
			} else {
				num += x;
			}
			answer += num;
		}
		cout << answer << endl;
	}
}