#include<bits/stdc++.h>

#define inf 0x3f3f3f3f

#define pb push_back

#define y second

#define x first



using namespace std;

typedef long long INT;

typedef pair<int, int> pii;

typedef pair<int, pii> pi3;

template<typename T, typename U> inline void smin(T &a, const U &b) {if(a>b) a=b;}

template<typename T, typename U> inline void smax(T &a, const U &b) {if(a<b) a=b;}

typedef vector<int> VI;



#define NN 1000100



pii edge[NN];

int deg[NN], add[NN];

vector<pii> ans;

int flag[NN], f[NN];



main() {

#ifndef ONLINE_JUDGE

	freopen("in.in", "r", stdin);

	freopen("out.out", "w", stdout);

#endif

	

	int n, m; scanf("%d %d", &n, &m);

	for(int i=0; i<m; i++) {

		int u, v; scanf("%d %d", &u, &v);

		edge[i]=pii(u, v);

		deg[u]++, deg[v]++;

	}

	for(int i=1; i<=n; i++) add[i]=deg[i]+1>>1;

	

	srand(time(0));

	for(int i=0; i<m; i++) f[i]=i;

	random_shuffle(f, f+m);

	random_shuffle(f, f+m);

	

	int cnt=n+m+1>>1;

	for(int i=m; i-- && cnt>=1; ) {

		int I=f[i], u=edge[I].x, v=edge[I].y;

		if(add[u]>0 && add[v]>0) {

			ans.pb(pii(u, v));

			add[u]--; add[v]--; cnt--;

			flag[I]=1;

			if(cnt==0) break;

		}

	}

	for(int i=m; i-- && cnt>=1; ) {

		int I=f[i], u=edge[I].x, v=edge[I].y;

		if(flag[I]) continue;

		if(add[u]<=0 && add[v]<=0) continue;

		ans.pb(pii(u, v));

		add[u]--; add[v]--; cnt--;

		if(cnt==0) break;

	}

	

	printf("%d\n", ans.size());

	for(pii p: ans) printf("%d %d\n", p.x, p.y);

}