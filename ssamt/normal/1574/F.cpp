#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

int main() {
	int h, i, j;
	int t, n, m, k;
	int len;
	int in;
	long long mod = 998244353;
	int size_limit = 300000;
	scanf("%d %d %d", &n, &m, &k);
	vector<int> a[n];
	for(i=0; i<n; i++) {
		scanf("%d", &len);
		for(j=0; j<len; j++) {
			scanf("%d", &in);
			a[i].push_back(in-1);
		}
	}
	vector<pair<int, int> > idx[k];
	for(i=0; i<n; i++) {
		for(j=0; j<a[i].size(); j++) {
			int add = a[i][j];
			pair<int, int> e{i, j};
			idx[add].push_back(e);
		}
	}
	int visited[n] = {};
	pair<bool, int> pos[n];
	for(i=0; i<n; i++) {
		pos[i].first = false;
	}
	pair<bool, int> elem[k];
	for(i=0; i<k; i++) {
		elem[i].first = false;
	}
	vector<int> stack;
	vector<int> lengths;
	for(i=0; i<n; i++) {
		if(!visited[i]) {
			set<int> fill;
			int collide = 0;
			visited[i] = 1;
			pos[i].first = true;
			pos[i].second = 0;
			for(j=0; j<a[i].size(); j++) {
				stack.push_back(a[i][j]);
				elem[a[i][j]].first = true;
				elem[a[i][j]].second = j;
				fill.insert(elem[a[i][j]].second);
			}
			int start = 0;
			int end = a[i].size();
			while(!stack.empty()) {
				int num = stack.back();
				stack.pop_back();
				for(j=0; j<idx[num].size(); j++) {
					int arr_idx = idx[num][j].first;
					int str_idx = idx[num][j].second;
					if(pos[arr_idx].first) {
						if(pos[arr_idx].second+str_idx != elem[num].second) {
							collide = 1;
						}
					} else {
						pos[arr_idx].first = true;
						pos[arr_idx].second = elem[num].second-str_idx;
						start = min(start, pos[arr_idx].second);
						end = max(end, pos[arr_idx].second+(int)a[arr_idx].size());
					}
					if(!visited[arr_idx]) {
						visited[arr_idx] = 1;
						for(h=0; h<a[arr_idx].size(); h++) {
							if(!elem[a[arr_idx][h]].first) {
								stack.push_back(a[arr_idx][h]);
								elem[a[arr_idx][h]].first = true;
								elem[a[arr_idx][h]].second = pos[arr_idx].second+h;
								if(fill.count(elem[a[arr_idx][h]].second) > 0) {
									collide = 1;
								}
								fill.insert(elem[a[arr_idx][h]].second);
							}
						}
					}
				}
			}
OUT1:
			if(!collide) {
				lengths.push_back(end-start);
			}
			//printf("%d\n", fill.size());
		}
	}
	vector<pair<int, int> > lens;
	int len_count[size_limit+1] = {};
	for(i=0; i<lengths.size(); i++) {
		//printf("%d\n", lengths[i]);
		len_count[lengths[i]]++;
	}
	for(i=0; i<k; i++) {
		if(!elem[i].first) {
			len_count[1]++;
		}
	}
	for(i=0; i<=size_limit; i++) {
		if(len_count[i] > 0) {
			pair<int, int> e{i, len_count[i]};
			lens.push_back(e);
		}
	}
	long long dp[m+1];
	dp[0] = 1;
	for(i=1; i<=m; i++) {
		dp[i] = 0;
		for(j=0; j<lens.size(); j++) {
			if(i >= lens[j].first) {
				dp[i] = (dp[i]+dp[i-lens[j].first]*lens[j].second)%mod;
			}
		}
	}
	printf("%lld\n", dp[m]);
}