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
int n,m,k,x,y;
int a[N], b[N], c[N];
int lst[N];
vector<int> v[N];
multiset<int> S;
int main(void){
	scanf("%d%d%d", &n, &m, &k);
	for(int i=1; i<=n; i++) scanf("%d%d%d", a+i, b+i, c+i);
	for(int i=1; i<=n; i++) lst[i]=i;
	for(int i=0; i<m; i++) {
		scanf("%d%d", &x, &y);
		lst[x]=max(lst[x],y);
		lst[y]=max(lst[y],x);
	}
	for(int i=1; i<=n; i++) v[lst[i]].push_back(i);

	for(int i=1; i<=n; i++) {
		if(k<a[i]) {
			printf("-1");
			return 0;
		}
		while(k-sz(S)<a[i]) S.erase(S.begin());
		k+=b[i];
		for(int e : v[i]) S.insert(c[e]);	
	}
	while(sz(S)>k) S.erase(S.begin());

	int ans=0;
	for(int e : S) ans+=e;
	printf("%d", ans);
}