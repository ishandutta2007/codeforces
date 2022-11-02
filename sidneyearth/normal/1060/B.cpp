#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long ll;
int S(ll n){
	int rnt = 0;
	while(n) rnt += n % 10, n /= 10;
	return rnt;
}
int main(){
	ll n; scanf("%I64d", &n);
	ll a = 0;
	while(a * 10 + 9 <= n) a = a * 10 + 9;
	ll b = n - a;
	printf("%d\n", S(a) + S(b));
	return 0;
}