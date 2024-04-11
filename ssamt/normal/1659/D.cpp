#include <bits/stdc++.h>

using namespace std;

vector<int> cur(vector<int> x) {
	if(x.size() == 1) {
		return x;
	}
	int i;
	int n = x.size();
	/*for(i=0; i<n; i++) {
		printf("%d ", x[i]);
	}
	printf("\n");*/
	long long sum = 0;
	for(i=0; i<n; i++) {
		sum += x[i];
	}
	int total = sum/n;
	vector<int> answer(n, 0);
	for(i=(n+1)/2; i<n; i++) {
		answer[i] = (x[i]<=n/2)?0:1;
		total -= answer[i];
	}
	vector<int> y((n+1)/2, 0);
	for(i=0; i<(n+1)/2; i++) {
		y[i] = x[i];
	}
	int pos = (n+1)/2-total;
	for(i=(n+1)/2; i<n && pos<(n+1)/2; i++) {
		if(answer[i] == 0) {
			y[pos] -= i-(n+1)/2;
			pos++;
		}
	}
	for(; pos<(n+1)/2; pos++) {
		y[pos] -= i-(n+1)/2;
	}
	vector<int> front = cur(y);
	for(i=0; i<front.size(); i++) {
		answer[i] = front[i];
	}
	return answer;
}

int main() {
	int i, j, k, l;
	int t, n, m, q;
	scanf("%d", &t);
	for(int cl=0; cl<t; cl++) {
		scanf("%d", &n);
		vector<int> a(n);
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		vector<int> answer = cur(a);
		for(i=0; i<n; i++) {
			printf("%d ", answer[i]);
		}
		printf("\n");
	}
}