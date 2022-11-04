#include<bits/stdc++.h>
#define pb push_back
#define y second
#define x first

using namespace std;
typedef long long INT;
typedef pair<int, int> pii;
template<typename T, typename U> inline void smin(T &a, const U &b) {if(a>b) a=b;}
template<typename T, typename U> inline void smax(T &a, const U &b) {if(a<b) a=b;}

int root[101010];

int find(int u) {
	return root[u]==u ? u : root[u]=find(root[u]);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	
	int n, k; scanf("%d %d", &n, &k);
	for(int i=1; i<=n; i++) root[i]=i;
	
	int ans=0;
	while(k--) {
		int u, v; scanf("%d %d", &u, &v);
		u=find(u), v=find(v);
		if(u==v) ans++;
		else root[u]=v;
	}
	cout<<ans;
}