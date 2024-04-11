#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define pb push_back
#define y second
#define x first

using namespace std;
typedef long long INT;
typedef pair<int, int> pii;
template<typename T, typename U> inline void smin(T &a, const U &b) {if(a>b) a=b;}
template<typename T, typename U> inline void smax(T &a, const U &b) {if(a<b) a=b;}
typedef vector<int> VI;

#define NN 505
#define MM 1010

int in[NN], out[NN], w[NN], s[NN], v[NN];
int id[NN], ans;
int dp[NN][MM], mx[MM];

int main() {
#ifndef	ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif

	int n, S; scanf("%d %d", &n, &S);
	for(int i=0; i<n; i++) {
		scanf("%d %d %d %d %d", in+i, out+i, w+i, s+i, v+i);
		id[i]=i;
	}
	in[n]=0, out[n]=n<<1, id[n]=n, s[n++]=S;
	
	sort(id, id+n, [](int u, int v) {
		return out[u]-in[u]<out[v]-in[v];
	});
	
	for(int i=0; i<n; i++) {
		sort(id, id+i, [](int u, int v) {
			return in[u]<in[v];
		});
		int u=id[i];
		for(int j=0; j<=S; j++) {
			int weight=min(j-w[u], s[u]);
			if(weight<0) continue;
//		for(int j=w[u]; j<=s[u]; j++) {
//			int weight=j-w[u];
			int I=0;
			for(int k=in[u]; k<out[u]; k++) {
				smax(mx[k+1], mx[k]);
				while(I<i && in[id[I]]<k) I++;
				while(I<i && in[id[I]]==k) {
					if(out[id[I]]<=out[u]) {
						smax(mx[out[id[I]]], mx[k]+dp[id[I]][weight]);
					}
					I++;
				}
			}
			int Max=0;
			for(int k=in[u]; k<=out[u]; k++) {
				smax(Max, mx[k]);
				mx[k]=0;
			}
			smax(dp[u][j], Max+v[u]);
		}
		for(int j=1; j<=S; j++) smax(dp[u][j], dp[u][j-1]);
	}
	int ans=0;
	for(int i=0; i<n; i++) smax(ans, dp[i][S]);
	printf("%d", ans);
}