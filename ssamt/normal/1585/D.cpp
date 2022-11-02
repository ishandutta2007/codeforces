#include <stdio.h>
#include <limits.h>
#include <time.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <queue>
#include <string>
#include <map>
#include <functional>

using namespace std;

long long count_inv(vector<int>& input) {
	int i;
	int n = input.size();
	int a[n];
	for(i=0; i<n; i++) {
		a[i] = input[i];
	}
	function<long long(int, int)> merge_count = [&](int l, int r) {
		int i, j;
		if(l+1 < r) {
			long long answer = 0;
			int mid = (l+r)/2;
			int s[r-l];
			answer += merge_count(l, mid);
			answer += merge_count(mid, r);
			for(i=l, j=mid; i<mid || j<r;) {
				if((a[i] <= a[j] && i < mid) || j == r) {
					s[(i-l)+(j-mid)] = a[i];
					answer += j-mid;
					i++;
				} else {
					s[(i-l)+(j-mid)] = a[j];
					j++;
				}
			}
			for(i=l; i<r; i++) {
				a[i] = s[i-l];
			}
			return answer;
		} else {
			return (long long)0;
		}
	};
	return merge_count(0, n);
}

int main() {
	int h, i, j;
	int t, n, m, k, q;
	int in;
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		scanf("%d", &n);
		vector<int> a;
		for(i=0; i<n; i++) {
			scanf("%d", &in);
			a.push_back(in);
		}
		long long inv = count_inv(a);
		int same = 0;
		sort(a.begin(), a.end());
		for(i=1; i<n; i++) {
			if(a[i-1] == a[i]) {
				same = 1;
			}
		}
		if(same || inv%2 == 0) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
		//vector<int> e{2,1};
		//printf("%lld\n", count_inv(e));
	}
}