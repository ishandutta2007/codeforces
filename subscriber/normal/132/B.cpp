#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<sstream>
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define SV(x) sort(x.begin(),x.end())
#define pw(x) (1ull<<(x))
using namespace std;
typedef pair<int,int> pt;
typedef vector<int> vt;
typedef unsigned long long UL;

int n,k,aa,x,y,f[55][55],m1x[55][55],m2x[55][55],m1y[55][55],m2y[55][55],m;
string a[55];

void rec(int xx,int yy,int x,int y,char o){
	if (x<0||x>=n||y<0||y>=m||f[x][y]||a[x][y]!=o)return;
	f[x][y]=1;
	m1x[xx][yy]=min(m1x[xx][yy],x);
	m2x[xx][yy]=max(m2x[xx][yy],x);
	m1y[xx][yy]=min(m1y[xx][yy],y);
	m2y[xx][yy]=max(m2y[xx][yy],y); 
	rec(xx,yy,x-1,y,o);
	rec(xx,yy,x+1,y,o);
	rec(xx,yy,x,y-1,o);
	rec(xx,yy,x,y+1,o);
}

bool ok(int x,int y){
	if (x<0||x>=n||y<0||y>=m||a[x][y]=='0')return 0;
	return 1;
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n >> k;
	for (int i=0;i<n;i++)cin >> a[i];
	m=a[0].size();
	for (int i=0;i<n;i++)for (int j=0;j<m;j++)if (a[i][j]!='0'){
		m0(f);
		m1x[i][j]=m2x[i][j]=i;
		m1y[i][j]=m2y[i][j]=j;
		rec(i,j,i,j,a[i][j]);
	}
	x=0;
	y=0;
	aa=0;
	for (int i=0;i<k;i++){
		int xx=x;
		int yy=y;
		if (aa==0){
			if (ok(m1x[x][y],m2y[x][y]+1))x=m1x[x][y],y=m2y[x][y]+1;
		}
		if (aa==1){
			if (ok(m2x[x][y],m2y[x][y]+1))x=m2x[x][y],y=m2y[x][y]+1;
		}
		if (aa==2){
			if (ok(m2x[x][y]+1,m2y[x][y]))y=m2y[x][y],x=m2x[x][y]+1;
		}
		if (aa==3){
			if (ok(m2x[x][y]+1,m1y[x][y]))y=m1y[x][y],x=m2x[x][y]+1;
		}
		if (aa==4){
			if (ok(m2x[x][y],m1y[x][y]-1))x=m2x[x][y],y=m1y[x][y]-1;
		}
		if (aa==5){
			if (ok(m1x[x][y],m1y[x][y]-1))x=m1x[x][y],y=m1y[x][y]-1;
		}
		if (aa==6){
			if (ok(m1x[x][y]-1,m1y[x][y]))y=m1y[x][y],x=m1x[x][y]-1;
		}
		if (aa==7){
			if (ok(m1x[x][y]-1,m2y[x][y]))y=m2y[x][y],x=m1x[x][y]-1;
		}
		if (x==xx&&y==yy)aa=(aa+1)%8;
	}
	CC(a[x][y]);
	return 0;
}