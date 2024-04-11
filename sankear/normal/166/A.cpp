#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <complex>

using namespace std;

typedef pair <int, int> pii;

int ans[100];
pii p[100];

bool cmp (const pii &a, const pii &b){
	if(a.first != b.first){
		return a.first > b.first;
	}
	return a.second < b.second;
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; i++){
		scanf("%d %d", &p[i].first, &p[i].second);
	}
	sort(p, p + n, cmp);
	int cur = 1, i = 0;
	while(i < n){
		int j = i;
		while(j + 1 < n && p[i] == p[j + 1]){
			j++;
		}
		for(int z = cur; z < cur + j - i + 1; z++){
			ans[z] = j - i + 1;
		}
		cur += j - i + 1;
		i = j + 1;
	}
	printf("%d\n", ans[k]);
	return 0;
}