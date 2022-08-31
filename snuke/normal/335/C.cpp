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
#define each(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define rng(a) a.begin(),a.end()
#define maxs(x,y) x = max(x,y);
#define mins(x,y) x = min(x,y);
#define pb push_back
#define snuke srand((unsigned)clock())
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;

const int MX = 1005, INF = 1000000000, mod = 1000000009;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-9;
const int dx[4] = {-1,0,1,0}, dy[4] = {0,-1,0,1}; //<^>v

int x[MX], y[MX];

bool a[MX][2], z[MX];
int g[MX][3][3];

void sets(int w, int b, int p){
	rep(i,w+4){
		a[i][0] = a[i][1] = (i>1&&i<w+2)?false:true;
	}
	if(b == 1) a[1][0] = false;
	if(b == 2) a[1][1] = false;
	if(p == 1) a[w+2][0] = false;
	if(p == 2) a[w+2][1] = false;
}

int sum(int w){
	int res = 0, i = 1, f, t, s;
	while(i <= w+2){
		f = 3;
		if(!a[i][0]) f ^= 2;
		if(!a[i][1]) f ^= 1;
		i++;
		if(f == 3) continue;
		s = (f==0)?1:0;
		while(1){
			t = 0;
			if(!a[i][0]) t ^= 1;
			if(!a[i][1]) t ^= 2;
			i++;
			if(t != 3) break;
			s++;
		}
		//printf("%d %d %d %d\n",s,f,t,g[s][f][t]);
		res ^= g[s][f][t];
	}
	
	//printf("%d : %d\n",w,res);
	//rep(j,2){rep(i,w+4) printf("%d",a[i][j]); puts("");}
	
	return res;
}

void calc(int w, int b, int p){
	rep(i,MX) z[i] = true;
	rrep(i,w+2)rep(j,2){
		sets(w,b,p);
		if(a[i][j]) continue;
		//rep(j2,2){rep(i2,w+4) printf("%d",a[i2][j2]); puts("");}
		a[i][j] = a[i-1][j^1] = a[i][j^1] = a[i+1][j^1] = true;
		z[sum(w)] = false;
	}
	rep(i,MX) if(z[i]){
		g[w][b][p] = i;
		//printf("%d %d %d ; %d\n",w,b,p,i);
		return;
	}
}


int main(){
	int n, r;
	cin >> r >> n;
	rep(i,n){
		cin >> x[i] >> y[i];
		y[i]--;
	}
	
	rep(i,r+1){
		rep(j,3)rep(k,3) calc(i,j,k);
	}
	
	sets(r,0,0);
	rep(i,n){
		a[x[i]+1][y[i]] = a[x[i]][y[i]^1] = a[x[i]+1][y[i]^1] = a[x[i]+2][y[i]^1] = true;
	}
	
	puts(sum(r)?"WIN":"LOSE");
	
	return 0;
}