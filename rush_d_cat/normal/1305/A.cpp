#include <bits/stdc++.h>
using namespace std;
const int N = 200000 + 10;
typedef long long LL;
int t,n,a[N],b[N];
int main() {
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)scanf("%d",&b[i]);
		sort(a+1,a+1+n);
		sort(b+1,b+1+n);
		for(int i=1;i<=n;i++)printf("%d ", a[i]);printf("\n");
		for(int i=1;i<=n;i++)printf("%d ", b[i]);printf("\n");
	}
}