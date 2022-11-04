#include<bits/stdc++.h>
#define pb push_back
#define y second
#define x first

using namespace std;
typedef long long INT;
typedef pair<int, int> pii;
template<typename T, typename U> inline void smin(T &a, const U &b) {if(a>b) a=b;}
template<typename T, typename U> inline void smax(T &a, const U &b) {if(a<b) a=b;}

#define NN 202020
#define INF 0x3f3f3f3f3f3f3f3fLL

INT a[NN], b[NN], ta, tb, ans;
int n, m, k;

inline void calc(int id) {
	if(id==n) ans=INF;
	else {
		INT T=a[id+1]+ta;
		int I=lower_bound(b+1, b+m+1, T)-b;
		I+=k-id;
		if(I>m) ans=INF;
		else smax(ans, b[I]+tb);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	
	scanf("%d %d %I64d %I64d %d", &n, &m, &ta, &tb, &k);
	for(int i=1; i<=n; i++) scanf("%I64d", a+i);
	for(int i=1; i<=m; i++) scanf("%I64d", b+i);
	
	for(int i=0; i<=min(n, k); i++) calc(i);
	if(ans<INF) cout<<ans<<endl;
	else puts("-1");
}