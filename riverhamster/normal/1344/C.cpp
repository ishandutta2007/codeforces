// Codeforces contest template
#include <bits/stdc++.h>
using namespace std;
#define File(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define mkp make_pair
#define pb push_back
#define SP putchar(' ')
#define EL putchar('\n')

mt19937 rnd(chrono :: steady_clock :: now().time_since_epoch().count());
mt19937_64 rnd64(chrono :: steady_clock :: now().time_since_epoch().count()) ;

template<class T> inline void gi(T &x){
	char ch; x = 0;int f = 1;
	while(isspace(ch = getchar()));
	if(ch == '-') ch = getchar(), f = -1;
	do x = x * 10 + ch - '0'; while(isdigit(ch = getchar()));
	x *= f;
}
template<class T> inline void wi(T x){
	static char stk[128]; int top = 0;
	if(x == 0) putchar('0');
	if(x < 0) putchar('-'), x = -x;
	while(x) stk[++top] = x % 10, x /= 10;
	while(top) putchar(stk[top--] + '0');
}
template<class T> void upmax(T &x, T y){x = x>y ? x : y;}
template<class T> void upmin(T &x, T y){x = x<y ? x : y;}

const int N = 200005;

vector<int> gL[N], gG[N];
bool extL[N], extG[N], *ext;
vector<int> *G;
int ind[N];
int n, m;
char res[N];

bool topologicalSort(){
	queue<int> q;
	for(int i=1; i<=n; i++)
		if(!ind[i]) q.push(i);
	int cnt = 0;
	while(!q.empty()){
		int x = q.front(); q.pop();
		++cnt;
		for(int v : gL[x]){
			--ind[v];
			if(!ind[v]) q.push(v);
		}
	}
	return cnt == n;
}

void extend(int x){
	ext[x] = true;
	for(int v : G[x])
		if(!ext[v]) extend(v);
}

int main(){
	// File("c");
	gi(n); gi(m);
	for(int i=1; i<=m; i++){
		int u, v; gi(u); gi(v);
		++ind[v];
		gL[u].pb(v); gG[v].pb(u);
	}

	if(!topologicalSort()){
		puts("-1");
		return 0;
	}

	int cnt = 0;
	for(int i=1; i<=n; i++){
		if(extL[i] || extG[i]){
			res[i] = 'E';
			if(!extL[i]){
				G = gL; ext = extL; extend(i);
			}
			if(!extG[i]){
				G = gG; ext = extG; extend(i);
			}
		}
		else{
			res[i] = 'A'; ++cnt;
			G = gL; ext = extL; extend(i);
			G = gG; ext = extG; extend(i);
		}
	}
	printf("%d\n%s\n", cnt, res + 1);
	return 0;
}