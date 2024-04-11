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

int TC, N, Q;
int P[110], A[202020], K;
LL S[22][202020];
priority_queue<LL> PQ, del;

int main(){
	scanf("%d", &TC);
	while (TC--){
		scanf("%d %d", &N, &Q);
		int x=N;
		K = 0;
		for (int i=2; i<=x; i++){
			if (x % i == 0){
				P[++K] = N/i;
				while (x % i == 0) x /= i;
			}
		}
		for (int i=1; i<=K; i++) for (int j=0; j<P[i]; j++) S[i][j] = 0;
		for (int i=0; i<N; i++){
			scanf("%d", &A[i]);
			for (int j=1; j<=K; j++) S[j][i%P[j]] += (LL)A[i]*P[j];
		}
		while (PQ.size()) PQ.pop();
		while (del.size()) del.pop();
		for (int i=1; i<=K; i++) for (int j=0; j<P[i]; j++) PQ.push(S[i][j]);
		printf("%lld\n", PQ.top());
		while (Q--){
			int a, b;
			scanf("%d %d", &a, &b);
			a--;
			for (int i=1; i<=K; i++){
				del.push(S[i][a%P[i]]);
				S[i][a%P[i]] -= (LL)A[a]*P[i];
			}
			A[a] = b;
			for (int i=1; i<=K; i++){
				S[i][a%P[i]] += (LL)A[a]*P[i];
				PQ.push(S[i][a%P[i]]);
			}
			while (del.size() && PQ.top() == del.top()) PQ.pop(), del.pop();
			printf("%lld\n", PQ.top());
		}
	}
	return 0;
}