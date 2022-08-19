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

const int MX = 100005, INF = 10000000, mod = 1000000009;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-9;
const int dx[4] = {-1,0,1,0}, dy[4] = {0,-1,0,1}; //<^>v

char ss[MX];
string s;
bool b[11];

int main(){
	ll ans = 1;
	int n, x = 9, zs = 0;
	scanf("%s",ss);
	s = ss;
	n = s.size();
	
	rep(i,n){
		if(s[i] >= '0' && s[i] <= '9'){
		} else if(s[i] >= 'A' && s[i] <= 'J'){
			if(!b[s[i]-'A']){
				ans *= x;
				x--;
				b[s[i]-'A'] = true;
			}
		} else {
			if(i == 0) ans *= 9; else zs++;
		}
		if(i == 0) x++;
	}
	//if(n == 1) ans = 10;
	
	cout << ans;
	rep(i,zs) printf("0");
	puts("");
	
	return 0;
}