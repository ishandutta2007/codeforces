#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int TC, N;

int main(){
	scanf("%d", &TC);
	while (TC--){
		LL sum=0, x=0;
		scanf("%d", &N);
		for (int i=1; i<=N; i++){
			int t;
			scanf("%d", &t);
			sum += t;
			x ^= t;
		}
		LL a = (1ll<<56);
		if (sum & 1) a++;
		printf("3\n%lld %lld %lld\n", a, (2*(x^a)-sum-a)/2, (2*(x^a)-sum-a)/2);
	}
	return 0;
}