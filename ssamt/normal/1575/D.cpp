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
	int t, n, m, k;
	char s[9];
	scanf("%s", s);
	for(i=0; s[i]; i++);
	n = i;
	int total = 0;
	int x[n];
	int xcount = 0;
	for(i=0; i<n; i++) {
		if(s[i] == 'X') {
			x[i] = 1;
			xcount++;
		} else {
			x[i] = 0;
		}
	}
	for(h=0; h<10; h++) {
		for(i=0; i<n; i++) {
			if(x[i]) {
				s[i] = h+'0';
			}
		}
		int answer;
		if(n == 1) {
			if(s[0] == '0' || s[0] == '_') {
				answer = 1;
			} else {
				answer = 0;
			}
		} else {
			answer = 0;
			if((s[n-2] == '0' || s[n-2] == '_') && (s[n-1] == '0' || s[n-1] == '_') && n != 2) {
				answer++;
			}
			if((s[n-2] == '2' || s[n-2] == '_') && (s[n-1] == '5' || s[n-1] == '_')) {
				answer++;
			}
			if((s[n-2] == '5' || s[n-2] == '_') && (s[n-1] == '0' || s[n-1] == '_')) {
				answer++;
			}
			if((s[n-2] == '7' || s[n-2] == '_') && (s[n-1] == '5' || s[n-1] == '_')) {
				answer++;
			}
			for(i=0; i<n-2; i++) {
				if(s[i] == '_') {
					if(i == 0) {
						answer *= 9;
					} else {
						answer *= 10;
					}
				}
			}
			if(s[0] == '0') {
				answer = 0;
			}
		}
		total += answer;
		if(xcount == 0) {
			break;
		}
	}
	printf("%d", total);
}