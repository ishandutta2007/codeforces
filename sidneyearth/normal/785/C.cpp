#include<cstdio>
typedef long long ll;
int main(){
	ll n, m;
	scanf("%I64d%I64d", &n, &m);
	if(m >= n) printf("%I64d\n", n);
	else{
		ll l = 0, r = 1e18;
		while(r - l > 1){
			ll mid = (l + r) / 2;
			if(mid + 1 > (2 * (n - m) - 1) / mid) r = mid;
			else l = mid;
		}
		printf("%I64d\n", m + r);
	}
	return 0;
}