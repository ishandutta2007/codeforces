#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int cal(vector<int> l) {
	int i;
	int answer = 0;
	vector<int> r;
	if(l.size() == 0) {
		return 0;
	} else if(l.size() == 1) {
		return 1-l[0];
	}
	r.push_back(l[0]);
	r.push_back(l[1]);
	for(i=2; i<l.size(); i++) {
		if(l[i] != l[i-1] || l[i] != l[i-2]) {
			r.push_back(l[i]);
		} else {
			if(l[i] == 0) {
				answer++;
			}
		}
	}
	for(i=0; i<r.size(); i++) {
		if(r[i] == 0) {
			if(i == r.size()-1 || r[i+1] == 0) {
				answer++;
			} else {
				answer += 2;
				i++;
			}
		} else {
			if(i != r.size()-1 && r[i+1] == 0) {
				answer += 2;
				i++;
			}
		}
	}
	return answer;
}

int main() {
	int h, i, j;
	int t, n;
	char s1[100001];
	char s2[100001];
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		int answer = 0;
		scanf("%d", &n);
		scanf("%s", s1);
		scanf("%s", s2);
		vector<int> l;
		for(i=0; i<n; i++) {
			if(s1[i] != s2[i]) {
				answer += 2;
				answer += cal(l);
				l.clear();
			} else {
				l.push_back(s1[i]-'0');
			}
		}
		answer += cal(l);
		printf("%d\n", answer);
	}
}