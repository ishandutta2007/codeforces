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
#include<complex>
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
#define gep(i,g,j) for(int i = g.head[j]; i != -1; i = g.e[i].next)
#define each(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define rng(a) a.begin(),a.end()
#define maxs(x,y) x = max(x,y);
#define mins(x,y) x = min(x,y);
#define pb push_back
#define sz(x) (int)(x).size()
#define snuke srand((unsigned)clock()+(unsigned)time(NULL))
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;

const int MX = 100005, INF = 1000000000;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;
const int dx[] = {-1,0,1,0}, dy[] = {0,-1,0,1}; //<^>v

bool d[1005][1005];

int main(){
	int k;
	cin >> k;
	
	if(k == 1){
		printf("2\nNY\nYN\n");
		return 0;
	}
	
	vi v;
	v.pb(3);
	v.pb(4);
	d[1][3] = true;
	d[1][4] = true;
	
	vi x;
	
	while(k > 1){
		x.pb(k&1);
		k >>= 1;
	}
	reverse(rng(x));
	
	int c = 5;
	rep(j,x.size()){
		rep(i,(int)v.size()-1){
			d[v[i]][c] = true;
			d[v[i]][c+1] = true;
		}
		d[v[(int)v.size()-1]][c+2] = true;
		if(x[j]) d[v[(int)v.size()-1]][c] = true;
		v.clear();
		v.pb(c++);
		v.pb(c++);
		v.pb(c++);
	}
	
	rep(i,(int)v.size()-1){
		d[v[i]][2] = true;
	}
	
	printf("%d\n",c-1);
	rrep(i,c-1){
		rrep(j,c-1) printf("%c",d[i][j]||d[j][i]?'Y':'N');
		puts("");
	}
	
	return 0;
}