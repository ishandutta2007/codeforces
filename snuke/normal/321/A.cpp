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
#define snuke srand((unsigned)time(NULL))
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;

const int MX = 100005, INF = 1000000000, mod = 1000000009;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-9;
const int dx[4] = {-1,0,1,0}, dy[4] = {0,-1,0,1}; //<^>v

int ci[256];

int main(){
	ci['U'] = 3;
	ci['D'] = 1;
	ci['L'] = 0;
	ci['R'] = 2;
	int n, x, y, a, b;
	string s;
	
	cin >> a >> b >> s;
	if(a == 0 && b == 0){ puts("Yes"); return 0;}
	n = s.size();
	
	x = y = 0;
	rep(i,n){
		x += dx[ci[s[i]]];
		y += dy[ci[s[i]]];
		if(a == x && b == y){ puts("Yes"); return 0;}
	}
	if(x == 0 && y == 0){ puts("No"); return 0;}
	
	int t = 0;
	if(x>0) t = max(t,(a-200)/x);
	if(x<0) t = max(t,(a+200)/x);
	if(y>0) t = max(t,(b-200)/y);
	if(y<0) t = max(t,(b+200)/y);
	
	//cout << t << " " << x << " " << y << endl;
	
	x *= t;
	y *= t;
	
	rep(j,10000){
		rep(i,n){
			x += dx[ci[s[i]]];
			y += dy[ci[s[i]]];
			if(a == x && b == y){ puts("Yes"); return 0;}
		}
	}
	
	puts("No");
	
	return 0;
}