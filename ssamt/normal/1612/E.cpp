#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, l;
	int t, n, q;
	int in;
	scanf("%d", &n);
	int m[n];
	int k[n];
	for(i=0; i<n; i++) {
		scanf("%d", &m[i]);
		scanf("%d", &k[i]);
	}
	double answer = 0;
	int num = 0;
	int size = 200001;
	for(i=1; i<=20; i++) {
		int count[size] = {};
		for(j=0; j<n; j++) {
			count[m[j]] += min(k[j], i);
		}
		vector<vector<int>> large;
		for(j=0; j<size; j++) {
			if(count[j]) {
				large.push_back({count[j], j});
			}
		}
		sort(large.begin(), large.end());
		int sum = 0;
		for(j=(int)large.size()-1; j>=max((int)large.size()-i, 0); j--) {
			sum += large[j][0];
		}
		if((double)sum/i > answer) {
			answer = (double)sum/i;
			num = i;
		}
	}
	int count[size] = {};
	for(j=0; j<n; j++) {
		count[m[j]] += k[j];
	}
	vector<vector<int>> large;
	for(j=0; j<size; j++) {
		if(count[j]) {
			large.push_back({count[j], j});
		}
	}
	int sum[large.size()+1] = {};
	for(i=1; i<=large.size(); i++) {
		sum[i] = sum[i-1]+large[(int)large.size()-i][0];
	}
	for(i=21; i<=large.size(); i++) {
		if((double)sum[i]/i > answer) {
			answer = (double)sum[i]/i;
			num = i;
		}
	}
	printf("%d\n", num);
	if(num <= 20) {
		int count[size] = {};
		for(j=0; j<n; j++) {
			count[m[j]] += min(k[j], num);
		}
		vector<vector<int>> large;
		for(j=0; j<size; j++) {
			if(count[j]) {
				large.push_back({count[j], j});
			}
		}
		sort(large.begin(), large.end());
		for(j=(int)large.size()-1; j>=(int)large.size()-num; j--) {
			printf("%d ", large[j][1]);
		}
		printf("\n");
	} else {
		for(j=(int)large.size()-1; j>=(int)large.size()-num; j--) {
			printf("%d ", large[j][1]);
		}
		printf("\n");
	}
}