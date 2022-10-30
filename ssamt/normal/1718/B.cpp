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
		vector<long long> a(n);
		long long sum = 0;
		for(i=0; i<n; i++) {
			cin >> a[i];
			sum += a[i];
		}
		if(n == 1 && a[0] == 1) {
			cout << "YES" << endl;
		} else {
			vector<long long> fib{1, 1};
			long long acc = 2;
			while(acc < sum) {
				fib.push_back(fib[fib.size()-2]+fib[fib.size()-1]);
				acc += fib.back();
			}
			if(acc == sum) {
				priority_queue<vector<long long>> pq;
				for(i=0; i<n; i++) {
					pq.push({a[i], i});
				}
				int check = 1;
				int last = -1;
				for(i=fib.size()-1; i>=0; i--) {
					long long num = pq.top()[0];
					int idx = pq.top()[1];
					if(num >= fib[i]) {
						if(idx == last) {
							pq.pop();
							if(!pq.empty() && pq.top()[0] >= fib[i]) {
								pq.push({pq.top()[0]-fib[i], pq.top()[1]});
								last = pq.top()[1];
								pq.pop();
								pq.push({num, idx});
							} else {
								check = 0;
								break;
							}
						} else {
							pq.push({num-fib[i], idx});
							pq.pop();
							last = idx;
						}
					} else {
						check = 0;
						break;
					}
				}
				cout << (check?"YES":"NO") << endl;
			} else {
				cout << "NO" << endl;
			}
			
		}
	}
}