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

int n,x,y,kk=0,xx[111111],yy[111111],pp[111111],f[111111],q[111111];

bool rec(int x,int e,int p){
	f[x]=1;
	int t=0;
	for(int w=xx[x];w;w=pp[w])if (yy[w]!=p){
		if (f[yy[w]]&&yy[w]==e)t=1;
		if (!f[yy[w]])t|=rec(yy[w],e,x);
	}
	return t;
}

int rc(int x){
	if (q[x])return 0;
	if (f[x])return 1000000;
	f[x]=1;
	int r=1e9;
	for (int w=xx[x];w;w=pp[w])r=min(r,rc(yy[w])+1);
	return r;
	
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n;
	for (int i=0;i<n;i++){
		cin >> x >> y;
		x--;
		y--;
		yy[++kk]=y;
		pp[kk]=xx[x];
		xx[x]=kk;
		yy[++kk]=x;
		pp[kk]=xx[y];
		xx[y]=kk;
	}
	for (int i=0;i<n;i++){
		m0(f);
		q[i]=rec(i,i,i);
	}
	for (int i=0;i<n;i++){
		m0(f);
		cout << rc(i) << " ";
	}
	return 0;
}