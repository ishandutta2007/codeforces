#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define File(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)
typedef long long ll;
template<typename T> inline void in(T &x){ //Read Positive Integer.
	char ch; x = 0;
	// int f = 1;
	while(isspace(ch = getchar()));
	// if(ch == '-') ch = getchar(), f = -1;
	do x = x * 10 + ch - '0'; while(isdigit(ch = getchar()));
	// x *= f;
}

const int N = 5005;
int p[N], c[N], k[N], res[N];
vector<int> G[N];
int mtx[N], mty[N], dfn[N], Time;
bool left[N];

bool dfs(int x){
	for(int v : G[x]){
		if(v == mtx[x] || dfn[v] == Time) continue;
		if(!mty[v]){
			mtx[x] = v; mty[v] = x;
			return true;
		}
		dfn[v] = Time;
		if(dfs(mty[v])){
			mtx[x] = v; mty[v] = x;
			return true;
		}
	}
	return false;
}

int main(){
	// File("cf1139e");
	int n, m, d;
	in(n); in(m);
	for(int i=1; i<=n; i++) in(p[i]), ++p[i];
	for(int i=1; i<=n; i++) in(c[i]);
	in(d);
	for(int i=1; i<=d; i++) in(k[i]), left[k[i]] = true;
	for(int i=1; i<=n; i++)
		if(!left[i]) G[p[i]].push_back(c[i]);
	int now = 1;
	for(int i=d; i>=1; i--){
		while(true){
			++Time;
			if(dfs(now)) ++now;
			else break;
		}
		res[i] = now - 1;
		G[p[k[i]]].push_back(c[k[i]]);
	}
	for(int i=1; i<=d; i++) printf("%d\n", res[i]);
	return 0;
}