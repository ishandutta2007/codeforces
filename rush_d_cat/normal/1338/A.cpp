#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int t,n;
LL a[N],b[N];
bool chk(LL k){
	LL d=0;
	for(int i=0;i<k;i++)d+=(1LL<<i);
	for(int i=1;i<=n;i++)b[i]=a[i];
	for(int i=2;i<=n;i++){
		if(b[i]+d<b[i-1])return false;
		b[i]=max(b[i-1],b[i]);
	}
	return true;
}
int main() {
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		for(int i=0;;i++){
			if(chk(i)){
				printf("%d\n", i); break;
			}
		}
	}
}