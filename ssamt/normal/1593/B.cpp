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

using namespace std;

int main() {
	int h, i, j, l;
	long long t, n, m, k;
	scanf("%lld", &t);
	for(h=0; h<t; h++) {
		scanf("%lld", &n);
		bool zero = false, five = false;
		int answer;
		i = 1;
		while(n > 0) {
			int d = n%10;
			if(d == 0) {
				if(zero) {
					answer = i-2;
					break;
				} else {
					zero = true;
				}
			} else if(d == 2) {
				if(five) {
					answer = i-2;
					break;
				}
			} else if(d == 5) {
				if(zero) {
					answer = i-2;
					break;
				} else {
					five = true;
				}
			} else if(d == 7) {
				if(five) {
					answer = i-2;
					break;
				}
			}
			n /= 10;
			i++;
		}
		printf("%d\n", answer);
	}
}