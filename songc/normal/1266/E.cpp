#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> pii;

int N, Q;
LL ans;
int A[202020];
int cnt[202020];

map<pii, int> M;

int main(){
	scanf("%d", &N);
	for (int i=1; i<=N; i++){
		scanf("%d", &A[i]);
		ans += A[i];
	}
	scanf("%d", &Q);
	while (Q--){
		int s, t, u;
		scanf("%d %d %d", &s, &t, &u);
		if (M.find(pii(s,t)) != M.end()){
			int c = M[pii(s,t)];
			if (cnt[c] <= A[c]) ans++; 
			cnt[c]--;
			M.erase(pii(s, t));
		}
		if (u != 0){
			M[pii(s,t)] = u;
			if (cnt[u] < A[u]) ans--; 
			cnt[u]++;
		}
		printf("%lld\n", ans);
	}
	return 0;
}