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
#define pw(x) (1ull<<(x))
#define M 1000000007
using namespace std;
typedef pair<int,int> pt;

int n,k,e,d,ex,ey;
long long x[6666],y[6666],zx[6666],zy[6666],ans=0,xx,yy;
bool w[6555][6555],u[6555][6555];
pair<long long,int>q[6666];
char o;

void rec(int x,int y){
	if (x<0||y<0||x>ex+4||y>ey+4||w[x][y]||u[x][y])return;
	u[x][y]=1;
	rec(x-1,y);
	rec(x+1,y);
	rec(x,y-1);
	rec(x,y+1);
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n;
	x[0]=y[0]=0;
	for (int i=0;i<n;i++){
		cin >> o >> d;
		x[i+1]=x[i];
		y[i+1]=y[i];
		if (o=='R')x[i+1]+=d;
		if (o=='L')x[i+1]-=d;
		if (o=='U')y[i+1]+=d;
		if (o=='D')y[i+1]-=d;
	}
	k=0;
	for (int i=0;i<=n;i++){
		q[k++]=mp(x[i],i);
		q[k++]=mp(x[i]-1,-1);
		q[k++]=mp(x[i]+1,-1);
	}
	sort(q,q+k);
	e=2;
	for (int i=0;i<k;i++){
		if (!i||q[i-1].F!=q[i].F)e++;
		zx[e]=q[i].F;
		if (q[i].S!=-1)x[q[i].S]=e;
	}
	ex=e;
	k=0;
	for (int i=0;i<=n;i++){
		q[k++]=mp(y[i],i);
		q[k++]=mp(y[i]-1,-1);
		q[k++]=mp(y[i]+1,-1);
	}
	sort(q,q+k);
	e=2;
	for (int i=0;i<k;i++){
		if (!i||q[i-1].F!=q[i].F)e++;
		zy[e]=q[i].F;
		if (q[i].S!=-1)y[q[i].S]=e;
	}
	ey=e;
	w[x[0]][y[0]]=1;
	for (int i=0;i<n;i++){
		xx=x[i];
		yy=y[i];
		while (xx!=x[i+1]||yy!=y[i+1]){
			if (xx<x[i+1])xx++;
			if (xx>x[i+1])xx--;
			if (yy<y[i+1])yy++;
			if (yy>y[i+1])yy--;
			w[xx][yy]=1;
		}
	}
	rec(0,0);
	for (int i=0;i<=ex;i++)for (int j=0;j<=ey;j++)if (!u[i][j]){
//	        cout << i << " " << j << " " << zx[i] << " " << zy[j] << " " << (zx[i]-zx[i-1])*1ll*(zy[j]-zy[j-1]) << endl;
		ans+=(zx[i]-zx[i-1])*1ll*(zy[j]-zy[j-1]);
	}
	CC(ans);
	return 0;
}