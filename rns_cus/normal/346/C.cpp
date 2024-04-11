#include<bits/stdc++.h>
using namespace std;

#define N 1001000

int n, a, b, mn, tmp, arr[N], cnt, cnt1, ans;
char s[N];

int main(){
//	freopen("cc.in", "r", stdin);

	scanf("%d", &n);
	for(int i = 0; i < n; i ++){
		scanf("%d", arr + i);
		assert(arr[i] > 1);
	}
	sort(arr, arr + n);
	int cnt = unique(arr, arr + n) - arr;
	scanf("%d %d", &a, &b);

	int step = 0;
	while(a > b){
		mn = a, cnt1 = 0;
		for(int i = 0; i < cnt; i ++){
			assert(arr[i] != 0);
			tmp = a / arr[i] * arr[i];
			if(tmp < b){ continue; }

			arr[cnt1 ++] = arr[i];
			if(mn > tmp) mn = tmp;
		}
		cnt = cnt1;
		if(mn < a) a = mn;
		else a --;
		ans ++;
	}
	printf("%d\n", ans);
}