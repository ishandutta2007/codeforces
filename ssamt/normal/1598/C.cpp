#include <stdio.h>
#include <limits.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <queue>
#include <string>
#include <map>
#include <functional>

using namespace std;

int main() {
	int h, i, j, l;
	int t, n, m, k;
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		scanf("%d", &n);
		int a[n];
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		long long sum = 0;
		for(i=0; i<n; i++) {
			sum += a[i];
		}
		if((2*sum)%n == 0) {
			long long answer = 0;
			int tar = (2*sum)/n;
			map<int, int> m;
			for(i=0; i<n; i++) {
				if(m.count(a[i]) == 0) {
					m[a[i]] = 0;
				}
				m[a[i]]++;
			}
			for(i=0; i<n; i++) {
				if(m.count(tar-a[i]) > 0) {
					answer += m[tar-a[i]];
				}
				if(2*a[i] == tar) {
					answer--;
				}
			}
			answer /= 2;
			printf("%lld\n", answer);
		} else {
			printf("0\n");
		}
	}
}