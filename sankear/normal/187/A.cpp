#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <cstring>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <complex>

using namespace std;

bool used[200200];
int a[200200], b[200200], val[200200];

int main(){
	//freopen("bad-hashing.in", "r", stdin);
	//freopen("bad-hashing.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	for(int i = 0; i < n; i++){
		scanf("%d", &b[i]);
	}
	for(int i = 0; i < n; i++){
		val[b[i]] = i;
	}
	for(int i = 0; i < n; i++){
		a[i] = val[a[i]];
	}
	int ans = 0, l = 0, r = n - 1;
	for(int i = 0; i < n; i++){
		if(used[i]){
			continue;
		}
		if(a[l] == i){
			l++;
			continue;
		}
		while(true){
			used[a[r]] = true;
			r--;
			ans++;
			if(a[r + 1] == i){
				break;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}