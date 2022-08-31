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
#define dels(x,y) x = (x-(y)+mod)%mod;
#define muls(x,y) x = ((ll)x*(y))%mod;
#define pb push_back
#define sz(x) (int)(x).size()
#define snuke srand((unsigned)clock()+(unsigned)time(NULL))
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;

const int MX = 100005, INF = 1000000000, mod = 1000000007;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;
const int dx[] = {-1,0,1,0}, dy[] = {0,-1,0,1}; //<^>v

int x[MX*2], xi;
ll y[MX], now; int t[MX], l[MX], yi;

int main(){
	int m, n, a, b;
	scanf("%d",&m);
	
	rep(i,m){
		scanf("%d",&a);
		if(a == 1){
			scanf("%d",&a);
			if(xi < MX){
				x[xi++] = a;
			} else {
				y[yi] = now;
				t[yi] = 1;
				l[yi++] = a;
			}
			now++;
		} else {
			scanf("%d%d",&a,&b);
			while(b && xi < MX){
				rep(j,a) x[xi++] = x[j];
				now = xi;
				b--;
			}
			if(b){
				y[yi] = now;
				t[yi] = 2;
				l[yi++] = a;
				now += a*b;
			}
		}
	}
	y[yi++] = LINF;
	
	scanf("%d",&n);
	ll aa;
	rep(i,n){
		scanf("%I64d",&aa);
		aa--;
		if(aa < xi){
			printf("%d",x[aa]);
		} else {
			b = upper_bound(y,y+yi,aa)-y-1;
			if(t[b] == 1) printf("%d",l[b]);
			else printf("%d",x[(aa-y[b])%l[b]]);
		}
		printf("%c",i==n-1?'\n':' ');
	}
	
	return 0;
}