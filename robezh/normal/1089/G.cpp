#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll inf = 1e18;

ll k;
ll a[10], sum[10];

void solve(int tnum) {
	scanf("%lld",&k);
	for(int i=1;i<=7;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=7;i++) sum[i] = sum[i-1] + a[i];
	ll ans = inf;
	for(int x=1;x<=7;x++) {
		for(int y=x;y<=7;y++) {
			if(sum[y]-sum[x-1] >= k) {
				ans = min(ans, (ll)y-x+1);
			}
		}
	}
	for(int x=0;x<=7;x++) {
		for(int y=0;y<=7;y++) {
			ll kk = k;
			if(x!=0) kk -= sum[7] - sum[x-1];
			if(y!=0) kk -= sum[y];
			ll day = ((kk + sum[7] - 1) / sum[7]) * 7;
			if(x!=0) day += 7-x+1;
			if(y!=0) day += y;
			ans = min(ans, day);
		}
	}
	printf("%lld\n",ans);
}

int main() {
	int tnum; scanf("%d",&tnum);
	for(int i=1;i<=tnum;i++) solve(i);
}