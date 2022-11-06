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
int p[N], c[N],ans[N];
vector<int> v[N];

bool dfs(int cur, vector<int> &ret) {
	for(int nxt : v[cur]) {
		vector<int> temp;
		if(!dfs(nxt, temp)) return false;
		for(int e : temp) ret.push_back(e);
	}
	if(c[cur]>sz(ret)) return false;

	ret.insert(ret.begin()+c[cur], cur);
	return true;
}
int main(void){
	scanf("%d", &n);
	for(int i=1; i<=n; i++) scanf("%d%d", p+i, c+i);
	for(int i=1; i<=n; i++) v[p[i]].push_back(i);

	int r=v[0][0];
	vector<int> ret;
	if(!dfs(r,ret)) {
		printf("NO");
		return 0;
	}
	for(int i=0; i<n; i++) ans[ret[i]]=i+1;
	printf("YES\n");
	for(int i=1; i<=n; i++) printf("%d ", ans[i]);
}