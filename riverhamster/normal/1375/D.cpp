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

const int N = 1005;
int a[N];
vector<int> e[N];
int op[N * 2], oc = 0, n = 0;

int mex(){
	bool v[N];
	fill(v, v + n + 1, false);
	for(int i=0; i<n; i++)
		v[a[i]] = true;
	for(int i=0; i<=n; i++)
		if(!v[i]) return i;
	return n + 1;
}

int main(){
	// File("d");
	int T;
	gi(T);
	while(T--){
		gi(n);
		for(int i=0; i<n; i++) gi(a[i]);
		int m = mex();
		oc = 0;
		while(m != n){
			op[++oc] = m + 1;
			a[m] = m;
			m = mex();
		}
		static int p[N];
		int pc = 0;
		for(int i=0; i<n; i++){
			if(a[i] == i) continue;
			p[pc = 1] = i;
			while(a[p[pc]] != i){
				++pc;
				p[pc] = a[p[pc - 1]];
			}
			for(int i=1; i<=pc; i++) op[++oc] = p[i] + 1;
			op[++oc] = i + 1;
			for(int i=1; i<=pc; i++) a[p[i]] = p[i];
		}
		wi(oc); EL;
		for(int i=1; i<=oc; i++) wi(op[i]), SP;
		EL;
	}
	return 0;
}