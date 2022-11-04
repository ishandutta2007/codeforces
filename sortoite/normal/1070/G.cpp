#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back

using namespace std;
typedef long long INT;
typedef pair<int,int> pii;
typedef vector<int> VI;

const int N = 111;
int n, m, a[N], b[N], s[N], h[N], pos[N], flag[N];

int can(int x) {
	int updated = true;
	for (int i=1; i<=m; i++) flag[i]=0;
	for (int i=1; i<=n; i++) b[i]=a[i];
	VI ans;
	while (updated) {
		updated = false;
		for (int i=1; i<=x; i++) {
			int u=pos[i];
			if (!u || flag[u]) continue;
			int ok = 1, v = h[u];
			for (int j=i; j<=x && ok; j++) {
				v+=b[j];
				if (v<0) ok=0;
			}
			if (!ok) continue;
			updated = true;
			for (int j=i; j<=x; j++) {
				b[j]=0;
				int v=pos[j];
				if (!v || flag[v]) continue;
				flag[v]=true;
				ans.pb(v);
			}
		}
		for (int i=n; i>=x; i--) {
			int u=pos[i];
			if (!u || flag[u]) continue;
			int ok = 1, v = h[u];
			for (int j=i; j>=x && ok; j--) {
				v+=b[j];
				if (v<0) ok=0;
			}
			if (!ok) continue;
			updated = true;
			for (int j=i; j>=x; j--) {
				b[j]=0;
				int v=pos[i];
				if (!v || flag[v]) continue;
				flag[v]=true;
				ans.pb(v);
			}
		}
	}
	if (ans.size()==m) {
		printf("%d\n", x);
		for (int u : ans) printf("%d ", u);
		exit(0);
	}
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif

	cin>>n>>m;
	for (int i=1; i<=m; i++) scanf("%d%d", s+i, h+i), pos[s[i]]=i;
	for (int i=1; i<=n; i++) scanf("%d", a+i);

	for (int i=1; i<=n; i++) can(i);
	puts("-1");

	return 0;
}