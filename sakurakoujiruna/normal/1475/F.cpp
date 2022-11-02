#include <bits/stdc++.h>
using namespace std;

int a[1001][1001];
int b[1001][1001];

int main() {
	int t; cin >> t;
	while(t --) {
		int n; cin >> n;
		for(int i = 1; i <= n; i ++) {
			for(int j = 1; j <= n; j ++) {
				char c; cin >> c;
				if(c == '0')
					a[i][j] = 0;
				else
					a[i][j] = 1;
			}
		}
		
		for(int i = 1; i <= n; i ++) {
			for(int j = 1; j <= n; j ++) {
				char c; cin >> c;
				if(c == '0')
					a[i][j] ^= 0;
				else
					a[i][j] ^= 1;
			}
		}
		
		for(int j = 1; j <= n; j ++) {
			if(a[1][j] == 0) {
				for(int i = 1; i <= n; i ++)
					a[i][j] ^= 1;
			}
		}
		
		int ans = 1;
		for(int i = 1; i <= n; i ++)
			for(int j = 1; j <= n; j ++)
				if(a[i][j] != a[i][1])
					ans = 0;
		
		if(ans == 1)
			cout << "Yes\n";
		else
			cout << "No\n";
	}
}