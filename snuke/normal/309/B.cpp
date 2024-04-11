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

const int MX = 1000005, INF = 1000000000, x18 = 18, mod = 1000000009;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-9;
const int dx[4] = {-1,0,1,0}, dy[4] = {0,-1,0,1}; //<^>v

char in[MX*5];
string s[MX];
int l[MX], p[x18+1][MX], d[x18+1][MX];

int main(){
	int n, r, c, mx = 0, ans = 0;
	scanf("%d%d%d",&n,&r,&c);
	
	rep(i,n){
		scanf("%s",in);
		s[i] = in;
		l[i] = s[i].size()+1;
	}
	
	int a = 0, x = -1;
	
	rep(i,n){
		if(a < i){ x = -1; a = i;}
		while(a < n && x+l[a] <= c) x += l[a++];
		p[0][i] = a; d[0][i] = a-i;
		x -= l[i];
	}
	
	rep(i,x18){ p[i][n] = n; d[i][n] = 0;}
	rep(i,x18-1){
		rep(j,n){
			p[i+1][j] = p[i][p[i][j]];
			d[i+1][j] = d[i][j]+d[i][p[i][j]];
		}
	}
	
	//rep(i,n) printf("%d\n",p[0][i]);
	
	rep(i,n){
		a = r; x = 0; c = i;
		drep(j,x18){
			if(a&(1<<j)){
				x += d[j][c];
				c = p[j][c];
			}
		}
		if(x > mx){
			mx = x;
			ans = i;
		}
	}
	
	//printf("%d %d\n",mx,ans);
	c = ans;
	rep(i,r){
		a = p[0][c];
		if(a == c) break;
		for(int j = c; j < a; j++) printf("%s%c",s[j].c_str(),j==a-1?'\n':' ');
		c = a;
	}
	
	return 0;
}