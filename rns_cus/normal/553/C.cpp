#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <string.h>
#include <set>
#include <queue>
#include <map>
#include <math.h>
#include <vector>
#include <ctype.h>
#include <string.h>
#include <string>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vii;
const int N = 100007;
const int mod = 1000000007;
#define all(it,a) for(typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

int n,m;
int a[N],b[N],c[N];
vii v[N];
void input() {
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++) {
		scanf("%d%d%d",a+i,b+i,c+i);
		v[a[i]].push_back(pii(b[i],c[i]));
		v[b[i]].push_back(pii(a[i],c[i]));
	}
}
int d[N];
bool dfs(int u,int x) {
	d[u]=x+1;
	all(it,v[u]) {
		if (!d[it->first]) {
			if (it->second) {if (dfs(it->first,x)) return 1;}
			else {if (dfs(it->first,1-x)) return 1;}
		} else {
			int y=d[it->first]-1;
			if (it->second && x!=y) return 1;
			if (!it->second && x==y) return 1;
		}
	}
	return 0;
}

void solve() {
	int A=0;
	int B=0;
	for (int i=1;i<=n;i++) if (!d[i]) {
		B+=dfs(i,0);
		if (B) break;
		A++;
	}
	//printf("%d %d\n",A,B);
	if (B) puts("0");
	else {
		ll ans=1;
		for (int i=1;i<=A-1;i++) ans=ans*2%mod;
		printf("%I64d\n",ans);
	}
}

int main() {
	//freopen("C.in", "r", stdin);
	input();
	solve();
	return 0;
}