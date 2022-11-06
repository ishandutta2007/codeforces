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
vector<pii> v[N];
bool vst[N];
vector<int> con;
vector<int> ind;
void proc() {
	scanf("%d%d", &n, &m);
	int n3=n+n+n;
	con.clear(); ind.clear();
	for(int i=1; i<=n3; i++) v[i].clear(), vst[i]=false;
	for(int i=1; i<=m; i++) {
		int x,y;
		scanf("%d%d", &x, &y);
		v[x].push_back({y,i});
		v[y].push_back({x,i});
	}
	for(int i=1; i<=n3; i++) {
		bool flag=false;
		if(vst[i]) continue;
		for(pii e : v[i]) {
			if(!vst[e.first]) {
				vst[e.first]=true;
				vst[i]=true;
				con.push_back(e.second);
				flag=true;
				break;
			}
		}
		if(!flag) ind.push_back(i);

		if(sz(con)>=n) {
			printf("Matching\n");
			for(int e : con) printf("%d ", e);
			printf("\n");
			break;
		}
		if(sz(ind)>=n) {
			printf("IndSet\n");
			for(int e : ind) printf("%d ", e);
			printf("\n");
			break;
		}
	}
}
int main(void){
	int TC; scanf("%d", &TC);
	while(TC--) {
		proc();
	}
}