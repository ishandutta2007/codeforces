#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

long long ipow(int base, int pow)
{
	int i;
	long long answer = 1;
	for(i=0; i<pow; i++)
		answer *= base;
	return answer;
}

int digitroot(int num)//  
{
	int answer = 0;
	while(num > 0) {
		answer += num%10;
		num /= 10;
	}
	return answer;
}

int last_nonzero(int num) {
	int i;
	for(i=0; num%10==0; i++, num/=10);
	return i;
}

int main() {
	int h, i, j;
	int t, s, n;
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		scanf("%d %d", &s, &n);
		std::vector<int> answer;
		while(digitroot(s) < n) {
			int take = ipow(10, std::max(last_nonzero(s)-1, 0));
			while(s-take < n-1) {
				take /= 10;
			}
			s -= take;
			n--;
			answer.push_back(take);
		}
		int d = 0;
		while(n > 1) {
			while(s%ipow(10, d+1) == 0) {
				d++;
			}
			s -= ipow(10, d);
			n--;
			answer.push_back(ipow(10, d));
		}
		answer.push_back(s);
		for(i=0; i<answer.size(); i++) {
			printf("%d ", answer[i]);
		}
		printf("\n");
	}
}