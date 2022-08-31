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

const int MX = 100005, INF = 1000000000, mod = 1000000007;

string s;
ll b[105];

int main(){
	int n;
	cin >> s;
	n = s.size();
	b[n-1] = 1;
	drep(i,n-1) b[i] = (b[i+1]*2)%mod;
	ll a = 1, ans = 0;
	rep(i,n){
		if(s[i] == '1') ans += ((a*b[i])%mod)*b[i];
		ans %= mod;
		a = (a*2)%mod;
	}
	
	cout << ans << endl;
	return 0;
}