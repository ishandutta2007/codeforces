#include<bits/stdc++.h>
using namespace std;

char s[100];

int n, k, ans1, ans2;

bool OK(int x, int y) {
	printf("1 %d %d\n", x, y);
	fflush(stdout);
	scanf("%s", s);
	if(s[0] == 'T') return true;
	return false;
}

int solve(int st, int en) {
	while(st < en){
		int mid = (st + en) >> 1;
		if(OK(mid, mid + 1)) en = mid;
		else st = mid + 1;
	}
	return st;
}

int main() {
	scanf("%d %d", &n, &k);
	int ans1 = solve(1, n);
	if(ans1 == 1){
		ans2 = solve(2, n);
		printf("2 %d %d\n", ans1, ans2);
		fflush(stdout);
		return 0;
	}
	ans2 = solve(1, ans1 - 1);
	if( OK(ans2, ans1) ){
		printf("2 %d %d\n", ans1, ans2);
		fflush(stdout);
		return 0;
	}
	ans2 = solve(ans1 + 1, n);
	printf("2 %d %d\n", ans1, ans2);
	fflush(stdout);
	return 0;
}