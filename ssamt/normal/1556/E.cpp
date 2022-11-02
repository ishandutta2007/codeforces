#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <math.h>
#include <vector>

long long max_tree(int start, int end, long long* tree, int node, int left, int right) {
	if(end < left || right < start) {
		return LLONG_MIN;
	}
	if(left <= start && end <= right) {
		return tree[node];
	}
	int mid = (start+end)/2;
	return std::max(max_tree(start, mid, tree, node*2, left, right), max_tree(mid+1, end, tree, node*2+1, left, right));
}

long long min_tree(int start, int end, long long* tree, int node, int left, int right) {
	if(end < left || right < start) {
		return LLONG_MAX;
	}
	if(left <= start && end <= right) {
		return tree[node];
	}
	int mid = (start+end)/2;
	return std::min(min_tree(start, mid, tree, node*2, left, right), min_tree(mid+1, end, tree, node*2+1, left, right));
}

int main() {
	int h, i, j;
	int t, n, q;
	scanf("%d %d", &n, &q);
	int a[n];
	int b[n];
	for(i=0; i<n; i++) {
		scanf("%d", &a[i]);
	}
	for(i=0; i<n; i++) {
		scanf("%d", &b[i]);
	}
	int diff[n];
	for(i=0; i<n; i++) {
		diff[i] = b[i]-a[i];
	}
	long long sum[n+1];
	sum[0] = 0;
	for(i=1; i<=n; i++) {
		sum[i] = sum[i-1]+diff[i-1];
	}
	int tempn = n-1;
	for(i=0; tempn>0; i++, tempn/=2);
	i++;
	int arr_size = 1;
	for(j=0; j<i; j++) {
		arr_size *= 2;
	}
	long long tree[arr_size];
	for(i=0; i<arr_size; i++) {
		tree[i] = LLONG_MIN;
	}
	for(i=0; i<n; i++) {
		tree[arr_size/2+i] = sum[i+1];
	}
	for(i=arr_size/2-1; i>0; i--) {
		tree[i] = std::max(tree[2*i], tree[2*i+1]);
	}
	long long tree2[arr_size];
	for(i=0; i<arr_size; i++) {
		tree2[i] = LLONG_MAX;
	}
	for(i=0; i<n; i++) {
		tree2[arr_size/2+i] = sum[i+1];
	}
	for(i=arr_size/2-1; i>0; i--) {
		tree2[i] = std::min(tree2[2*i], tree2[2*i+1]);
	}
	for(h=0; h<q; h++) {
		int l, r;
		scanf("%d %d", &l, &r);
		long long min_sum = min_tree(0, arr_size/2-1, tree2, 1, l-1, r-1);
		if(min_sum >= sum[l-1] && sum[l-1] == sum[r]) {
			long long max_sum = max_tree(0, arr_size/2-1, tree, 1, l-1, r-1);
			printf("%lld\n", max_sum-sum[l-1]);
		} else {
			printf("-1\n");
		}
	}
}