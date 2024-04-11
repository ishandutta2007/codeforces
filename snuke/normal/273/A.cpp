#include<cstdio>
#include<algorithm>
#include<iostream>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < n; i++)
#define rrep(i,n) for(int i = 1; i <= n; i++)
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;

const int MX = 100005, n17 = 1<<17, INF = 100000000;

int x[MX];

int main(){
	int n, m, a, b, c; ll y = 0, ans;
	scanf("%d",&n);
	rep(i,n) scanf("%d",&x[i]);
	
	scanf("%d",&m);
	c = 0;
	rep(i,m){
		scanf("%d%d",&a,&b);
		if(a > c){
			c = a;
			ans = x[a-1];
		} else ans = 0;
		ans = max(ans,y);
		y = ans+b;
		cout << ans << endl;
	}
	
	return 0;
}