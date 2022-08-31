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

const int MX = 100005, INF = 1000000000, mod = 1000000000;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-9;
const int dx[4] = {-1,0,1,0}, dy[4] = {0,-1,0,1}; //<^>v

int x[MX];

int main(){
	int n, m, a, b, c, f, g; ll ans;
	scanf("%d%d",&n,&m);
	
	rep(i,n) scanf("%d",&x[i]);
	
	rep(i,m){
		scanf("%d",&a);
		if(a == 1){
			scanf("%d%d",&a,&b); a--;
			x[a] = b;
		} else if(a == 2){
			scanf("%d%d",&a,&b); a--; b--;
			f = g = 1; ans = 0;
			while(a<=b){
				ans += (ll)x[a]*f;
				ans %= mod;
				swap(f,g); g = (f+g)%mod;
				a++;
			}
			printf("%I64d\n",ans);
		}
	}
	
	return 0;
}