#include <bits/stdc++.h>

using namespace std;

long long les(long long n) {
	long long answer = 0;
	long long start = 0, end = 1e9+1;
	while(start+1 < end) {
		long long mid = (start+end)/2;
		if(mid*mid < n) {
			start = mid;
		} else {
			end = mid;
		}
	}
	answer += start;
	start = 0, end = 1e9+1;
	while(start+1 < end) {
		long long mid = (start+end)/2;
		if(mid*(mid+1) < n) {
			start = mid;
		} else {
			end = mid;
		}
	}
	answer += start;
	start = 0, end = 1e9+1;
	while(start+1 < end) {
		long long mid = (start+end)/2;
		if(mid*(mid+2) < n) {
			start = mid;
		} else {
			end = mid;
		}
	}
	answer += start;
	return answer;
}

int main() {
	int i, j, k, l;
	int t, n, m, q;
	scanf("%d", &t);
	for(int cl=0; cl<t; cl++) {
		long long l, r;
		scanf("%lld %lld", &l, &r);
		printf("%lld\n", les(r+1)-les(l));
	}
}