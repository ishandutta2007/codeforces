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

int n,a[555555],w[555555][2];
long long f[555555][2],x,y;

long long rec(int x,int t){
	if (x<=0||x>n)return 0;
	if (x==1){
		if (t==0)return -1e9-10;
		if (t==1)return 1e17;
	}
	if (w[x][t]==1)return -1e9-10;
	if (w[x][t]==2)return f[x][t];
	w[x][t]=1;
	long long r;
	if (t==0)r=rec(x+a[x],1)+a[x];
	if (t==1)r=rec(x-a[x],0)+a[x];
	if (r<0)r=-1e9-10;
	w[x][t]=2;
	return f[x][t]=r;
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n;
	for (int i=2;i<=n;i++)scanf("%d",&a[i]);
	for (int i=1;i<n;i++){
		long long x=1,y=0;
		x+=i;
		y+=i;
		y+=rec(x,1);
		if (y>=1e17){
			y-=1e17;
			y+=i;
		}
		if (y<0)puts("-1");else
		cout << y << endl;
	}
	return 0;
}