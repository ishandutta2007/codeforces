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
#define AL(x) x.begin(),x.end()
#define pw(x) (1ull<<(x))
#define M 1000000007
using namespace std;
typedef pair<int,int> pt;
typedef vector<int> vt;

int n,m,xs,ys,x,y,o,xx[6111111],pp[4444444],kk,q1,q2,qx[4444444],qy[4444444];
long long yy[4444444];
char a[2222][2222];
string ans="No";

bool ww(int x,int y){
	x+=1111111;
	y+=1111111;
	long long e=x*300001100ll+y;
	int h=e%6000011;
	for (int w=xx[h];w;w=pp[w])if (yy[w]==e)return 1;
	return 0;
}

void ad(int x,int y){
	x+=1111111;
	y+=1111111;
	long long e=x*300001100ll+y;
	int h=e%6000011;
	yy[++kk]=e;
	pp[kk]=xx[h];
	xx[h]=kk;
}

void rec(int x,int y){
	if (a[(x+M*1ll*n)%n][(y+M*1ll*m)%m]=='#')return;
	if (ww(x,y))return;
	ad(x,y);
	if (kk>n*m){
		ans="Yes";
		return;
	}
	qx[q1]=x;
	qy[q1++]=y;
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	scanf("%d%d\n",&n,&m);
	for (int i=0;i<n;i++)gets(a[i]);
	for (int i=0;i<n;i++)for (int j=0;j<m;j++)if (a[i][j]=='S')xs=i,ys=j;
	rec(xs,ys);
	while (q1!=q2){
		x=qx[q2];
		y=qy[q2++];
		rec(x-1,y);
		rec(x+1,y);
		rec(x,y-1);
		rec(x,y+1);
	}
	CC(ans);
	return 0;
}