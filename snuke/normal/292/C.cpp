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

int d[10], n, p[15], o[5];
int x[300], xi;

string s[MX]; int si;

/*
bool f(int a){
	if(a == 0 && !d[0]) return false;
	while(a){
		if(!d[a%10]) return false;
		a /= 10;
	}
	return true;
}//*/

void ch(int k, int l, int dep){
	if(dep == 0){
		if(l != k) return;
		string t; int a;
		rep(i,4){
			t = ""; a = o[i]; if(a == 0) t = '0';
			while(a){ t += '0'+a%10; a /= 10;}
			reverse(rng(t)); s[si] += t;
			if(i == 3) si++; else s[si] += '.';
		}
		return;
	}
	dep--;
	int a;
	rrep(i,(p[l]==0?1:3)){
		if(l+i > k) continue;
		a = 0;
		rep(j,i) a = a*10+p[l+j];
		if(a > 255) continue;
		o[3-dep] = a;
		ch(k,l+i,dep);
	}
}

void dfs(int k, int dep){
	if(dep == 0){
		int m = (k+1)/2;
		bool bl;
		rep(i,n){
			bl = false;
			rep(j,m) if(d[i] == p[j]) bl = true;
			if(!bl) return;
		}
		rep(j,m) p[k-1-j] = p[j];
		ch(k,0,4);
		return;
	}
	dep--;
	rep(i,n){
		p[dep] = d[i];
		dfs(k,dep);
	}
}

int main(){
	scanf("%d",&n);
	rep(i,n) scanf("%d",&d[i]);
	//rep(i,n){ scanf("%d",&a); d[a] = true;}
	//rep(i,256) if(f(i)) x[xi++] = i;
	
	for(int i = 4; i <= 12; i++) dfs(i,(i+1)/2);
	
	printf("%d\n",si);
	rep(i,si) printf("%s\n",s[i].c_str());
	
	return 0;
}