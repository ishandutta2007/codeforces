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
int a,b;
int x[N][3];
vector<int> v[N];
vector<int> e;
int idx[N];
int main(void){
	scanf("%d", &n);
	for(int j=0; j<3; j++)
		for(int i=1; i<=n; i++)
			scanf("%d", x[i]+j);

	for(int i=1; i<n; i++) {
		scanf("%d%d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for(int i=1; i<=n; i++) if(sz(v[i])>2) {printf("-1"); return 0;}

	int prv=-1;
	int s;
	for(int i=1; i<=n; i++) if(sz(v[i])==1) {s=i; break;}

	e.push_back(s);
	while(sz(e)<n) {
		for(int nxt : v[s]) if(nxt!=prv) {prv=s, s=nxt; break;}
		e.push_back(s);
	}
	
	int cur[3]={0,1,2};
	int c[3];
	ll ans=LINF;
	do {
		ll t=0;
		for(int i=0; i<n; i++) t+=x[e[i]][cur[i%3]];
		if(ans>t) {
			ans=t;
			c[0]=cur[0], c[1]=cur[1], c[2]=cur[2];
		}
	} while(next_permutation(cur, cur+3));

	for(int i=0; i<n; i++) {
		idx[e[i]]=c[i%3];
	}
	printf("%lld\n", ans);
	for(int i=1; i<=n; i++) printf("%d ", idx[i]+1);
}