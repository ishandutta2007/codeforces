#include <bits/stdc++.h>
#define fi first
#define se second
#define lb lower_bound
#define pb push_back
#define MOD 1000000007
#define INF (1ll<<60)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int N, M, TC;
int A[55], B[55];

int main(){
	scanf("%d", &TC);
	while (TC--){
		scanf("%d %d", &N, &M);
		for (int i=1; i<=N; i++) scanf("%1d", &A[i]);
		for (int i=1; i<=M; i++) scanf("%1d", &B[i]);
		if (N < M){
			puts("NO");
			continue;
		}
		bool tf = true;
		for (int i=2; i<=M; i++) if (B[i] != A[N-M+i]) tf = false;
		if (!tf){
			puts("NO");
			continue;
		}
		tf = false;
		for (int i=1; i<=N-M+1; i++) if (B[1] == A[i]) tf = true;
		puts(tf?"YES":"NO");
	}
	return 0;
}