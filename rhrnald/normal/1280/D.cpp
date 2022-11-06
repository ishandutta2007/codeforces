#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <complex>

#define sz(v) ((int)((v).size()))
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef pair<int,ll> pii;

const int INF = 0x3c3c3c3c;
const ll LINF = 1ll*INF*INF*2;

const int N = 5001;
int n,m,a,b;
int x[N], y[N];

vector<int> v[N];
vector<int> dfn;
pii ans[N][N];
int s[N];
pii nans[N];

int dfs(int prv, int cur) {
	dfn.push_back(cur);
	for(int i=0; i<sz(v[cur]); i++) if(v[cur][i]==prv) {v[cur].erase(v[cur].begin()+i); break;}
	s[cur]=1;
	for(int nxt : v[cur]) {
		s[cur]+=dfs(cur,nxt);
	}
	return s[cur];
}
void clear() {
	for(int i=1; i<=n; i++) v[i].clear();
	dfn.clear();
}
inline void mm(pii &x, pii y) {
	x=min(x,y);
}
void proc() {
	scanf("%d%d", &n, &m);
	for(int i=1; i<=n; i++) scanf("%d", x+i);
	for(int i=1; i<=n; i++) scanf("%d", y+i);
	for(int i=1; i<=n; i++) x[i]=x[i]-y[i];
	for(int i=1; i<n; i++) {
		scanf("%d%d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}

	dfs(0,1);
	reverse(all(dfn));
	for(int i : dfn) {
		for(int j=0; j<=n; j++) ans[i][j]={INF,INF};
		ans[i][0]={0,x[i]};

		int num=0;
		for(int nxt : v[i]) {
			for(int j=0; j<=s[nxt]+num; j++) nans[j]={INF,INF};
			for(int j=0; j<=s[nxt]; j++) {
				for(int k=0; k<=num; k++) {
					pii p1=ans[nxt][j];
					pii p2=ans[i][k];
					mm(nans[j+k], {p1.first+p2.first, p1.second+p2.second});
				}
			}
			num+=s[nxt];
			for(int j=0; j<=num; j++) ans[i][j]=nans[j];
		}
		num++;
		if(i==1) ans[i][m]={INF,INF};
		for(int j=num-1; j>=0; j--) mm(ans[i][j+1], {ans[i][j].first-(ans[i][j].second<0), 0});
	}
	printf("%d\n", -ans[1][m].first);
}
int main(void){
	int TC; scanf("%d", &TC);
	while(TC--) {
		proc();
		clear();
	}
}