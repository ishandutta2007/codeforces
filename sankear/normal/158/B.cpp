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

using namespace std;

int cnt[10];
int a[100100];

int main(){
	//freopen("cobweb.in", "r", stdin);
	//freopen("cobweb.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	for(int i = 0; i < n; i++){
		cnt[a[i]]++;
	}
	int ans = cnt[4];
	int can = min(cnt[1], cnt[3]);
	ans += can;
	cnt[1] -= can;
	cnt[3] -= can;
	ans += cnt[3];
	can = cnt[2] / 2;
	ans += can;
	cnt[2] -= can * 2;
	can = min(cnt[2], cnt[1] / 2);
	ans += can;
	cnt[2] -= can;
	cnt[1] -= can * 2;
	can = min(cnt[2], cnt[1]);
	ans += can;
	cnt[1] -= can;
	cnt[2] -= can;
	ans += cnt[2];
	ans += (cnt[1] + 3) / 4;
	printf("%d\n", ans);
	return 0;
}