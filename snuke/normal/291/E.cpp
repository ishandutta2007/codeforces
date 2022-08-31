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

const int MX = 100005, INF = 1000000000, mod = 1000000009;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-9;
const int dx[4] = {-1,0,1,0}, dy[4] = {0,-1,0,1}; //<^>v

char in[MX*3];
int n, m;
vector<int> ch[MX];
vector<string> s[MX];
string t; int l[MX*3];

int dfs(int v, int p){
	int res = 0, a; string u;
	rep(i,ch[v].size()){
		a = p; u = s[v][i];
		rep(j,u.size()){
			while(a != -1 && u[j] != t[a]) a = l[a];
			if(a == -1) a = 0; else a++;
			if(a == m) res++;
		}
		res += dfs(ch[v][i],a);
	}
	return res;
}

int main(){
	int a;
	scanf("%d",&n);
	
	rrep(i,n-1){
		scanf("%d%s",&a,in);
		t = in; a--;
		ch[a].pb(i); s[a].pb(t);
	}
	
	scanf("%s",in); t = in; m = t.size(); t+='*';
	l[0] = -1; l[1] = 0;
	for(int i=2,j=0; i<=m;){
		if(t[i-1]==t[j]) l[i++] = ++j;
		else if(j == 0) l[i++] = 0;
		else j = l[j];
	}
	
	printf("%d\n",dfs(0,0));
	
	return 0;
}