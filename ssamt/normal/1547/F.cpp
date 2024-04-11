#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <vector>

#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

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
	int h, i, j;
	int t, n;
	int d;
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		scanf("%d", &n);
		int a[n];
		int e[n];
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		int maxa = 0;
		for(i=0; i<n; i++) {
			maxa = max(maxa, a[i]);
		}
		int answer = 0;
		for(d=2; d*d<=maxa; d++) {
			if(isprime(d)) {
				for(i=0; i<n; i++) {
					e[i] = 0;
					while(a[i]%d == 0) {
						e[i]++;
						a[i] /= d;
					}
				}
				int mine = INT_MAX;
				for(i=0; i<n; i++) {
					mine = min(mine, e[i]);
				}
				std::vector<int> elist;
				for(i=0; i<n; i++) {
					if(e[i] == mine) {
						elist.push_back(i);
					}
				}
				int maxdis = n-elist[elist.size()-1]+elist[0];
				for(i=0; i<elist.size()-1; i++) {
					maxdis = max(maxdis, elist[i+1]-elist[i]);
				}
				answer = max(answer, maxdis-1);
			}
		}
		int loop = 0;
		int maxdis = 1;
		for(i=0; loop<2; i=(i+1)%n) {
			if(a[i] == 1) {
				maxdis = 1;
			} else {
				if(a[i] == a[(i+1)%n]) {
					maxdis++;
				} else {
					answer = max(answer, maxdis);
					maxdis = 1;
					if(loop) {
						break;
					}
				}
			}
			if(i == n-1) {
				loop++;
			}
		}
		printf("%d\n", answer);
	}
}