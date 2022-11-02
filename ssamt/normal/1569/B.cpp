#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	int h, i, j;
	int t, n;
	int in;
	int idx;
	cin >> t;
	for(h=0; h<t; h++) {
		cin >> n;
		char s[n+1];
		int count = 0;
		vector<int> no;
		scanf("%s", s);
		for(i=0; i<n; i++) {
			if(s[i] == '2') {
				count++;
				no.push_back(i);
			}
		}
		if(count == 1 || count == 2) {
			printf("NO\n");
		} else {
			printf("YES\n");
			for(i=0; i<n; i++) {
				for(j=0; j<n; j++) {
					if(i == j) {
						printf("X");
					} else if(s[i] == '1' || s[j] == '1') {
						printf("=");
					} else {
						idx = find(no.begin(), no.end(), i)-no.begin();
						if(no[(idx+1)%no.size()] == j) {
							printf("+");
						} else if(no[(no.size()+idx-1)%no.size()] == j){
							printf("-");
						} else {
							printf("=");
						}
					}
				}
				printf("\n");
			}
		}
	}
}