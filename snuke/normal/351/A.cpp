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

const int MX = 100005, INF = 1000000000, mod = 1000000007;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-9;
const int dx[4] = {-1,0,1,0}, dy[4] = {0,-1,0,1}; //<^>v


int main(){
	int n;
	string s;
	cin >> n; n *= 2;
	int a = 0, b = 0, x = 0;
	rep(i,n){
		cin >> s;
		x = 0;
		for(int j = s.size()-3; j < s.size(); j++) x = x*10+(s[j]-'0');
		if(x) b++;
		a += x;
	}
	int r = min(b,n/2);
	int l = max(0,b-n/2);
	
	int d = a/1000;
	
	int ans = INF;
	if(l <= d && d <= r) ans = min(ans,abs(a-d*1000));
	if(l <= d+1 && d+1 <= r) ans = min(ans,abs(a-(d+1)*1000));
	ans = min(ans,abs(a-1000*r));
	ans = min(ans,abs(a-1000*l));
	
	printf("%d.%03d\n",ans/1000,ans%1000);
	
	return 0;
}