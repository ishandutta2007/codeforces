#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int t,n;
LL a[N];
LL sum = 0;
int main() {
	scanf("%d", &t);
	while(t--){
		scanf("%d",&n);

		sum = 0;
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			sum += a[i];
		}
		LL x = ((n-1) - sum % (n-1)) % (n-1);
		// x + k * (n-1)
		LL lef = -1, rig = 1e13;
		while(rig-lef>1){
			LL mid=(lef+rig)>>1;
			LL tot=(sum+mid*(n-1)+x)/(n-1);
			bool ok=1;
			for(int i=1;i<=n;i++)
				if(a[i]>tot)ok=false;
			if(ok)rig=mid;else lef=mid;
		}
		printf("%lld\n", rig * (n-1) + x);
    }
}