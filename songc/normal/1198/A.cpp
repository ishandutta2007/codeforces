#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int N, K;
int ans = 1234567890;
map<int,int> M;

inline int LOG(int x){
	for (int i=0; ; i++) if ((1<<i) >= x) return i;
}

int main(){
	scanf("%d %d", &N, &K);
	for (int i=1; i<=N; i++) {
		int x;
		scanf("%d", &x);
		M[x]++; 
	}
	int cnt = 1, sum=M.begin()->second;
	auto l=M.begin(), r=M.begin();
	while (1){
		while (LOG(cnt) * N > K * 8) cnt--, sum -= l->second, l = next(l);
		ans = min(ans, N-sum);
		r = next(r);
		if (r == M.end()) break;
		cnt++;
		sum += r->second;
	}
	printf("%d\n", ans);
	return 0;
}