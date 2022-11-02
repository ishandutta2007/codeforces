#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1e5+10;

int t,n,d[N];
ll w[N],c[N];

int main()
{
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=0;i <= n;i++) d[i] = 0;
		ll ans=0;
		for(int i=1; i<= n;i++) scanf("%lld",&w[i]) , ans += w[i];
		int fr,to;
		for(int i=1;i < n;i++) scanf("%d%d",&fr,&to) , d[fr]++ , d[to]++;
		int cnt=0;
		for(int i=1;i <= n;i++) for(int j=2;j <= d[i];j++) c[++cnt] = w[i];
		sort(c+1,c+1+cnt);
		printf("%lld ",ans);
		for(int i=2;i < n;i++){
			if(cnt) ans += c[cnt--];
			printf("%lld ",ans);
		}
		puts("");
	}
}