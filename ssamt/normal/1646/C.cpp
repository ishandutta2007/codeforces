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
		long long n;
		scanf("%lld", &n);
		vector<long long> f{1};
		while(f.back() <= n) {
			f.push_back(f.back()*f.size());
		}
		f.pop_back();
		int answer = INT_MAX;
		for(i=0; i<(1<<f.size()); i+=(1<<3)) {
			int count = 0;
			long long sum = 0;
			for(j=0; j<f.size(); j++) {
				if(i&(1<<j)) {
					count++;
					sum += f[j];
				}
			}
			sum = n-sum;
			if(sum >= 0) {
				for(j=0; j<64; j++) {
					if(sum&((long long)1<<j)) {
						count++;
					}
				}
				answer = min(answer, count);
			}
		}
		printf("%d\n", answer);
	}
}