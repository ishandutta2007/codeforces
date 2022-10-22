#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int N;
LL ans;
LL T[1010101];
vector<int> A;

int main(){
	scanf("%d", &N);
	for (int i=1; i<=N; i++){
		int k, a, b, f;
		scanf("%d", &k);
		scanf("%d", &f);
		b = f;
		for (int j=2; j<=k; j++){
			scanf("%d", &a);
			if (b < a) f = -1;
			b = a;
		}
		if (f != -1){
			A.push_back(f);
			T[b]++;
		}
	}
	for (int i=1000000; i>=0; i--) T[i] += T[i+1];
	for (int x : A) ans += T[x];
	printf("%lld\n", (LL)N*N-ans);
	return 0;
}