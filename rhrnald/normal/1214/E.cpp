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
int n,m,x;
vector<pii> v;

int ans[N];
int main(void){
	scanf("%d", &n);
	for(int i=1; i<=n; i++) {
		scanf("%d", &x);
		v.push_back({x, i});
	}
	sort(all(v), greater<pii>());
	for(int i=0; i<n; i++) ans[i]=v[i].second+v[i].second-1;
	for(int i=0; i<n-1; i++) printf("%d %d\n", ans[i], ans[i+1]);
	for(int i=0; i<n; i++) {
		int idx=i+v[i].first;
		int cur=v[i].second+v[i].second;
		if(!ans[idx]) ans[idx]=cur;
		printf("%d %d\n", ans[idx-1], cur);
	}
}