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

typedef double DO;
#define NN 410
int n, d[NN][NN];
VI vec[NN][NN];
DO p[NN], mmx[NN];

DO calc(int f){
	DO ans=0;
	for(int l=0; l<n; l++) if(!vec[f][l].empty()){
		if(vec[f][l].size()==1){
			ans+=1.0/n;
			continue;
		}
		for(int i=1; i<=n; i++) p[i]=0;
		VI nxt;
		for(int v : vec[f][l]){
			DO x=1.0/n/vec[v][1].size();
			for(int w : vec[v][1]){
				if(p[w]<1e-9) nxt.pb(w);
				p[w]+=x;
			}
		}
		DO mx=1.0/n;
		for(int i=1; i<=n; i++){
			DO s=0;
			for(int w : nxt) smax(mmx[d[i][w]], p[w]);
			for(int w : nxt) s+=mmx[d[i][w]], mmx[d[i][w]]=0;
			smax(mx, s);
		}
		ans+=mx;
	}
	return ans;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	
	int m;
	cin >> n >> m;
	for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) d[i][j]=(i!=j)*n;
	
	for(int i=0, u, v; i<m; i++){
		gn(u, v);
		d[u][v]=d[v][u]=1;
	}
	for(int k=1; k<=n; k++) for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) smin(d[i][j], d[i][k]+d[k][j]);
	for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) vec[i][d[i][j]].pb(j);
	
	DO ans=0;
	for(int i=1; i<=n; i++) smax(ans, calc(i));
	
	printf("%.12lf\n", ans);
	
	return 0;
}