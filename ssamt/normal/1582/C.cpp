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
		char s[n+1];
		scanf("%s", s);
		vector<char> p;
		int answer = INT_MAX;
		for(char c='a'; c<='z'; c++) {
			p.clear();
			int count = 0;
			int left = 0, right = n-1;
			int check = 1;
			while(left < right) {
				if(s[left] != s[right]) {
					if(s[left] == c) {
						if(s[right] == c) {
							left++;
							right--;
						} else {
							count++;
							left++;
						}
					} else {
						if(s[right] == c) {
							count++;
							right--;
						} else {
							check = 0;
							break;
						}
					}
				} else {
					left++;
					right--;
				}
			}
			if(check) {
				answer = min(answer, count);
			}
		}
		if(answer == INT_MAX) {
			printf("-1\n");
		} else {
			printf("%d\n", answer);
		}
	}
}