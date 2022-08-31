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

const int MX = 45, INF = 1000000000, mod = 1000000007;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;
const int dx[] = {-1,0,1,0}, dy[] = {0,-1,0,1}; //<^>v

char cs[45];

int a[MX][MX];
int e[MX][MX][MX][MX];

int main(){
	int n, m, q;
	scanf("%d%d%d",&n,&m,&q);
	rep(i,n){
		scanf("%s",cs);
		rep(j,m) a[i][j] = cs[j]-'0';
	}
	
	for(int i1 = 0; i1 < n; i1++)for(int j1 = 0; j1 < m; j1++){
		for(int i = 0; i+i1 < n; i++)for(int j = 0; j+j1 < m; j++){
			int i2 = i1+i, j2 = j1+j;
			if(i==i2 && j==j2) e[i][j][i2][j2] = !a[i][j];
			else {
				if(i == i2){
					e[i][j][i2][j2] = (e[i][j][i2][j2-1]&e[i][j2][i2][j2]);
				} else {
					e[i][j][i2][j2] = (e[i][j][i2-1][j2]&e[i2][j][i2][j2]);
				}
			}
		}
	}
	
	
	for(int i1 = 0; i1 < n; i1++)for(int j1 = 0; j1 < m; j1++){
		for(int i = 0; i+i1 < n; i++)for(int j = 0; j+j1 < m; j++){
			int i2 = i1+i, j2 = j1+j;
			if(i==i2 && j==j2) continue;
			int x = 0;
			if(i==i2){
				x += e[i][j][i][j2-1];
				x += e[i][j+1][i][j2];
				x -= e[i][j+1][i][j2-1];
			} else if(j==j2){
				x += e[i][j][i2-1][j];
				x += e[i+1][j][i2][j];
				x -= e[i+1][j][i2-1][j];
			} else {
				x += e[i][j][i2][j2-1];
				x += e[i][j+1][i2][j2];
				x += e[i][j][i2-1][j2];
				x += e[i+1][j][i2][j2];
				
				x -= e[i+1][j][i2-1][j2];
				x -= e[i][j+1][i2][j2-1];
				x -= e[i+1][j+1][i2][j2];
				x -= e[i][j+1][i2-1][j2];
				x -= e[i+1][j][i2][j2-1];
				x -= e[i][j][i2-1][j2-1];
				
				x += e[i+1][j+1][i2-1][j2];
				x += e[i+1][j+1][i2][j2-1];
				x += e[i+1][j][i2-1][j2-1];
				x += e[i][j+1][i2-1][j2-1];
				
				x -= e[i+1][j+1][i2-1][j2-1];
			}
			e[i][j][i2][j2] += x;
		}
	}
	
	
	int a, b, c, d;
	rep(i,q){
		scanf("%d%d%d%d",&a,&b,&c,&d);
		a--; b--; c--; d--;
		printf("%d\n",e[a][b][c][d]);
	}
	
	return 0;
}