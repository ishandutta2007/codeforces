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
ll x[N];
vector<int> v[300];

int dis[N];
bool vst[N];

queue<int> Q;
int f(int a) {
	int ret=INF;
	for(int nxt : v[a]) {
		for(int i=0; i<n; i++) vst[i]=false, dis[i]=INF;
		
		dis[nxt]=1;
		Q.push(nxt);
		while(!Q.empty()) {
			int cur = Q.front(); Q.pop();
			vst[cur]=true;
			for(int e : v[cur]) if(e!=a && dis[e]>dis[cur]+1) {dis[e]=dis[cur]+1; Q.push(e);}
		}
		for(int i : v[a]) if(nxt!=i) ret=min(ret, dis[i]+1);
	}
	return ret;
}
int main(void){
	scanf("%d", &n);
	for(int i=0; i<n; i++) scanf("%lld", x+i);
	sort(x, x+n); reverse(x, x+n);
	while(!x[n-1]) n--;
	if(n>200) {printf("3"); return 0;}
	for(int i=0;i<n; i++)
		for(int j=i+1; j<n; j++) {
			if(x[i]&x[j]) v[i].push_back(j), v[j].push_back(i);
		}
	
	int ans=INF;
	for(int i=0; i<n; i++) ans=min(ans, f(i));
	if(ans==INF) printf("-1");
	else printf("%d", ans);
}