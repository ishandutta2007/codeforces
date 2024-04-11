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

int a[1005], b[1005], ai, bi;

int main(){
	int x = 0, y = 0;
	char c;
	
	while(1){
		scanf("%c",&c);
		if(c == '\n') break;
		a[ai++] = c-'0';
		x += a[ai-1];
	}
	while(1){
		scanf("%c",&c);
		if(c == '\n') break;
		b[bi++] = c-'0';
		y += b[bi-1];
	}
	
	if(x+(x%2?1:0) >= y){ puts("YES"); return 0;}
	
	puts("NO");
	return 0;
}