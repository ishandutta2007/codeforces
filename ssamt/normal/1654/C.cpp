#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int u, v;
	int in;
	cin >> t;
	for(cl=0; cl<t; cl++) {
		cin >> n;
		priority_queue<long long> a, b;
		long long sum = 0;
		for(i=0; i<n; i++) {
			cin >> in;
			a.push(in);
			sum += in;
		}
		b.push(sum);
		int check = 1;
		while(!a.empty() && !b.empty()) {
			if(a.top() == b.top()) {
				a.pop();
				b.pop();
			} else if(b.top() > a.top()) {
				long long p = b.top();
				b.pop();
				b.push(p/2);
				b.push((p+1)/2);
			} else {
				check = 0;
				break;
			}
		}
		if(check && a.empty() && b.empty()) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}