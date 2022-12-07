#include <bits/stdc++.h>
#define MOD 1000000007
#define pb push_back
#define x first
#define y second
#define bctz(x) (__builtin_ctz(x))
using namespace std;
typedef long long INT;
typedef vector<int> VI;
typedef pair<int, int> pii;
typedef pair<pii, int> pi3;template<typename T> inline void gn(T &x) {char c, sg=0; while (c=getchar(), (c>'9' || c<'0') && c!='-');for((c=='-'?sg=1, c=getchar():0), x=0; c>='0' && c<='9'; c=getchar()) x=(x<<1)+(x<<3)+c-'0';if (sg) x=-x;}
template<class T, class T1>inline void gn(T &x, T1 &y) {gn(x); gn(y);}
template<class T, class T1, class T2>inline void gn(T &x, T1 &y, T2 &z) {gn(x); gn(y); gn(z);}
template<typename T> inline void print(T x) {if (x<0) {putchar('-');return print(-x);}if (x<10) {putchar('0'+x);return;} print(x/10);putchar(x%10+'0');}
template<typename T> inline void println(T x) {print(x), putchar('\n');}
template<typename T> inline void printsp(T x) {print(x), putchar(' ');}
#define NN 25
int adj[NN];
int ss[1<<24];
int val[1<<22], flag[1<<22];
pii pre[1<<22];
VI ans;
int main() {
    #ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    #endif
	int n, m, u, v;
	gn(n, m);
	for(int i=0; i<m; i++){
		gn(u, v);
		u--, v--;
		adj[u]|=1<<v;
		adj[v]|=1<<u;
	}
	memset(val, 0x3f, sizeof(int)*(1<<n));
	flag[0]=1;
	for(int i=1, c=1<<n; i<c; i++){
		if(flag[i-(i&-i)] && (adj[bctz(i)]&(i-(i&-i)))==(i-(i&-i))) flag[i]=1;
	}
	for(int i=1; i<16777215; i++)
    {
        ss[i] = i%5000;
    }
	for(int i=1, c=1<<n; i<c; i++){
		if(flag[i]) val[i]=0;
		for(int j=i; j; j-=j&-j){
			int k=bctz(j);
			if(val[i|adj[k]]>val[i]+1){
				val[i|adj[k]]=val[i]+1;
				pre[i|adj[k]]=pii(k, i);
			}
		}
	}
	for(int p=(1<<n)-1; !flag[p]; p=pre[p].y){
		ans.pb(pre[p].x);
	}
	println(ans.size());
	for(int i=ans.size(); i--; ) printsp(ans[i]+1);
	return 0;
}