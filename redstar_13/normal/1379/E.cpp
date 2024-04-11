#include <bits/stdc++.h>

using namespace std;
int ans[100011];
int n, k;

inline int ok(int n, int k) {
	if(n%2==0) return 0;
	if(n==1 and k==0) return 1;
	if(k>n/2-1) return 0;	
	if(n == 9 and k == 2) return 0;
	if(__builtin_popcount(n+1) == 1) {
		if(k == 1) return 0;
		return 1;
	}
	return k != 0;
}

void solve(int st, int ed, int k) {
	int n = ed - st;
//	cerr<<st<<' '<<ed<<' '<<k<<endl;
	if(ed == st + 1) {
		assert(k == 0);
		return ;
	}
	for(int i=st+1; i<ed; i+=2) {
		int pj = i-st;
		int pk = n-pj-1;
		int nk = k;
		if(pj * 2 <= pk or pk * 2 <= pj) {
			nk--;
		}
		if(nk<0) continue;
		for(int j=0; j<=max(0, pj/2-1) and j<=nk; j++) {
			if(ok(pj, j) and ok(pk, nk-j)) {
				ans[st+1] = st;
				ans[i+1] = st;
				solve(st+1, i+1, j);
				solve(i+1, ed, nk-j);
				return ;
			}
		}
	}
	assert(0);
}

inline int solve() {
	if(ok(n, k) == 0) return 0;
	solve(1, n+1, k);
	return 1;	
}

int main (){
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif
		
	cin >> n >> k;
	if(solve() == 0) return puts("NO");
	puts("YES");
	for(int i=1; i<=n; i++) printf("%d ", ans[i]);
	
	return 0;
}