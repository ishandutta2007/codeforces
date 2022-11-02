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

#define NN 100100
const int M=1<<20;
const int M_1=M-1;

int E, head[M], nxt[NN];
INT to[NN];

int add(int x, int y){
	INT val=123457LL*x+y;
	int u=val&M_1;
	E++;
	nxt[E]=head[u]; to[E]=val; head[u]=E;
}
bool find(int x, int y){
	INT val=123457LL*x+y;
	int u=val&M_1;
	for(int e=head[u]; e; e=nxt[e]) if(to[e]==val) return true;
	return false;
}

VI vx[NN], vy[NN];
int x[NN], y[NN];
int xpos[NN], ypos[NN];

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	
	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		gn(x[i], y[i]);
		add(x[i], y[i]);
		vx[x[i]].pb(i);
		vy[y[i]].pb(i);
	}
	
	for(int i=0; i<NN; i++){
		sort(vx[i].begin(), vx[i].end(), [](int a, int b){return y[a]<y[b];});
		for(int j=0; j<vx[i].size(); j++) xpos[vx[i][j]]=j;
		sort(vy[i].begin(), vy[i].end(), [](int a, int b){return x[a]<x[b];});
		for(int j=0; j<vy[i].size(); j++) ypos[vy[i][j]]=j;
	}
	
	int ans=0;
	for(int i=0; i<n; i++){
		if(xpos[i]<ypos[i]){
			for(int j=0; j<xpos[i]; j++){
				int d=y[i]-y[vx[x[i]][j]];
				if(find(x[i]-d, y[i]) && find(x[i]-d, y[i]-d) && find(x[i], y[i]-d)) ans++;
			}
		}
		else {
			for(int j=0; j<ypos[i]; j++){
				int d=x[i]-x[vy[y[i]][j]];
				if(find(x[i], y[i]-d) && find(x[i]-d, y[i]-d) && find(x[i]-d, y[i])) ans++;
			}
		}
	}
	
	cout << ans << endl;
	
	return 0;
}