#include <bits/stdc++.h>
using namespace std;

const int N = 35;

int c[N][N];
int cnt[N];

int main() {
	for(int i = 0; i < N; i ++) {
		c[i][0] = 1;
		for(int j = 1; j <= i; j ++)
			c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
	}
	
	int n; cin >> n;
	for(int i = N - 1; i >= 6; i --)
		while(n >= c[i][6]) {
			n -= c[i][6];
			cnt[i] ++;
		}
	for(int i = 1; i < N; i ++) {
		cout << 'a';
		while(cnt[i]) {
			cout << 'b';
			cnt[i] --;
		}
	}
	cout << "\naaaaaab\n";
	
	return 0;
}