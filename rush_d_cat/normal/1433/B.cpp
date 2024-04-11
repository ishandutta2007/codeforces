#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int t, n, a[N];
int main() {
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		int l=0,r=n+1;
		for(int i=1;i<=n;i++){
			if(a[i]) {
				l=i; break;
			}
		}
		for(int i=n;i>=1;i--){
			if(a[i]){
				r=i; break;
			}
		}
		int ans=0;
		for(int i=l;i<=r;i++)if(!a[i])ans++;
		printf("%d\n", ans);
	}
}