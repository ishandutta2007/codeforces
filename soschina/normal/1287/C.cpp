#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 100;

int n, ans, l = -1, r = -1, cnt, num;

int allcnt[2], a[2][MAXN], len[2], spec[2][2], slen[2];

int calc(int allcnt, int a[], int len){
	int j = 0;
	while(j < len && a[j] <= allcnt)
		allcnt -= a[j], j++;
	return (len - j) << 1;
}

int main(){
	scanf("%d", &n);
	if(n == 1){
		putchar('0');
		return 0;
	}
	allcnt[0] = n >> 1;
	allcnt[1] = (n >> 1) + (n & 1);
	while(n--){
		scanf("%d", &num);
		if(num == 0) cnt++;
		else{
			r = num & 1;
			allcnt[r]--;
			if(!~l){ if(cnt) spec[r][slen[r]++] = cnt; }
			else if(l != r) ans++;
			else if(cnt) a[r][len[r]++] = cnt;
			l = r, r = -1;
			cnt = 0;
		}
	}
	if(!~l){
		putchar('1');
		return 0;
	}
	if(cnt) spec[l][slen[l]++] = cnt;
	for(int i = 0; i < 2; i++){
		sort(a[i], a[i] + len[i]);
		if(slen[i] == 0) ans += calc(allcnt[i], a[i], len[i]);
		else if(slen[i] == 1){
			int ret = calc(allcnt[i], a[i], len[i]) + 1;
			if(spec[i][0] <= allcnt[i]) ret = min(ret, calc(allcnt[i] - spec[i][0], a[i], len[i]));
			ans += ret;
		}else{
			int ret = calc(allcnt[i], a[i], len[i]) + 2;
			if(spec[i][0] <= allcnt[i]) ret = min(ret, calc(allcnt[i] - spec[i][0], a[i], len[i]) + 1);
			if(spec[i][1] <= allcnt[i]) ret = min(ret, calc(allcnt[i] - spec[i][1], a[i], len[i]) + 1);
			if(spec[i][0] + spec[i][1] <= allcnt[i]) ret = min(ret, calc(allcnt[i] - spec[i][0] - spec[i][1], a[i], len[i]));
			ans += ret;
		}
	}
	printf("%d", ans);
	return 0;
}