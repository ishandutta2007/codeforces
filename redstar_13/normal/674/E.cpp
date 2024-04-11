#include<bits/stdc++.h>

#define x first
#define y second
#define pb push_back

using namespace std;

typedef long long INT;
typedef vector<int> VI;
typedef pair<int, int> pii;

template<typename T, typename U> inline void smin(T &a, const U &b) {if(a>b) a=b;}
template<typename T, typename U> inline void smax(T &a, const U &b) {if(a<b) a=b;}

template <class T> inline void gn(T &x) {char c, sg=0; while(c=getchar(), (c>'9' || c<'0') && c!='-'); for((c=='-' ? sg=1, c=getchar() : 0), x=0; c>='0' && c<='9'; c=getchar()) x=(x<<1)+(x<<3)+c-'0'; if(sg) x=-x;}
template <class T1, class T2> inline void gn(T1 &x1, T2 &x2) {gn(x1), gn(x2);}
int power(int a, int b, int m, int ans=1){for (; b; b>>=1, a=1LL*a*a%m) if (b&1) ans=1LL*ans*a%m; return ans;}

#define NN 500500
#define M 50
typedef double DO;
DO dp[NN][M];
int fa[NN];

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	
	int q;
	int n=1;
	for(int i=0; i<M; i++) dp[n][i]=1;
	
	cin >> q;
	int tp, u;
	while(q--){
		gn(tp, u);
		if(tp==1){
			int v=++n;
			fa[v]=u;
			for(int i=0; i<M; i++) dp[v][i]=1;
			VI vec;
			for(int i=0; i<M && u; i++) vec.pb(u), u=fa[u];
			for(int i=vec.size(); i--; ){
				if(i) dp[vec[i]][i]/=(dp[vec[i-1]][i-1]+1)/2;
				else dp[vec[i]][i]*=0.5;
			}
			for(int i=1; i<vec.size(); i++){
				dp[vec[i]][i]*=(dp[vec[i-1]][i-1]+1)/2;
			}
		}
		else {
			DO ans=0;
			for(int i=1; i<M; i++) ans+=i*(dp[u][i]-dp[u][i-1]);
			printf("%.10lf\n", ans);
		}
	}
	
	return 0;
}