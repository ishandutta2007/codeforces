#include<bits/stdc++.h>

using namespace std;

#define NN 30

int SZ[NN];
int sz[NN];
int son[NN];

int calc(int n) {
	if(n == 1) {
		puts("YES");
		exit(0);
	}
	for(int i=n-1; i; i--) if(sz[i] > SZ[n]) {
		if(sz[i] == SZ[n] + 1 and !son[i]) continue;
		sz[i] -= SZ[n];
		son[i]++;
		calc(n-1);
		sz[i] += SZ[n];
		son[i]--;
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	int n;
	cin>>n;
	for(int i=1; i<=n; i++) cin>>sz[i];
	if(n == 1) return puts("YES"), 0;
	sort(sz+1, sz+n+1);
	reverse(sz+1, sz+n+1);
	for(int i=1; i<=n; i++) SZ[i] = sz[i];
	int tot = 0;
	for(int i=1; i<=n; i++) if(sz[i] == 1) tot++;
	
	for(int i=2; i<n; i++) if(abs(sz[i] - sz[i+1]) <= 1 and sz[i] + sz[i+1] >= n - 1) {
		return puts("NO"), 0;
	}
	
	if(sz[1] != n || tot <= n / 2) return puts("NO"), 0;
	for(int i=1; i<=n; i++) if(sz[i] == 2) return puts("NO"), 0;
	
	for(int i=1; i<=n; i++) if(sz[i] == 1) {
		calc(i-1);
		return puts("NO"), 0;
	}
}