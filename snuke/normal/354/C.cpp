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
#define adds(x,y) x = (x+(y))%mod;
#define muls(x,y) x = (x*(y))%mod;
#define pb push_back
#define snuke srand((unsigned)clock()+(unsigned)time(NULL))
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;

const int MX = 1000005, INF = 1000000000, mod = 1000000007;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-9;
const int dx[4] = {-1,0,1,0}, dy[4] = {0,-1,0,1}; //<^>v

int x[MX];

int main(){
	int n, k, a, ans;
	scanf("%d%d",&n,&k);
	ans = k;
	
	rep(i,n){
		scanf("%d",&a);
		x[max(0,a-k)]++;
		x[min(MX-3,a+1)]--;
		ans = min(ans,a);
	}
	
	rep(i,MX-2) x[i+1] += x[i];
	
	for(int i = k+1; i < MX; i++){
		int c = 0;
		for(int j = i; j < MX; j+=i) c += x[j];
		if(c == n) ans = i;
	}
	
	cout << ans << endl;
	
	return 0;
}