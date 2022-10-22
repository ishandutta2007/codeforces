#include <bits/stdc++.h>
#define pb push_back
#define all(v) v.begin(),v.end()
#define lb lower_bound
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int TC;
int N, K, M;
LL cnt[40], ans;
LL D[40][40];

int main(){
	scanf("%d", &TC);
	while (TC--){
		scanf("%d %d", &K, &M);
		for (N=0; (1<<N) <= K; N++){
			if (K >= (1<<(N+1))) cnt[N] = (1<<N) % M;
			else cnt[N] = (K - (1<<N) + 1) % M;
		}
		N--;
		for (int i=0; i<=N; i++) D[1][i] = cnt[i];
		for (int i=2; i<=N+1; i++){
			LL sum=0;
			for (int j=1; j<=N; j++){
				sum = (sum+D[i-1][j-1])%M;
				D[i][j] = sum * cnt[j] % M;
			}
		}
		ans = 0;
		for (int i=1; i<=N+1; i++) for (int j=0; j<=N; j++) ans = (ans+D[i][j])%M;
		printf("%lld\n", ans);
	}
	return 0;
}