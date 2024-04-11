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
#define O 1

int n,a[2222][2222],a1,a2,e[2222][2222],f[2222][2222],N,A,B;
double xx,yy,u,mi,ma,r,ss,q1,q2;

                           
void rec(int x,int y,int o){
	if (x<1||x>N||y<1||y>N||e[x][y]==0||f[x][y]==o)return;
	f[x][y]=o;
	if (o==1)xx+=x,yy+=y;
	u++;
	ss+=sqrt(sqr(xx-x)+sqr(yy-y));
	if (e[x][y-1]==0||e[x][y+1]==0||e[x+1][y]==0||e[x-1][y]==0)mi=min(mi,sqrt(sqr(xx-x)+sqr(yy-y)));
	ma=max(ma,sqrt(sqr(xx-x)+sqr(yy-y)));
	rec(x,y-1,o);
	rec(x,y+1,o);
	rec(x-1,y,o);
	rec(x+1,y,o);
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	scanf("%d\n",&n);
	for (int i=1;i<=n;i++)for (int j=1;j<=n;j++)scanf("%d",&a[i][j]),a[i][j]++;
	N=n/O;
	for (int i=1;i<=N;i++)for (int j=1;j<=N;j++){
		A=B=0;
		for (int x=0;x<O;x++)for (int y=0;y<O;y++)if (a[i*O+x][j*O+y]==2)A++;else if (a[i*O+x][j*O+y]==1)B++;
		if (A>B)e[i][j]=1;else e[i][j]=0;
	}
/*	for (int i=1;i<N;i++){
		for (int j=1;j<=N;j++)cout << e[i][j];
		puts("");
	}*/
	for (int i=1;i<=N;i++)for (int j=1;j<=N;j++)if (e[i][j]&&!f[i][j]){
		xx=yy=0;
		u=0;
		rec(i,j,1);
		if (u<3)continue;
		xx/=u;
		yy/=u;
		mi=1e9;
		ma=0;
		rec(i,j,2);
		q1=sqrt(2)*mi-ma;
		q2=ma-mi;
		r=sqrt(2)*mi-ma-(ma-mi);
		if (r>0)a2++;else a1++;
	}
	cout << a2 << " " << a1 << endl;
	return 0;
}