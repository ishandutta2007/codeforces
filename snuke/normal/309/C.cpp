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

const int MX = 1000005, INF = 1000000000, mod = 1000000009;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-9;
const int dx[4] = {-1,0,1,0}, dy[4] = {0,-1,0,1}; //<^>v

int b[35], c[35];

int main(){
	int n, m, a, x, ans = 0;
	scanf("%d%d",&n,&m);
	
	rep(i,n){
		scanf("%d",&a);
		rep(i,32){
			if(a==0) break;
			c[i] += (a&1);
			a >>= 1;
		}
	}
	
	rep(i,m){ scanf("%d",&a); b[a]++;}
	
	rep(i,32){
		if(b[i] == 0) continue;
		ans += min(b[i],c[i]);
		b[i] -= c[i]; c[i] = 0;
		if(b[i] > 0){
			while(b[i]){
				x = i;
				while(x < 32 && c[x] <= 0) x++;
				if(c[x] <= 0) break;
				c[x]--;
				for(int j = x-1; j >= i; j--) c[j]++;
				b[i]--; ans++;
			}
		}
	}
	
	printf("%d\n",ans);
	
	return 0;
}