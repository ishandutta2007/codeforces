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
#include<bitset>
#include<iostream>
#include<sstream>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < n; i++)
#define rrep(i,n) for(int i = 1; i <= n; i++)
#define drep(i,n) for(int i = n-1; i >= 0; i--)
#define each(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define rng(a) a.begin(),a.end()
#define maxs(x,y) x = max(x,y);
#define mins(x,y) x = min(x,y);
#define pb push_back
#define snuke srand((unsigned)time(NULL))
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;

const int MX = 66, INF = 1000000000, mod = 1000000009;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-9;
const int dx[4] = {-1,0,1,0}, dy[4] = {0,-1,0,1}; //<^>v

int f[MX][MX], g[MX][MX];

int main(){
	int n, t, x, y, ni, nj;
	scanf("%d%d",&n,&t);
	f[0][0] = n;
	
	bool ch = true;
	while(ch){
		ch = false;
		rep(i,MX)rep(j,i+1) g[i][j] = f[i][j]/4;
		rep(i,MX)rep(j,i+1){
			x = g[i][j];
			if(x){
				f[i][j] -= x*4;
				rep(v,4){
					ni = i+dx[v]; nj = j+dy[v];
					if(ni<0||nj<0||ni<nj) continue;
					y = 1;
					if((v==1||!ni)&&!nj) y <<= 1;
					if(ni==nj) y <<= 1;
					f[ni][nj] += x*y;
				}
				ch = true;
			}
		}
	}
	
	rep(i,t){
		scanf("%d%d",&x,&y);
		if(x<0) x = -x;
		if(y<0) y = -y;
		if(x<y) swap(x,y);
		if(x >= MX) puts("0"); else printf("%d\n",f[x][y]);
	}
	
	return 0;
}