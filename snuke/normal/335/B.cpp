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
#define snuke srand((unsigned)clock())
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;

const int MX = 50005, INF = 1000000000, mod = 1000000009;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-9;
const int dx[4] = {-1,0,1,0}, dy[4] = {0,-1,0,1}; //<^>v

int dp[MX], q[MX];
string ds[MX], ans;
vector<int> p[26];

int main(){
	int n, u, a;
	string s;
	cin >> s;
	n = s.size();
	
	rep(i,51) dp[i] = -1;
	dp[0] = n;
	rep(i,n){
		p[s[i]-'a'].pb(i);
		q[i] = p[s[i]-'a'].size()-1;
	}
	
	rep(i,n){
		drep(j,50){
			if(dp[j] == -1) continue;
			u = dp[j];
			vector<int>::iterator it = lower_bound(rng(p[s[i]-'a']),u);
			if(it == p[s[i]-'a'].begin()) continue;
			--it;
			if(dp[j+1] < (*it)){
				dp[j+1] = (*it);
				ds[j+1] = ds[j]+s[(*it)];
			}
		}
		
		string t, rt;
		rep(j,51){
			if(dp[j] >= i){
				t = ds[j];
				rt = t;
				reverse(rng(rt));
				if(dp[j] == i) t = t.substr(0,t.size()-1);
				t += rt;
				if(ans.size() < t.size()) ans = t;
			}
		}
	}
	
	cout << ans << endl;
	
	return 0;
}