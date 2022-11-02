#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long ll;
void exgcd(int a, int b, ll &d, ll &x, ll &y){
	if(b) exgcd(b, a % b, d, y, x), y -= a / b * x;
	else d = a, x = 1, y = 0;
}
int main(){
	int la, ra, ta;
	scanf("%d%d%d", &la, &ra, &ta);
	int lb, rb, tb;
	scanf("%d%d%d", &lb, &rb, &tb);
	ll x, y, d;
	exgcd(ta, tb, d, x, y);
//	printf("ta:%d tb:%d d:%I64d\n", ta, tb, d);
	ll k, c;
	if(rb > ra) k = (rb - ra) / tb * -1, c = rb + k * tb - ra;
	else k = (ra - rb + tb - 1) / tb * tb, c = rb + k * tb - ra;
//	printf("c:%lld\n", c);
	ll c1 = c / d * d;
	ll ka = c1 / d * x;
	ll kb = c1 / d * y * -1 + k;
//	printf("c1:%lld\n", c1);
//	printf("ka:%lld kb:%lld\n", ka, kb);
//	printf("la:%lld ra:%lld lb:%lld rb:%lld\n",
//			la + ka * ta, ra + ka * ta, lb + kb * tb, rb + kb * tb);
	ll ans1 = min(ra+(ll)ka*ta,rb+(ll)kb*tb)-max(la+(ll)ka*ta,lb+(ll)kb*tb);
	ll c2 = (c + d - 1) / d * d;
	ka = c2 / d * x;
	kb = c2 / d * y * -1 + k;
//	printf("c2:%lld\n", c2);
//	printf("ka:%lld kb:%lld\n", ka, kb);
//	printf("la:%lld ra:%lld lb:%lld rb:%lld\n",
//			la + ka * ta, ra + ka * ta, lb + kb * tb, rb + kb * tb);
	ll ans2 = min(ra+(ll)ka*ta,rb+(ll)kb*tb)-max(la+(ll)ka*ta,lb+(ll)kb*tb);
	printf("%I64d\n", max(0ll, max(ans1, ans2) + 1));
	return 0;
}