#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<ctime>
#include<queue>
#include<deque>
#include<complex>
using namespace std;
#define pb push_back
#define pf push_front
typedef long long lint;
typedef complex<double> P;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
int dep[1100000];
int dbl[1100000][25];
void aedge(int x,int y){
	dbl[y][0]=x;dep[y]=dep[x]+1;
	rep(i,20) dbl[y][i+1]=dbl[dbl[y][i]][i];
}
int lca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	rep(i,20){
		if(((dep[x]-dep[y])&(1<<i))) x=dbl[x][i];
	}
	for(int i=19;i>=0;i--){
		if(dbl[x][i]!=dbl[y][i]){x=dbl[x][i];y=dbl[y][i];}
	}
	return dbl[x][0];
}
int dist(int x,int y){
	return dep[x]+dep[y]-dep[lca(x,y)]*2;
}
int main()
{
	rep(i,3) aedge(0,i+1);int x=1,y=2,n=3,m,a,ret=2;
	scanf("%d",&m);
	rep(i,m){
		scanf("%d",&a);a--;
		aedge(a,++n);aedge(a,++n);
		if(dist(x,n)>ret){
			ret++;y=n;
		}
		else if(dist(y,n)>ret){
			ret++;x=n;
		}
		printf("%d\n",ret);
	}
}