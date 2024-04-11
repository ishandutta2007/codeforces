#include <bits/stdc++.h>

using namespace std;

int coun[20000000+1] = {};
int mult[20000000+1] = {};
//int prime[20000000+1];
long long answer[20000000+1] = {};
vector<int> p;

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int in;
	scanf("%d", &n);
	int a[n];
	int am = 0;
	for(i=0; i<n; i++) {
		scanf("%d", &a[i]);
		am = max(am, a[i]);
		coun[a[i]]++;
	}
	for(i=am; i>=1; i--) {
		if(2*i <= am) {
			mult[i] = mult[2*i];
			for(j=i; j<=am; j+=i+i) {
				mult[i] += coun[j];
			}
		} else {
			mult[i] = coun[i];
		}
	}
	/*for(i=2; i<=am; i++) {
		prime[i] = 1;
	}
	for(i=2; i<=am; i++) {
		if(prime[i]) {
			int lim = i*i;
			for(j=2*i; j<=am && j<=lim; j+=i) {
				prime[j] = 0;
			}
		}
	}
	for(i=2; i<=am; i++) {
		if(prime[i]) {
			p.push_back(i);
		}
	}*/
	/*for(i=1; i<=am; i++) {
		printf("%d ", mult[i]);
	}
	printf("\n");*/
	/*if(a[0] == 19999980) {
		int count = 0;
		printf("%d\n", count);
		return 0;
		for(i=1; i<=am; i++) {
			if(mult[i]) {
				for(j=2*i; j<=am; j+=i) {
					if(mult[j]) {
						count++;
					}
				}
			}
		}
	}*/
	/*answer[1] = n;
	long long sum_max = 0;
	for(i=1; i<=am; i++) {
		sum_max = max(sum_max, answer[i]);
		if(mult[i]) {
			int lim = am/i;
			for(j=0; p[j]<=lim && j<p.size(); j++) {
				k = i*p[j];
				if(mult[k]) {
					answer[k] = max(answer[k], answer[i]+(long long)mult[k]*(k-i));
				}
			}
		}
	}
	printf("%lld\n", sum_max);*/
	answer[1] = n;
	long long sum_max = 0;
	for(i=1; i<=am; i++) {
		sum_max = max(sum_max, answer[i]);
		if(mult[i]) {
			for(j=2*i; j<=am; j+=i) {
				if(mult[j]) {
					answer[j] = max(answer[j], answer[i]+(long long)mult[j]*(j-i));
				}
			}
		}
	}
	printf("%lld\n", sum_max);
}