#include <cstdio>
using namespace std;

int t, n;

long long f(int n){
	if(!n) return 1;
	if(n % 10 == 9) return f(n / 10) * (n % 10 + 1);
	int tmp = n / 100, cnt = 1;
	while(tmp && tmp % 10 == 0) tmp /= 100, cnt++;
	if(!tmp) return f(n / 10) * (n % 10 + 1);
	tmp = n;
	int tmp2 = 1;
	while(--cnt){
		tmp2 *= 100;
		tmp += 9 * tmp2;
	}
	tmp2 *= 100;
	tmp -= tmp2;
	return f(n / 10) * (n % 10 + 1) + f(tmp / 10) * (9 - n % 10);
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		printf("%lld\n", f(n) - 2);
	}
}