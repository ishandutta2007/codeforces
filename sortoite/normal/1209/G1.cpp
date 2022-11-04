#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back

using namespace std;
typedef long long INT;
typedef pair<int,int> pii;
typedef vector<int> VI;

const int NN = 200020;

int mx[NN], a[NN], mx1[NN][20], cnt[NN];

int calc(int st, int ed) {
	int u=__lg(ed-st+1);
	return max(mx1[st][u], mx1[ed-(1<<u)+1][u]);
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif

	int n, q, u;
	cin>>n>>q;
	for (int i=1; i<=n; i++) scanf("%d", &u), mx[u]=max(mx[u], i), a[i]=u;
	for (int i=0; (1<<i)<=n; i++) {
		for (int j=1; j+(1<<i)<=n+1; j++) {
			if (i) mx1[j][i]=max(mx1[j][i-1], mx1[j+(1<<i-1)][i-1]);
			else mx1[j][0]=mx[a[j]];
		}
	}
	int ans = 0;
	for (int i=1; i<=n; ) {
		int st = i;
		while (true) {
			int ed=calc(i, mx[a[st]]);
			if (st==ed) break;
			st=ed;
		}
		int mx = 0;
		for (int j=i; j<=st; j++) mx=max(mx, ++cnt[a[j]]);
		ans+=st-i+1-mx;
		i=st+1;
	}
	printf("%d\n", ans);

	return 0;
}