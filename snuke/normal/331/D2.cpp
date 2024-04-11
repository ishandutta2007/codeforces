#include<cstdio>
#include<algorithm>
#include<iostream>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < n; i++)
#define rrep(i,n) for(int i = 1; i <= n; i++)
#define drep(i,n) for(int i = n-1; i >= 0; i--)
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;

const int MX = 1002, MV = MX*MX*4, n2 = 24, INF = 1000000000, mod = 1000000009;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-9;
const int dx[4] = {-1,0,1,0}, dy[4] = {0,-1,0,1}; //<v>^
int ci[256];

int n, m;
int to[n2][MV];
int d[MV];
int used[MV];

int tov(int x, int y, int vec){ return x*m*4+y*4+vec;}

int dfs(int v, int cnt){
	if(used[v]) return cnt-used[v];
	used[v] = cnt;
	return d[v] = dfs(to[0][v],cnt+1);
}

int main(){
	ci['L'] = 0;
	ci['R'] = 2;
	ci['U'] = 3;
	ci['D'] = 1;
	int ni, nj, v, u, x, x2, y, y2; ll t2; int t, z;
	scanf("%d%d",&n,&m);
	m++;
	
	int vs = m*m*4;
	
	rep(i,m)rep(j,m)rep(k,4){
		ni = i+dx[k]; nj = j+dy[k];
		v = tov(i,j,k);//printf("%d : %d %d %d %d %d\n",v,ni,nj,i,j,k);
		if(ni<0||nj<0||ni>=m||nj>=m){
			to[0][v] = v;
		} else {
			to[0][v] = tov(ni,nj,k);
		}
	}
	
	int av, dz;
	
	rep(i,n){
		scanf("%d%d%d%d",&x,&y,&x2,&y2);
		if(x == x2){
			if(y<y2){
				av = 3;
				dz = 1;
			} else {
				av = 1;
				dz = -1;
			}
			for(; y-dz != y2; y+=dz){
				v = tov(x,y,av);
				rep(k,4){
					u = tov(x,y,k);
					to[0][u] = to[0][v];
				}
			}
		} else {
			if(x<x2){
				av = 2;
				dz = 1;
			} else {
				av = 0;
				dz = -1;
			}
			for(; x-dz != x2; x+=dz){
				v = tov(x,y,av);
				rep(k,4){
					u = tov(x,y,k);
					to[0][u] = to[0][v];
				}
			}
		}
	}
	
	rep(i,vs) dfs(i,1);
	
	rrep(i,n2-1)rep(j,vs) to[i][j] = to[i-1][to[i-1][j]];
	
	//rep(i,vs) printf("%d : %d\n",i,to[0][i]);
	
	scanf("%d",&n);
	char c;
	
	rep(ni,n){
		scanf("%d%d %c%I64d",&x,&y,&c,&t2);
		av = ci[c];
		v = tov(x,y,av);
		t = min(3000000ll,t2);
		z = 1<<(n2-1);
		drep(i,n2){
			if(t&z) v = to[i][v];
			z >>= 1;
		}
		t2 -= t;
		//printf("%d %d\n",t,v);
		if(t2) t = t2%d[v]; else t = 0;
		//printf("%d %d %d\n",t,v,d[v]);
		z = 1<<(n2-1);
		drep(i,n2){
			if(t&z) v = to[i][v];
			z >>= 1;
		}

		v /= 4;
		printf("%d %d\n",v/m,v%m);
	}
	
	
	return 0;
}