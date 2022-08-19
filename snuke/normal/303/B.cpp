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

const int MX = 100005, INF = 1000000000, mod = 1000000009;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-9;
const int dx[4] = {-1,0,1,0}, dy[4] = {0,-1,0,1}; //<^>v

int gcd(int x, int y){
	if(y == 0) return x;
	return gcd(y,x%y);
}

int main(){
	int n, m, x, y, a, b, c, x1, y1;
	scanf("%d%d%d%d%d%d",&n,&m,&x,&y,&a,&b);
	
	c = gcd(a,b); a/=c; b/=c;
	
	c = 1;
	c = min(n/a,m/b);
	a *= c; b *= c;
	x1 = min(max(0,x-(a+1)/2),n-a);
	y1 = min(max(0,y-(b+1)/2),m-b);
	
	printf("%d %d %d %d\n",x1,y1,x1+a,y1+b);
	
	return 0;
}