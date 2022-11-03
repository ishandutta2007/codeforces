/*----------------by syr----------------*/
/*
  -----  -----  -----
  |   |  |---|    _/
  |   |  | \_    /
  -----  |   \  -----

  |---\  \   /  |\  /|
  |   |   \_/   | \/ |
  |   |   / \   |    |
  |---/  /   \  |    |
*/
#include<algorithm>
#include<bitset>
#include<cctype>
#include<cstring>
#include<cstdlib>
#include<deque>
#include<fstream>
#include<functional>
#include<iomanip>
#include<iostream>
#include<iterator>
#include<limits>
#include<list>
#include<map>
#include<math.h>
#include<queue>
#include<set>
#include<stack>
#include<stdio.h>
#include<sstream>
#include<string>
#include<time.h>
#include<utility>
#include<vector>

#define PH push
#define MP make_pair
#define PB push_back
#define fst first
#define snd second
#define FOR(i,x,y) for(int i=(x);i<(y);++i)
#define REP(i,x,y) for(int i=(x);i<=(y);++i)
#define x0 x0123456789
#define y0 y0123456789
#define x1 x1234567890
#define y1 y1234567890
#define x2 x2345678901
#define y2 y2345678901

using namespace std;

typedef double db;
typedef long long ll;
typedef long double ldb;
typedef pair<int,int> pii;

const int INF=1e9+7;
const int maxn=1e5+5;

int n,m,a=-1,b=-1;
int ans[maxn];
vector<int> g[maxn];

int main(){
	scanf("%d%d",&n,&m);
	if(n==1){
		puts("NO");
		return 0;
	}
	FOR(i,0,m){
		int u,v;
		scanf("%d%d",&u,&v);
		--u;--v;
		g[u].PB(v);
		g[v].PB(u);
	}
	FOR(i,1,n){
		sort(g[i].begin(),g[i].end());
		if(!g[i].size()){
			a=i,b=0;
			break;
		}
		if(g[i][0]!=0){
			a=i,b=0;
			break;
		}
		FOR(j,1,g[i].size()){
			if(g[i][j]-g[i][j-1]!=1&&g[i][j-1]+1!=i){
				a=i;b=g[i][j-1]+1;
				break;
			}
		}
		if(a!=-1) break;
		if(i!=n-1&&g[i][g[i].size()-1]!=n-1){
			a=i;b=n-1;break;
		}
	}
	if(a==-1){
		puts("NO");
		return 0;
	}
	puts("YES");
	ans[a]=1;ans[b]=2;
	int cnt=3;
	FOR(i,0,n) if(!ans[i]) ans[i]=cnt++;
	FOR(i,0,n) printf("%d ",ans[i]);
	puts("");
	FOR(i,0,n) printf("%d ",(ans[i]==2)?(1):(ans[i]));
	puts("");
	return 0;
}