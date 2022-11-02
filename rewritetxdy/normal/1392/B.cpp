#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 2e5+10;

int t,c[N],n;
ll k;

int main()
{
	scanf("%d",&t);
	while(t--){
		scanf("%d%lld",&n,&k);
		int maxn = -2e9;
		for(int i=1;i <= n;i++) scanf("%d",&c[i]) , maxn = max(maxn,c[i]);
		for(int i=1;i <= n;i++) c[i] = maxn-c[i];
		if(k&1){
			for(int i=1;i <= n;i++) printf("%d ",c[i]); puts("");
		}
		else{
			maxn = -2e9;
			for(int i=1; i<= n;i++) maxn = max(maxn,c[i]);
			for(int i=1;i <= n;i++) c[i] = maxn-c[i];
			for(int i=1;i <= n;i++) printf("%d ",c[i]); puts("");
		}
	}
	return 0;
}