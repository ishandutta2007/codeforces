#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int t,n,q,a[N];
char s[N];
int premax[N],premin[N],sufmax[N],sufmin[N];

int main() {
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%s",&n,&q,s+1);
		for(int i=1;i<=n;i++){
			a[i]=a[i-1]+(s[i]=='+'?1:-1);
		}
		premin[0]=0,premax[0]=0;
		for(int i=1;i<=n;i++){
			premin[i]=min(a[i],premin[i-1]);
			premax[i]=max(a[i],premax[i-1]);
		}
		sufmin[n]=sufmax[n]=a[n];
		for(int i=n-1;i>=1;i--){
			sufmin[i]=min(a[i],sufmin[i+1]);
			sufmax[i]=max(a[i],sufmax[i+1]);
		}
		while(q--){
			int l,r; scanf("%d%d",&l,&r);
			int mx=max(premax[l-1],a[l-1]+sufmax[r]-a[r]);
			int mn=min(premin[l-1],a[l-1]+sufmin[r]-a[r]);

			printf("%d\n", mx-mn+1);
		}
	}
}