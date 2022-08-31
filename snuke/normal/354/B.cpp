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

const int MX = 25, INF = 1000000000, mod = 1000000007;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-9;
const int dx[4] = {-1,0,1,0}, dy[4] = {0,-1,0,1}; //<^>v

int n, n2;

int dp[MX*2][1<<20];

char c[MX*3][MX];
bool ex[256];
char cs[MX], ci;
int fs[MX], ft[MX];

bool ch(int i, int j){
	int l = 0, r = n-1;
	if(i >= n) l = max(l,i-n+1);
	if(i < n) r = min(r,i);
	return (j>>r+1) || (j&(1<<l)-1);
}

int main(){
	cin >> n;
	n2 = 1<<n;
	
	string s;
	rep(i,n){
		cin >> s;
		rep(j,n){
			c[i+20][j] = s[j];
		}
	}
	
	dp[n*2-2][1<<n-1] = 0;
	
	char a;
	int nx;
	drep(i,n*2-2){
		for(int j = 'a'; j <= 'z'; j++) ex[j] = false;
		rep(j,n) if(i-j+1 >= 0 && i-j+1 < n) ex[c[20+i-j+1][j]] = true;
		ci = 0;
		for(int j = 'a'; j <= 'z'; j++) if(ex[j]) cs[ci++] = j;
		rep(k,ci){
			a = cs[k];
			fs[k] = 0; ft[k] = 0;
			rep(l,n){
				if(c[i-l+20+1][l] == a) fs[k] |= 1<<l;
				if(c[i-l+20][l+1] == a && l+1 < n) ft[k] |= 1<<l;
			}
		}
		
		rep(j,n2){
			if(ch(i,j)) continue;
			if(!(i&1)) dp[i][j] = INF;
			else dp[i][j] = -INF;
			rep(k,ci){
				a = cs[k];
				int f = (fs[k]&j)|(ft[k]&j)<<1;
				if(!f) continue;
				int d = 0;
				if(a == 'a') d++;
				if(a == 'b') d--;
				if(i&1){ maxs(dp[i][j],dp[i+1][f]+d);}
				else { mins(dp[i][j],dp[i+1][f]+d);}
			}
		}
	}
	
	if(c[20][0] == 'a') dp[0][1]++;
	if(c[20][0] == 'b') dp[0][1]--;
	
	if(dp[0][1] > 0){
		puts("FIRST");
	} else if(dp[0][1] < 0){
		puts("SECOND");
	} else puts("DRAW");
	
	return 0;
}