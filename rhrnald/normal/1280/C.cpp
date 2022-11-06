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
int n,m;

bool vst[N];
int siz[N];
ll sum[N];
vector<pii> v[N];
void make(int cur) {
	vst[cur]=true;
	siz[cur]=1;
	for(pii e: v[cur]) {
		int nxt=e.first;
		if(vst[nxt]) continue;
		make(nxt);
		siz[cur]+=siz[nxt];
	}
}
void mdfs(int cur) {
	vst[cur]=true;
	for(pii e : v[cur]) {
		int nxt=e.first;
		if(vst[nxt]) continue;
		mdfs(nxt);
		sum[cur]+=sum[nxt];
		if(siz[nxt]&1) sum[cur]+=e.second;
	}
}

int Mdfs(int cur, int d) {
	vst[cur]=true;
	for(pii e: v[cur]) {
		int nxt=e.first;
		if(vst[nxt]) continue;
		int val=min(d+siz[cur]-siz[nxt], siz[nxt]);
		Mdfs(nxt, val);
		sum[cur]+=sum[nxt]+1ll*val*e.second;
	}

}
void proc() {
	scanf("%d", &n);
	for(int i=1; i<=n+n; i++) v[i].clear();
	for(int i=1; i<n+n; i++) {
		int x,y,d;
		scanf("%d%d%d", &x, &y, &d);
		v[x].push_back({y,d});
		v[y].push_back({x,d});
	}
	for(int i=1; i<=n+n; i++) vst[i]=false, siz[i]=0;
	make(1);
	for(int i=1; i<=n+n; i++) vst[i]=false, sum[i]=0;
	mdfs(1);
	printf("%lld ", sum[1]);
	
	for(int i=1; i<=n+n; i++) vst[i]=false, sum[i]=0;
	Mdfs(1, 0);
	printf("%lld\n", sum[1]);
}

int main(void){
	int TC;
	scanf("%d", &TC); while(TC--) proc();
}