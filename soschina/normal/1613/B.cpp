#include <cstdio>
#include <iostream>
using namespace std;
const int N = 2e5 + 1;

int t, n, a[N], mina, cnt;

int main(){
	scanf("%d", &t);
	while(t--){
		cnt = 0;
		mina = 0x7fffffff;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++){
			scanf("%d", &a[i]);
			mina = min(mina, a[i]);
		}
		for(int i = 1; i <= n && cnt < n / 2; i++)
			if(a[i] != mina){
				printf("%d %d\n", a[i], mina);
				cnt++;
			}
	}
	return 0;
}