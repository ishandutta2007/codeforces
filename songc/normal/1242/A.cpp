#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long LL;

LL N, M;
LL d=1;

int main(){
	scanf("%lld", &N);
	M = N;
	for (LL i=2; i*i<=N; i++){
		if (N % i == 0){
			if (d != 1){
				puts("1");
				return 0;
			}
			d = i;
			while (N % i == 0) N /= i;
		}
	}
	if (N != 1){
		if (d != 1){
			puts("1");
			return 0;
		}
		printf("%lld\n", M);
		return 0;
	}
	printf("%lld\n", d);
	return 0;
}