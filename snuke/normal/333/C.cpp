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

const int MX = 100005, INF = 1000000000, mod = 1000000009;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-9;
const int dx[4] = {-1,0,1,0}, dy[4] = {0,-1,0,1}; //<^>v

set<int> s;

int op(int x, int y, int o){
	if(o == 0) return x*10+y;
	if(o == 1) return x+y;
	if(o == 2) return x-y;
	return x*y;
}

void f(int x, int y, int z){
	//printf("dfs %d %d %d\n",x,y,z);
	int a[4], o[3];
	rep(i,4){
		a[i] = x/1000;
		x = (x%1000)*10;
	}
	rep(i,3){
		o[i] = z/16;
		z = (z%16)*4;
	}
	int b = y/2, c = y%2;
	if(b && o[b-1] == 0) return;
	if(b<3 && o[b] != 0 && o[b+1] == 0) return;
	
	//rep(i,4) printf("%d ",a[i]); printf("a %d %d\n",b,op(a[b],a[b+1],o[b]));
	a[b] = op(a[b],a[b+1],o[b]);
	for(; b < 2; b++) a[b+1] = a[b+2], o[b] = o[b+1];
	
	if(c && o[0] == 0) return;
	if(!c && o[0] != 0 && o[1] == 0) return;
	//rep(i,4) printf("%d ",a[i]); printf("b %d %d %d %d\n",a[c],a[c+1],c,op(a[c],a[c+1],o[c]));
	a[c] = op(a[c],a[c+1],o[c]);
	for(; c < 1; c++) a[c+1] = a[c+2], o[c] = o[c+1];
	
	s.insert(abs(op(a[0],a[1],o[0])));
	
	//printf("%d %d\n",y,op(a[0],a[1],o[0]));
}

int main(){
	int k, m, a;
	scanf("%d%d",&k,&m);
	
	//int cnt = 0;
	rep(x,10000){
		s.clear();
		rep(i,6)rep(j,64){
			f(x,i,j);
		}
		//*
		each(it,s){
			a = (*it);
			//printf("%d %d\n",a,x);
			if(k+a < 10000 && k+a >= 0){
				printf("%04d%04d\n",k+a,x);
				m--;
			}
			if(!m) return 0;
			if(!a) continue;
			if(k-a < 10000 && k-a >= 0){
				printf("%04d%04d\n",k-a,x);
				m--;
			}
			if(!m) return 0;
		}//*/
		//cnt += s.size();
	}
	
	//cout << cnt << endl;
	
	return 0;
}