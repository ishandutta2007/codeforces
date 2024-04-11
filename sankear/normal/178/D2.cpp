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

#define pb push_back

int n, k, need;
int a[20], b[20], cnt[20];
int val[20][20];
vector <int> v[20];
vector <int> lst[66000];

inline bool find(int sum, int mask){
	int pos = lower_bound(b, b + k, sum) - b;
	if(pos >= 0 && pos < k && b[pos] == sum && cnt[pos] > 0){
		return true;
	}
	return false;
}

inline bool check(int x, int mask){
	int sum = 0;
	for(int i = 0; i < n; i++){
		sum += val[x][i];
	}
	if(sum != need){
		return false;
	}
	if(x == n - 2){
		int sum = 0;
		for(int i = 0; i < n - 1; i++){
			sum += val[i][i];
		}
		if(!find(need - sum, mask)){
			return false;
		}
		sum = 0;
		for(int i = 0; i < n - 1; i++){
			sum += val[i][n - i - 1];
		}
		if(!find(need - sum, mask)){
			return false;
		}
		for(int i = 0; i < n; i++){
			sum = 0;
			for(int j = 0; j < n - 1; j++){
				sum += val[j][i];
			}
			if(!find(need - sum, mask)){
				return false;
			}
		}
	}
	return true;
}

void gen(int x, int y, int mask){
	if(x >= n){
		for(int i = 0; i < n; i++){
			int sum = 0;
			for(int j = 0; j < n; j++){
				sum += val[i][j];
			}
			if(sum != need){
				return;
			}
			sum = 0;
			for(int j = 0; j < n; j++){
				sum += val[j][i];
			}
			if(sum != need){
				return;
			}
		}
		int sum = 0;
		for(int i = 0; i < n; i++){
			sum += val[i][i];
		}
		if(sum != need){
			return;
		}
		sum = 0;
		for(int i = 0; i < n; i++){
			sum += val[i][n - i - 1];
		}
		if(sum != need){
			return;
		}
		printf("%d\n", need);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(j > 0){
					printf(" ");
				}
				printf("%d", val[i][j]);
			}
			printf("\n");
		}
		exit(0);
	}
	if(y == n - 1){
		int sum = 0;
		for(int i = 0; i < n - 1; i++){
			sum += val[x][i];
		}
		sum = need - sum;
		int pos = lower_bound(b, b + k, sum) - b;
		if(pos >= 0 && pos < k && b[pos] == sum && cnt[pos] > 0){
			cnt[pos]--;
			if(cnt[pos] == 0){
				mask ^= (1 << pos);
			}
			val[x][y] = sum;
			gen(x + 1, 0, mask);
			if(cnt[pos] == 0){
				mask |= (1 << pos);
			}
			cnt[pos]++;
		}
		return;
	}
	if(x == n - 1){
		for(int i = 0; i < n; i++){
			int sum = 0;
			for(int j = 0; j < n - 1; j++){
				sum += val[j][i];
			}
			sum = need - sum;
			int pos = lower_bound(b, b + k, sum) - b;
			if(pos >= 0 && pos < k && b[pos] == sum && cnt[pos] > 0){
				val[x][y] = sum;
				cnt[pos]--;
				if(cnt[pos] == 0){
					mask ^= (1 << pos);
				}
				gen(x, y + 1, mask);
				if(cnt[pos] == 0){
					mask |= (1 << pos);
				}
				cnt[pos]++;
			}
		}
		return;
	}
	for(int i = 0; i < (int)lst[mask].size(); i++){
		val[x][y] = b[lst[mask][i]];
		cnt[lst[mask][i]]--;
		int nmask = mask;
		if(cnt[lst[mask][i]] == 0){
			nmask ^= (1 << lst[mask][i]);
		}
		gen(x, y + 1, nmask);
		cnt[lst[mask][i]]++;
	}
}

int main(){
	//freopen("difference.in", "r", stdin);
	//freopen("difference.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	need = 0;
	for(int i = 0; i < n * n; i++){
		scanf("%d", &a[i]);
		b[i] = a[i];
		need += a[i];
	}
	need /= n;
	sort(b, b + n * n);
	k = unique(b, b + n * n) - b;
	for(int i = 0; i < n * n; i++){
		for(int j = 0; j < k; j++){
			if(b[j] == a[i]){
				v[j].pb(i);
				cnt[j]++;
				break;
			}
		}
	}
	int all = (1 << k);
	for(int i = 0; i < all; i++){
		for(int j = 0; j < k; j++){
			if((i & (1 << j)) != 0){
				lst[i].pb(j);
			}
		}
	}
	gen(0, 0, all - 1);
	return 0;
}