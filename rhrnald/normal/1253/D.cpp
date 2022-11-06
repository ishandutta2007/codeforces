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
int x,y;

vector<int> v[N];
bool vst[N];
int lst=0;

void  dfs(int cur) {
	if(vst[cur]) return;
	vst[cur]=true;
	if(cur>lst) lst=cur;

	for(int nxt : v[cur]) dfs(nxt);
}
int main(void){
	scanf("%d%d", &n, &m);
	for(int i=0; i<m; i++) {
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	
	int ans=0;
	for(int i=1; i<=n; i++) {
		if(!vst[i] && i<lst) ans++;
		dfs(i);
	}
	cout << ans;
}