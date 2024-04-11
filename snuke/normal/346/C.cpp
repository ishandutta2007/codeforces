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
#define snuke srand((unsigned)clock()+(unsigned)time(NULL))
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;

const int MX = 100005, INF = 2000000000, mod = 1000000007;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-9;
const int dx[4] = {-1,0,1,0}, dy[4] = {0,-1,0,1}; //<^>v

int n, a, b;
int x[MX];
int d[MX*10];

int main(){
	cin >> n;
	rep(i,n) cin >> x[i];
	sort(x,x+n);
	n = unique(x,x+n)-x;
	cin >> a >> b;
	
	rep(i,MX*10) d[i] = i-1;
	rep(i,n) for(int j = (b+x[i]-1)/x[i]*x[i]; j <= a; j+=x[i]) mins(d[min(j+x[i]-b-1,a-b)],j-b);
	
	drep(i,a-b) mins(d[i],d[i+1]);
	
	int ans = 0; a -= b;
	while(a > 0){
		a = d[a];
		ans++;
	}
	
	cout << ans << endl;
	
	return 0;
}