#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int u, v;
	int in;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		scanf("%d", &n);
		int a[n], b[n];
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
			a[i]--;
		}
		for(i=0; i<n; i++) {
			scanf("%d", &b[i]);
			b[i]--;
		}
		int r[n];
		for(i=0; i<n; i++) {
			r[b[i]] = i;
		}
		vector<int> loop;
		int check[n] = {};
		for(i=0; i<n; i++) {
			if(!check[i]) {
				int count = 1;
				check[i] = 1;
				for(int idx=r[a[i]]; idx!=i; idx=r[a[idx]]) {
					check[idx] = 1;
					count++;
				}
				loop.push_back(count);
			}
		}
		vector<int> val;
		for(i=0; i<n; i++) {
			val.push_back(abs(2*i-(n-1)));
		}
		sort(val.begin(), val.end());
		int odd = 0;
		for(i=0; i<loop.size(); i++) {
			//printf("%d\n", loop[i]);
			if(loop[i]%2 == 1){
				odd++;
			}
		}
		long long answer = 0;
		for(i=odd; i<n; i++) {
			answer += val[i];
		}
		printf("%lld\n", answer);
	}
}