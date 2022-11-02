#include <bits/stdc++.h>

using namespace std;

int isprime(long long num)
{
	if(num <= 1)
		return 0;
	long long div;
	for(div=2; div*div<=num; div++)
		if(num%div == 0)
			return 0;
	return 1;
}

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int in;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		int e;
		scanf("%d %d", &n, &e);
		int a[n];
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		long long answer = 0;
		for(i=0; i<e; i++) {
			vector<int> others, ones;
			int count = 0;
			for(j=0; i+e*j<n; j++) {
				int idx = i+e*j;
				if(a[idx] == 1) {
					count++;
				} else {
					ones.push_back(count);
					others.push_back(a[idx]);
					count = 0;
				}
			}
			ones.push_back(count);
			for(j=0; j<others.size(); j++) {
				if(isprime(others[j])) {
					answer += (long long)(ones[j]+1)*(ones[j+1]+1)-1;
				}
			}
		}
		printf("%lld\n", answer);
	}
}