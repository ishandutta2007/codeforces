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
#include <queue>
#include <deque>
#include <functional>

using namespace std;

#define next _next

typedef long long ll;

const int maxn = 1000100;

char s[maxn];
int next[maxn], sum[maxn];

inline int get(int l, int r){
	return sum[r] - (l > 0 ? sum[l - 1] : 0);
}

int main(){
	//freopen("caravans.in", "r", stdin);
	//freopen("caravans.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int k;
	scanf("%d %s", &k, s);
	int n = strlen(s), last = n;
	for(int i = n - 1; i >= 0; i--){
		next[i] = last;
		if(s[i] == '1'){
			last = i;
		}
	}
	for(int i = 0; i < n; i++){
		sum[i] = (i > 0 ? sum[i - 1] : 0) + (s[i] == '1');
	}
	ll ans = 0;
	int j = 0;
	for(int i = 0; i < n; i++){
		j = max(j, i);
		while(j < n && get(i, j) < k){
			j++;
		}
		if(j < n && get(i, j) == k){
			ans += next[j] - j;
		}
	}
	cout << ans << endl;
	return 0;
}