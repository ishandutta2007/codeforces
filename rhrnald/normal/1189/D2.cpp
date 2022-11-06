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
typedef pair<int,int> pii;

const int INF = 0x3c3c3c3c;
const ll LINF = 1ll*INF*INF*2;

const int N = 1000001;
int n,m,x,y,z;
int cnt[N];
bool vst[N];
vector<int> v[N];
int e[1001][1001];

int dfs(int cur) {
	if(vst[cur]) return 0;
	vst[cur]=true;
	if(cnt[cur]==1) return cur;
	for(int e : v[cur]) {
		int t=dfs(e);
		if(t) return t;
	}
	return -1;
}
typedef pair<pii,int> ppi;
vector<ppi> E,ans;
void p(int x, int y, int d) {
	ans.push_back({{x,y},d});
}
int main(void){
	scanf("%d", &n);
	for(int i=1; i<n; i++) {scanf("%d%d%d", &x, &y, &z); v[x].push_back(y); v[y].push_back(x); cnt[x]++, cnt[y]++; E.push_back({{x,y}, z});}
	for(int i=1; i<=n; i++) if(cnt[i]==2) {printf("NO"); return 0;}
	printf("YES\n");
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) vst[j]=false;

		vst[i]=true;
		for(int nxt : v[i]) {
			e[i][nxt]=dfs(nxt);
		}
	}
	for(ppi edge : E) {
		int x=edge.first.first;
		int y=edge.first.second;
		int d=edge.second/2;
		if(cnt[y]==1) swap(x,y);
		if(cnt[x]==1) {
			if(cnt[y]==1) {
				p(x,y,d+d);
				continue;
			}
			vector<int> temp;
			for(int nxt : v[y]) {
				if(nxt==x) continue;
				temp.push_back(nxt);
				if(sz(temp)==2) break;
			}
			int a=e[y][temp[0]], b=e[y][temp[1]];
			p(x,a,d);
			p(x,b,d);
			p(a,b,-d);
			continue;
		}

		vector<int> temp;
		for(int nxt : v[y]) {
			if(nxt==x) continue;
			temp.push_back(nxt);
			if(sz(temp)==2) break;
		}
		int ya=e[y][temp[0]], yb=e[y][temp[1]];
		temp.clear();
		for(int nxt : v[x]) {
			if(nxt==y) continue;
			temp.push_back(nxt);
			if(sz(temp)==2) break;
		}
		int xa=e[x][temp[0]], xb=e[x][temp[1]];
		p(xa,ya,d);
		p(xb,yb,d);
		p(xa,xb,-d);
		p(ya,yb,-d);
	}
	cout << sz(ans) << endl;
	for(ppi e : ans) {
		printf("%d %d %d\n", e.first.first, e.first.second, e.second);
	}
}