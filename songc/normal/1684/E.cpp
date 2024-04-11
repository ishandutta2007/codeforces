#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define lb lower_bound
#define MOD 1000000007
#define INF (1ll<<62)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int N, K, D, Q;
int ans = MOD;
map<int,int> S;
int T[404040], cnt[404040];

void update(int id, int s, int e, int t, int v){
	if (t < s || e < t) return;
	if (s == e){cnt[id] += v, T[id] = cnt[id]*s; return;}
	int m=s+e>>1;
	update(id*2, s, m, t, v);
	update(id*2+1, m+1, e, t, v);
	T[id] = T[id*2] + T[id*2+1];
	cnt[id] = cnt[id*2] + cnt[id*2+1];
}

int f(int id, int s, int e, int k){
	if (s == e) return min(k/s, cnt[id]);
	int m=s+e>>1;
	if (T[id*2] < k) return cnt[id*2] + f(id*2+1, m+1, e, k-T[id*2]);
	return f(id*2, s, m, k); 
}

int main(){
	scanf("%d", &Q);
	while (Q--){
		int a;
		scanf("%d %d", &N, &K);
		for (int i=1; i<=N; i++) scanf("%d", &a), S[a]++;
		for (int i=1; i<=4*N; i++) T[i] = cnt[i] = 0;
		for (pii t : S) update(1, 1, N, t.se, 1);
		ans = f(1, 1, N, N) - f(1, 1, N, K);
		int c = 0;
		for (int i=1; i<=N; i++){
			if (S[i-1] == 0) c++;
			update(1, 1, N, S[i-1], -1);
			if (c > K) break;
			ans = min(ans, f(1, 1, N, N) - f(1, 1, N, K));
		}
		printf("%d\n", ans);
		S.clear();
	}
	return 0;
}