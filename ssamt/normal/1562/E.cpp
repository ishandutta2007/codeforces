#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

int main() {
	int h, i, j;
	int t, n;
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		scanf("%d", &n);
		char s[n];
		int m[n][n];
		scanf("%s", s);
		for(i=1; i<n; i++){
			int count = 0;
			for(j=n-i-1; j>=0; j--) {
				if(s[j] == s[j+i]) {
					count++;
				} else {
					count = 0;
				}
				m[j][j+i] = count;
			}
		}
		int answer[n];
		for(i=0; i<n; i++) {
			answer[i] = n-i;
			for(j=0; j<i; j++) {
				if(s[i+m[j][i]] > s[j+m[j][i]]) {
					int comb = (n-i-m[j][i])+answer[j];
					answer[i] = max(answer[i], comb);
				}
			}
		}
		int max_val = answer[0];
		for(i=1; i<n; i++) {
			max_val = max(max_val, answer[i]);
		}
		printf("%d\n", max_val);
	}
}