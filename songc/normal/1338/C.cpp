#include <bits/stdc++.h>
#define pb push_back
#define all(v) v.begin(),v.end()
#define lb lower_bound
#define fi first
#define se second
#define INF (1ll<<60)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int TC;
LL N;

LL f(LL k, LL d){
	if (!d) return 0;
	if (k/(3*d) == 0) return f(k%(3*d), d>>2);
	if (k/(3*d) == 1){
		if (k%3 == 0) return 1*d + f(k%(3*d), d>>2);
		if (k%3 == 1) return 2*d + f(k%(3*d), d>>2);
		if (k%3 == 2) return 3*d + f(k%(3*d), d>>2);
	}
	if (k/(3*d) == 2){
		if (k%3 == 0) return 2*d + f(k%(3*d), d>>2);
		if (k%3 == 1) return 3*d + f(k%(3*d), d>>2);
		if (k%3 == 2) return 1*d + f(k%(3*d), d>>2);
	}
	if (k/(3*d) == 3){
		if (k%3 == 0) return 3*d + f(k%(3*d), d>>2);
		if (k%3 == 1) return 1*d + f(k%(3*d), d>>2);
		if (k%3 == 2) return 2*d + f(k%(3*d), d>>2);
	}
}

int main(){
	scanf("%d", &TC);
	while (TC--){
		scanf("%lld", &N);
		N--;
		LL d=1;
		for (; N>=3*d; d*=4) N-=3*d;
		if (N%3 == 0) printf("%lld\n", d+f(N, d>>2));
		if (N%3 == 1) printf("%lld\n", 2*d+f(N, d>>2));
		if (N%3 == 2) printf("%lld\n", 3*d+f(N, d>>2));
	}
	return 0;
}