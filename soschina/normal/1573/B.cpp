#include <cstdio>
#include <iostream>
using namespace std;
const int N = 1e5;

int t, n, a[N], ai[N], b[N], bi[N], alen, blen, ans;

int main(){
	scanf("%d", &t);
	while(t--){
		alen = blen = 0;
		ans = 0x7fffffff;
		scanf("%d", &n);
		for(int i = 0; i < n; i++){
			scanf("%d", a + alen);
			if(!alen || a[alen] < a[alen - 1]){
				ai[alen] = i;
				alen++;
			}
		}
		for(int i = 0; i < n; i++){
			scanf("%d", b + blen);
			if(!blen || b[blen] > b[blen - 1]){
				bi[blen] = i;
				blen++;
			}
		}
		int j = 0;
		while(b[j] < a[0]) j++;
		for(int i = 0; i < alen; i++){
			while(j && b[j - 1] > a[i]) j--;
			ans = min(ans, ai[i] + bi[j]);
		}
		printf("%d\n", ans);
	}
	return 0;
}