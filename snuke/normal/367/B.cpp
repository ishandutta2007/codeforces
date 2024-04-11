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
#include<complex>
#include<map>
#include<set>
#include<bitset>
#include<iostream>
#include<sstream>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < n; i++)
#define rrep(i,n) for(int i = 1; i <= n; i++)
#define drep(i,n) for(int i = n-1; i >= 0; i--)
#define gep(i,g,j) for(int i = g.head[j]; i != -1; i = g.e[i].next)
#define each(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define rng(a) a.begin(),a.end()
#define maxs(x,y) x = max(x,y);
#define mins(x,y) x = min(x,y);
#define adds(x,y) x = (x+(y))%mod;
#define muls(x,y) x = (x*(y))%mod;
#define pb push_back
#define sz(x) (int)(x).size()
#define snuke srand((unsigned)clock()+(unsigned)time(NULL))
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;

const int MX = 200005, INF = 1000000000, mod = 1000000007;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;
const int dx[] = {-1,0,1,0}, dy[] = {0,-1,0,1}; //<^>v

int a[MX], b[MX], y[MX], yi, p;
int x[MX], xi;
int ans[MX], ansi;
int c[MX], cnt;

void f(int d, int e){
	int k = lower_bound(b,b+yi,d)-b;
	if(b[k] == d){
		if(c[k] == y[k]) cnt--;
		c[k] += e;
		if(c[k] == y[k]) cnt++;
	}
	//rep(i,yi) printf("%d : %d %d\n",b[i],y[i],c[i]);
}



int main(){
	int n,m,p, r;
	scanf("%d%d%d",&n,&m,&p);
	rep(i,n) scanf("%d",&a[i]);
	rep(i,m) scanf("%d",&b[i]);
	sort(b,b+m);
	int pre = -1; yi = -1;
	rep(i,m){
		if(pre != b[i]){
			b[++yi] = b[i];
			pre = b[i];
		}
		y[yi]++;
	}
	yi++; b[yi] = -1;
	
	//rep(i,yi) printf("%d %d\n",b[i],y[i]);
	
	rep(i,p){
		xi = 0;
		for(int j = i; j < n; j+=p) x[xi++] = a[j];
		if(xi < m) continue;
		//rep(j,xi) printf("%d ",x[j]); puts("");
		
		cnt = 0;
		rep(j,m-1) f(x[j],1);
		for(int j = m-1; j < xi; j++){
			f(x[j],1);
			if(cnt == yi) ans[ansi++] = p*(j-m+1)+i+1;
			f(x[j-m+1],-1);
		}
		rrep(j,m-1) f(x[xi-j],-1);
	}
	
	sort(ans,ans+ansi);
	printf("%d\n",ansi);
	rep(i,ansi) printf("%d%c",ans[i],i==ansi-1?'\n':' ');
	
	return 0;
}