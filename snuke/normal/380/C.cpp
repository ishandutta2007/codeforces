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
#define adds(x,y) x = (x+(y))%mod;
#define dels(x,y) x = (x-(y)+mod)%mod;
#define muls(x,y) x = ((ll)x*(y))%mod;
#define pb push_back
#define sz(x) (int)(x).size()
#define snuke srand((unsigned)clock()+(unsigned)time(NULL))
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;

const int MX = 1000005, INF = 1000000000, mod = 1000000007;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;
const int dx[] = {-1,0,1,0}, dy[] = {0,-1,0,1}; //<^>v

char in[MX];
string s;
int l[MX], r[MX], c[MX];
vi h[MX];

int main(){
	int n, m;
	scanf("%s%d",in,&m);
	s = in;
	n = s.size();
	
	stack<int> t;
	rep(i,n){
		if(s[i] == '('){
			t.push(i);
		} else {
			if(!t.empty()){
				l[t.top()+1] = c[t.top()+1] = 1;
				r[i+1] = c[i+1] = 1;
				t.pop();
			}
		}
	}
	
	rep(i,n){
		l[i+1] += l[i];
		r[i+1] += r[i];
		c[i+1] += c[i];
	}
	
	int mx = 0;
	rrep(i,n){
		if(l[i]-l[i-1] == 1){
			h[l[i]-r[i]].pb(i);
			mx = max(mx,l[i]-r[i]);
		}
	}
	rep(i,mx+1) h[i].pb(INF);
	//rep(i,mx+1) rep(j,sz(h[i])) printf("%d ",h[i][j]);puts("");
	
	int a, b;
	rep(i,m){
		scanf("%d%d",&a,&b);
		a--;
		int x = c[b]-c[a];
		int y = l[b]-r[a];
		//cerr << "xy " << x << " " << y << endl;
		int ar1 = l[a+1]-r[a+1];
		if(l[a+1]-l[a]==1) ar1--;
		int ar2 = l[b]-r[b];
		//if(r[b]-r[b-1]==1) ar2--;
		int al = 0, ar = min(ar1,ar2)+1, ac, ax, ay;
		//printf("%d %d %d\n",al,ar1,ar2);
		while(al+1<ar){
			ac = (al+ar)/2;
			ax = lower_bound(rng(h[ac]),a+1)-h[ac].begin();
			ay = lower_bound(rng(h[ac]),b+1)-h[ac].begin();
			//cerr << "l r " << ac << " " << ax << " " << ay << endl;
			if(ay==ax) al = ac; else ar = ac;
		}
		
		y -= al;
		int d = y*2-x;
		//cerr << "Non " << d << " " << al << endl;
		printf("%d\n",x-d);
	}
	
	return 0;
}