#include<cstdio>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
#include<string>
#include<string.h>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<map>
#include<set>
#include<complex>
#include<bitset>
#include<iostream>
#include<sstream>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < n; i++)
#define rrep(i,n) for(int i = 1; i <= n; i++)
#define drep(i,n) for(int i = n-1; i >= 0; i--)
#define each(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define rng(a) a.begin(),a.end()
#define maxs(x,y) x = max(x,y);
#define mins(x,y) x = min(x,y);
#define adds(x,y) x = (x+(y))%mod;
#define muls(x,y) x = (x*(y))%mod;
#define pb push_back
#define snuke srand((unsigned)clock()+(unsigned)time(NULL))
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef complex<double> cd;

const int N = 1<<21, INF = 1000000000, mod = 1000000007;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-9;
const double pi = acos(-1);
const int dx[4] = {-1,0,1,0}, dy[4] = {0,-1,0,1}; //<^>v

int b[N], ans[N>>1], ansi;
vector<cd> a(N), e(N);
cd x, y;

void fft(vector<cd>& d, cd w, int z=0, int r=1){
	if(r == N) return;
	fft(d,w*w,z,r<<1);
	fft(d,w*w,z+r,r<<1);
	cd v = cd(1,0);
	for(int i = z; i < N; i+=r) e[i] = d[i];
	for(int i = 0; i < N; i+=r, v*=w){
		d[i+z] = e[i*2%N+z]+v*e[i*2%N+r+z];
	}
}

int main(){
	int n, m, p;
	scanf("%d%d",&n,&m);
	rep(i,N) a[i] = cd(0,0);
	x = cd(cos(2*pi/N),sin(2*pi/N));
	y = cd(cos(2*pi/N),-sin(2*pi/N));
	
	rep(i,n){ scanf("%d",&p); a[p] = cd(1,0); b[p] = 1;}
	
	fft(a,x);
	rep(i,N) a[i] = a[i]*a[i];
	fft(a,y);
	
	//rep(i,m+15) printf("%d ",(int)(real(a[i])+eps)); puts("");
	rrep(i,m) if(abs(real(a[i])/N) > 0.5 && b[i] == 0){ puts("NO"); return 0;}
	
	puts("YES");
	rrep(i,m) if(abs(real(a[i])/N) < 0.5 && b[i] == 1) ans[ansi++] = i;
	printf("%d\n",ansi);
	rep(i,ansi) printf("%d%c",ans[i],(i==ansi-1?'\n':' '));
	
	return 0;
}