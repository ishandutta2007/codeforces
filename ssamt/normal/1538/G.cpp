#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <math.h>
#include <vector>

void swap(int* num1, int* num2)
{
	int swap;
	swap = *num1;
	*num1 = *num2;
	*num2 = swap;
}

int main() {
	int h, i, j;
	int t, x, y, a, b;
	int answer;
	int add;
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		scanf("%d %d %d %d", &x, &y, &a, &b);
		if(x > y) {
			swap(&x, &y);
		}
		if(a > b) {
			swap(&a, &b);
		}
		if(x/a <= y/b) {
			answer = x/a;
		} else {
			answer = (y-x)/(b-a);
			x -= answer*a;
			y -= answer*b;
			add = x/(a+b)*2;
			x -= a;
			y -= b;
			if(x >= 0 && y >= 0) {
				add = std::max(add, y/(a+b)*2+1);
			}
			answer += add;
		}
		printf("%d\n", answer);
	}
}