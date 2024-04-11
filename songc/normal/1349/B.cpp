#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int TC;
int N, K;
int A[101010], X[101010], P[101010], S[101010];

int main(){
	scanf("%d", &TC);
	while (TC--){
		scanf("%d %d", &N, &K);
		S[N+1] = -N-100;
		bool x = false;
		for (int i=1; i<=N; i++) scanf("%d", &A[i]), x = x || (A[i] == K);
		if (N == 1){
			if (A[1] == K) puts("yes");
			else puts("no");
			continue;
		}
		for (int i=1; i<=N; i++) X[i] = X[i-1] + (A[i]<K?-1:1), P[i] = min(X[i], P[i-1]);
		for (int i=N; i>0; i--) S[i] = max(X[i], S[i+1]);
		bool tf = false;
		for (int i=1; i<=N; i++){
			if (i > 1 && S[i] - P[i-2] > 0) tf = true;
			if (S[i+1] - P[i-1] > 0) tf = true;
		}
		puts((tf&&x)?"yes":"no");
	}
	return 0;
}