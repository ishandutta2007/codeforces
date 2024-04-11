#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
const int N = 100005;
typedef long long ll;
template<typename T> inline void in(T &x){ //Read Positive Integer.
	register char ch; x = 0;
	while(isspace(ch = getchar()));
	do x = x * 10 + ch - '0'; while(isdigit(ch = getchar()));
}
struct Ts{
	int t, x;
	bool type; int ed;
	Ts(){}
	Ts(int Time, int Value, int Type, int End): t(Time), x(Value), type(Type), ed(End){}
}a[N*2];
inline bool operator<(Ts a, Ts b){
	if(a.x == b.x) return a.ed > b.ed;
	return a.x > b.x;
}
inline bool Tscmp(Ts a, Ts b){
	if(a.t == b.t) return a.type > b.type;
	return a.t < b.t;
}
Ts mx[N];
ll f[2][N];
map<Ts, int> mp;

int main(){
	// freopen("cf1106e.in", "r", stdin);
	// freopen("cf1106e.out", "w", stdout);
	int n, m, k, l, r, d, x, tot = 0;
	in(n); in(m); in(k);
	for(int i=1; i<=k; i++){
		in(l); in(r); in(d); in(x);
		a[++tot] = Ts(l, x, 1, d);
		a[++tot] = Ts(r+1, x, 0, d);
	}
	sort(a+1, a+1+tot, Tscmp);
	a[tot+1].t = 0x7fffffff;
	memset(mx, -1, sizeof mx);
	for(int i=1; i<=tot; i++){
		if(a[i].type){
			if(mp.count(a[i]) == 0) mp.insert(make_pair(a[i], 1));//, printf("Inserted coin %d\n", a[i].x);
			else ++mp[a[i]];//, printf("Increase number coin %d\n", a[i].x);
		}
		else{
			if(mp[a[i]] == 1) mp.erase(a[i]);//, printf("Remove coin %d\n", a[i].x);
			else --mp[a[i]];//, printf("Decrease number coin %d\n", a[i].x);
		}
		if(a[i].t != a[i+1].t){
			if(!mp.empty()) mx[a[i].t] = mp.begin()->first;
			else mx[a[i].t] = Ts(a[i].t, 0, 0, a[i].t);
			// printf("set mx %d: coin %d\n", a[i].t, mx[a[i].t].x);
		}
	}
	mx[0] = Ts(0, 0, 0, 1);
	for(int i=1; i<=n; i++){
		if(mx[i].x == -1){
			if(mx[i-1].x == 0) mx[i] = Ts(i, 0, 0, i);
			else mx[i] = mx[i-1];//, printf("Set mx[%d] = mx[%d]\n", i, i-1);
		}
	}
	ll ans = 0x7fffffffffffffffLL;
	memset(f[0], 0x3f, sizeof f[0]);
	int now, nxt;
	f[0][1] = 0;
	for(int i=0; i<=m; ++i){
		now = i & 1; nxt = (i & 1) ^ 1;
		memset(f[nxt], 0x3f, sizeof f[0]);
		for(int j=1; j<=n; ++j){
			f[nxt][j+1] = min(f[nxt][j+1], f[now][j]);
			// printf("mx[%d].ed = %d\n", j, mx[j].ed); fflush(stdout);
			f[now][mx[j].ed + 1] = min(f[now][mx[j].ed + 1], f[now][j] + mx[j].x);
			// printf("f[%d][%d] = %lld\n", now, j, f[now][j]);
		}
		ans = min(ans, f[now][n+1]);
	}
	printf("%lld\n", ans);
	return 0;
}