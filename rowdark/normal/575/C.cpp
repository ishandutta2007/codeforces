#include <cmath>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <climits>
#include <cstring>
#include <vector>
#include <string>
#include <iostream>
#include <cassert>
#include <algorithm>
#include <ctime>
using namespace std;

#define foreach(e,x) for(__typeof((x).begin()) e=(x).begin(); e!=(x).end(); ++e)

inline int fastMax(int x, int y) { return (((y-x)>>(32-1))&(x^y))^y; }
inline int fastMin(int x, int y) { return (((y-x)>>(32-1))&(x^y))^x; }

const int maxn=20;const int oo=0x7fffffff;
int w[maxn][maxn],x[maxn],y[maxn],px[maxn],py[maxn],sy[maxn],slack[maxn];
int par[maxn];int n;int pa[maxn][2],pb[maxn][2],n0,m0,na,nb;char s[maxn][maxn];
void adjust(int v){	sy[v]=py[v]; if (px[sy[v]]!=-2) adjust(px[sy[v]]);}
bool find(int v){for (int i=0;i<n;i++)
	if (py[i]==-1){
		if (slack[i]>x[v]+y[i]-w[v][i]) slack[i]=x[v]+y[i]-w[v][i],	par[i]=v;
		if (x[v]+y[i]==w[v][i]){
			py[i]=v; if (sy[i]==-1){adjust(i);	return 1;}
			if (px[sy[i]]!=-1) continue;	px[sy[i]]=i;
			if (find(sy[i])) return 1;
		}}return 0;}

int km(int bar){int i,j,m,flag; for (i=0;i<n;i++) sy[i]=-1,y[i]=0;
	for (i=0;i<n;i++) {x[i]=0; for (j=0;j<n;j++) x[i]=fastMax(x[i],w[i][j]); bar -= x[i];}
	if (bar >= 0) {
		return 0;
	}
	for (i=0;i<n;i++){
		for (j=0;j<n;j++) px[j]=py[j]=-1,slack[j]=oo;
		px[i]=-2;	if (find(i)) continue; flag=false;
		for (;!flag;){ m=oo; 
			for (j=0;j<n;j++) if (py[j]==-1) m=fastMin(m,slack[j]);
			for (j=0;j<n;j++){ if (px[j]!=-1) {x[j]-=m; bar += m;}
				if (py[j]!=-1) {y[j]+=m; bar -= m;} else slack[j]-=m;}
			if (bar >= 0) {
				return 0;
			}
			for (j=0;j<n;j++){ if (py[j]==-1&&!slack[j]){
				py[j]=par[j];
				if (sy[j]==-1){	adjust(j);	flag=true;	break;}
				px[sy[j]]=j;	 if (find(sy[j])){flag=true;break;}
			}}}}
	int ans=0; for (i=0;i<n;i++) ans+=w[sy[i]][i];return ans;}

int a[maxn][maxn], b[maxn][maxn];

const int N = 20;
void solve()
{
	//n = 20;
	cin >> n;
	for(int i = 0; i < n; ++ i) {
		for(int j = 0; j < n; ++ j) {
			scanf("%d", &a[i][j]);
			//cin >> a[i][j];
			//a[i][j] = rand() % 1000000;
		}
	}
	for(int i = 0; i < n; ++ i) {
		for(int j = 0; j < n; ++ j) {
			scanf("%d", &b[i][j]);
			//cin >> b[i][j];
			//a[i][j] = rand() % 1000000;
		}
	}
	int ret = 0;
	int pl[N], pr[N];
	for (int i = 0; i < n; ++i) {
		pl[i] = i, pr[i] = i;
	}
	random_shuffle(pl, pl + n);
	random_shuffle(pr, pr + n);
	vector<int> st;
	for(int s = 0; s < (1 << n); ++ s) {
		if ((__builtin_popcount(s) << 1) == n) {
			st.push_back(s);
		}
	}
	random_shuffle(st.begin(), st.end());
	for (int _ = 0; _ < (int)st.size(); ++_) {
			int s = st[_];
			for(int i = 0; i < n; ++ i) {
				for(int j = 0; j < n; ++ j) {
					w[pl[i]][pr[j]] = s >> i & 1 ? a[i][j] : b[i][j];
				}
			}
			ret = fastMax(ret, km(ret));
			if (clock() >= 1.8 * CLOCKS_PER_SEC) break;
	}
	cout << ret << endl;
}

int main()
{
	solve();
	return 0;
}