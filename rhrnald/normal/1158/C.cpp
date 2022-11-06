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
int x[N];
int ans[N];

void proc();
vector<pii> v;
void proc() {
	scanf("%d", &n);
	for(int i=1; i<=n; i++) {scanf("%d", x+i); if(x[i]==-1) x[i]=i+1;}
	x[n+1]=n+1;
	int cur=1;
	v.clear();
	for(int i=1; i<=n+1; i++) {
		while(!v.empty() && v.back().second<=i) {
			ans[v.back().first]=cur++;
			v.pop_back();
		}
		if(!v.empty() && v.back().second<x[i]) {printf("-1\n"); return;}
		v.push_back({i,x[i]});
	}
	for(int i=1; i<=n; i++) printf("%d ", ans[i]); printf("\n");
}
int main(void){
	int tc;scanf("%d", &tc);
	while(tc--) proc();
}