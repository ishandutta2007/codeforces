#include<bits/stdc++.h>

#define pb push_back
#define x first
#define y second
using namespace std;
typedef long long INT;
typedef pair<int, int> pii;
typedef vector<int> VI;
int power(int a, int b, int m, int ans=1) {
	for(; b; b>>=1, a=1LL*a*a%m) if(b&1) ans=1LL*ans*a%m;
	return ans;
}

const int NN = 100111;
int a[NN], b[NN];
int B[NN];
int n;

int calc(int u) {
	int ans=0;
	while(u<=n) ans+=B[u], u+=u&-u;
	return ans;
}

void update(int u) {
	while(u) B[u]++, u-=u&-u;
	}
int main() {
#ifndef	ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	cin >> n;
	for(int i=1; i<=n; i++) scanf("%d", a+i);
	int nn = 0;
	for(int i=1; i<=n; i++) {
		int u; scanf("%d", &u);
		b[u] = ++nn;
	}
	int ans = 0;
	for(int i=1; i<=n; i++) {
		int v = a[i];
		int u = b[v];
		if(calc(u)) ans++;
		update(u);
	}
	cout << ans << endl;
	return 0;
}