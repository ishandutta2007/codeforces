#include<cstdio>
#include<algorithm>
#include<stack>
#include<queue>
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

int a[MX];
queue<int> q0, q1;

int main(){
	int n, l, t, c, x;
	ll sum = 0;
	scanf("%d%d%d",&n,&l,&t);
	
	if(n == 1){ puts("0"); return 0;}
	
	rep(i,n) scanf("%d",&a[i]);
	
	rep(k,2){
		c = ((ll)t*2-1+l)/l-1;
		for(int i = 1; i < n; i++) q1.push(i);
		
		rep(i,n){
			while(!q1.empty()){
				x = q1.front();
				if(((ll)t*2-(a[x]-a[i]+l)%l+l)/l == c) break;
				q1.pop(); q0.push(x);
			}
			sum += (ll)c*(n-1)+q0.size();
			if(q0.empty()) q1.pop(); else q0.pop();
			q1.push(i);
		}
		
		while(!q0.empty()) q0.pop();
		while(!q1.empty()) q1.pop();
		rep(i,n) a[i] = l-a[i]-1;
		reverse(a,a+n);
	}
	
	printf("%f\n",(double)sum/8);
	
	return 0;
}