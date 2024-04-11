#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;
const int N = 200000 + 10;
int gcd(int x, int y) {
	return y==0?x:gcd(y,x%y);
}
int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	int t; cin >> t;
	while (t --) {
		int n; string s;
		cin >> n >> s;
		int d = 0, k = 0;

		map< pair<int,int>,int > m; 
		for (int i = 0; i < n; i ++) {
			if (s[i] == 'D') d ++; else k ++;
			int x = gcd(d,k);
			int dd = d / x, kk = k / x;
			//printf("dd=%d,kk=%d\n", dd,kk);
			m[make_pair(dd,kk)] ++;
			cout << m[make_pair(dd,kk)] << " ";
		}
		cout << endl; 
	}
}