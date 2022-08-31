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

const int MX = 1005, INF = 1000000005, mod = 1000000009;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-9;
const int dx[4] = {-1,0,1,0}, dy[4] = {0,-1,0,1}; //<^>v

int n, m;
int a[MX][MX];
int d[MX], di;
bool b[MX][MX];

bool f(int x){
	rep(i,m)rep(j,i) b[i][j] = false;
	rep(i,n){
		di = 0;
		rep(j,m){
			if(a[i][j] < x) continue;
			rep(k,di) if(b[j][d[k]]) return true; else b[j][d[k]] = true;
			d[di++] = j;
		}
	}
	return false;
}

int main(){
	scanf("%d%d",&n,&m);
	
	rep(i,n)rep(j,m) scanf("%d",&a[i][j]);
	
	int l = 0, r = INF, c;
	while(l+1<r){
		c = (l+r)/2;
		if(f(c)) l = c; else r = c;
	}
	
	printf("%d\n",l);
	
	return 0;
}