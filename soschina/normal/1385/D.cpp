#include <cstdio>
#include <iostream>
using namespace std;
const int N = 131074;

int t, n, cnt[18][N];
char s[N];

int solve(int i, int l, int r){
	if(l == r) return s[l] - 'a' != i;
	int mid = (l + r) >> 1;
	return min(mid - l + 1 - cnt[i][mid] + cnt[i][l - 1] + solve(i + 1, mid + 1, r),
	r - mid - cnt[i][r] + cnt[i][mid] + solve(i + 1, l, mid));
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%s", &n, s + 1);
		for(int i = 1; i <= n; i++){
			for(int j = 0; j < 18; j++)
				cnt[j][i] = cnt[j][i - 1];
			if(s[i] - 'a' < 18) cnt[s[i] - 'a'][i]++;
		}
		printf("%d\n", solve(0, 1, n));
	}
	return 0;
}