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
		int x, y;
		cin >> x >> y;
		int answer;
		if(x == 0 && y == 0) {
			answer = 0;
		} else {
			int dist = round(sqrt(x*x+y*y));
			if(dist*dist == x*x+y*y) {
				answer = 1;
			} else {
				answer = 2;
			}
		}
		cout << answer << endl;
	}
}