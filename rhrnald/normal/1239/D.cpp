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
int n,m,x,y;

vector<int> v[N];
vector<int> u[N];

int cnt;
bool vst[N];
void dfsv(int cur) {
	if(vst[cur]) return;
	vst[cur]=true; cnt++;
	for(int e: v[cur]) dfsv(e);
}
void dfsu(int cur) {
	if(vst[cur]) return;
	vst[cur]=true; cnt++;
	for(int e: u[cur]) dfsu(e);
}
void proc() {
	scanf("%d%d", &n, &m);
	for(int i=1; i<=n; i++) v[i].clear(), u[i].clear();
	for(int i=0; i<m; i++) {
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
		u[y].push_back(x);
	}
	cnt=0;
	for(int i=1; i<=n; i++) vst[i]=0;
	dfsv(1);
	if(cnt<n) {
		printf("Yes\n");
		printf("%d %d\n", cnt, n-cnt);
		for(int i=1; i<=n; i++) if(vst[i]) printf("%d ", i); printf("\n");
		for(int i=1; i<=n; i++) if(!vst[i]) printf("%d ", i); printf("\n");
		return;
	}
	cnt=0;
	for(int i=1; i<=n; i++) vst[i]=0;
	dfsu(1);
	if(cnt<n) {
		printf("Yes\n");
		printf("%d %d\n", n-cnt, cnt);
		for(int i=1; i<=n; i++) if(!vst[i]) printf("%d ", i); printf("\n");
		for(int i=1; i<=n; i++) if(vst[i]) printf("%d ", i); printf("\n");
		return;
	}
	printf("No\n");
}
int main(void){
	int tc; scanf("%d", &tc);
	while(tc--) proc();
}