#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 300000 + 10;
int t,n,a[N];
int main() {
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int mx=0,mn=1e9+1,p;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if(a[i]>mx){
				mx=a[i]; p=i;
			}
			if(a[i]<mn){
				mn=a[i];
			}
		}
		for(int i=1;i<=n;i++){
			if(a[i]==mx) {
				if((i>1&&a[i]>a[i-1]) || (i<n&&a[i]>a[i+1]))
					p=i;
			}
		}
		if(mx==mn) printf("-1\n");
		else printf("%d\n", p);
	}
}