#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 5e5+10;
const int p = 1e9+7;

ll t,n,c[N],cnt[64],z[64];

int main()
{
	z[0] = 1;
	for(int i=1;i <= 60;i++) z[i] = z[i-1] << 1;
	scanf("%lld",&t);
	while(t--){
		memset(cnt,0,sizeof(cnt));
		scanf("%lld",&n);
		for(int i=1;i <= n;i++) scanf("%lld",&c[i]);
		for(int i=1;i <= n;i++) for(int j=0;j < 60;j++)
			if(c[i]&z[j]) cnt[j]++;
		ll ans = 0;
		for(int i=1;i <= n;i++){
			ll sum = 0,summ = 0;
			for(int j=0;j < 60;j++)
				if(c[i]&z[j]) sum = (sum+z[j]%p*cnt[j])%p;
			for(int j=0;j < 60;j++)
				summ = (summ+z[j]%p*((c[i]&z[j]) ? n : cnt[j]))%p;
			ans = (ans+sum*summ)%p;
		}
		printf("%lld\n",ans);
	}
}