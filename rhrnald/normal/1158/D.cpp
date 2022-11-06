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
int n;
pii x[N];
bool used[N];
string s;

bool cmp(int p, int a, int b, bool L) {
	if(p==a) return true;

	ll t=1ll*(x[a].first-x[p].first)*(x[b].second-x[p].second)-1ll*(x[a].second-x[p].second)*(x[b].first-x[p].first);
	if(L) return t<0;
	else return t>0;
}

int find(int idx, bool L) {
	int ret=idx;
	for(int i=1; i<=n; i++) {
		if(used[i]) continue;
		if(cmp(idx, ret, i, L)) ret=i;
	}
	printf("%d ", ret);
	used[ret]=true;
	return ret;
}

vector<int> ans;
int main(void){
	scanf("%d", &n);
	for(int i=1; i<=n; i++) scanf("%d%d", &x[i].first, &x[i].second);

	pii m={INF,INF};
	int idx=-1;
	for(int i=1; i<=n; i++) {
		if(m>x[i]) m=x[i], idx=i;
	}
	used[idx]=true; printf("%d ", idx);
	cin >> s;
	for(int i=0; i<n-1; i++) idx=find(idx, s[i]=='L');
}