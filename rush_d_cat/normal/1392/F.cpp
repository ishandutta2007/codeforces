#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long LL;
const int N=1000000+10;
int n; LL a[N],ans[N];
int main(){
	scanf("%d",&n);
	LL sum=0;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]); sum+=a[i];
	}
	// (x * (x + n - 1)) * n / 2 <= sum
	LL x = 2 * sum / n - (n - 1);
	x = x / 2;
	for (int i = 1; i <= n; i ++) ans[i] = x + i - 1;
	LL val = (x + (x + n - 1)) * n / 2;
	LL need = sum - val;
	for (int i = 1; i <= need; i ++) ans[i] ++;
	for (int i = 1; i <= n; i ++) {
		printf("%lld ", ans[i]);
	}
	printf("\n");
}