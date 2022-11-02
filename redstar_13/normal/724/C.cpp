#include <bits/stdc++.h>

#define eps 1e-7
#define sq(x) ((x)*(x))
#define cub(x) ((x)*(x)*(x))
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3fLL
#define MOD 1000000007
#define rep(i, a, b) for (i=(a); i<(b); i++)
#define bpt(x) __builtin_popcount(x)
#define isset(x, y) ((x)&(1<<(y)))
#define pb push_back
#define beyond(u, v) (u<0 || v<0 || u>=N || v>=M)
#define x first
#define y second
#define eprint(...) fprintf(stderr, __VA_ARGS)

#define FILEIO(name) \
	freopen(name".in", "r", stdin); \
	freopen(name".out", "w", stdout);

using namespace std;
typedef long long INT;
typedef double DO;
typedef pair<int, int> pii;

template<typename T, typename U> inline void smin(T &a, U b) {if(a>b) a=b;}
template<typename T, typename U> inline void smax(T &a, U b) {if(a<b) a=b;}
#define NN 1111111
int N, M, K;

int dx[]={1, 1, -1, -1}, dy[]={1, -1, -1, 1};

int stop;
INT wei[NN][5];
int vst[NN][5];

int f(int u, int v) {
	if(v==0) return u;
	if(v==M-1) return N+u;
	if(u==0) return N*2+v;
	return N*2+M+v;
}

int calc_dst(int d, int u, int v) {
	if(d==0) u=N-1-u, v=M-1-v;
	else if(d==1) u=N-1-u, v=v;
	else if(d==2) u=u, v=v;
	else if(d==3) u=u, v=M-1-v;
	if(u==v) stop=0;
	else if(u<v) stop=1;
	else stop=2;
	return min(u, v);
}
int rev(int d) {
	if(stop==2) {
		if(d<2) return 1-d;
		return 5-d;
	}
	return 3-d;
}
void prepare() {
	int i, j, k, ux, uy, vx, vy, d;
	INT len;
	for(ux=uy=d=0, len=0LL; ;) {
		int id=f(ux, uy);
		if(vst[id][d]) return;
		vst[id][d]=1;
		wei[id][d]=len;
//		printf("%d %d %d %d\n", ux, uy, d, len);
		
		int dst=calc_dst(d, ux, uy);
		
		ux+=dx[d]*dst; uy+=dy[d]*dst;
		len+=(INT) dst;
		d=rev(d);
		if(stop==0) return;
	}
}

int main() {
	
	scanf("%d%d%d", &N, &M, &K);
	N++; M++;
	
	prepare();
	
	int i, u, v, j, jj, uu, vv;
	rep(i, 0, K) {
		scanf("%d%d", &u, &v);
		INT res=-1;
		rep(j, 0, 4) {
			int dst=calc_dst(j, u, v);
			uu=u+dx[j]*dst; vv=v+dy[j]*dst;
			if(j%2==0) jj=2-j;
			else jj=4-j;
			int id=f(uu, vv);
			if(vst[id][jj]) {
				INT len=(INT) dst+wei[id][jj];
				if(res==-1 || res>len) res=len;
			}
		}
		cout<<res<<endl;
	}
	
	return 0;
}