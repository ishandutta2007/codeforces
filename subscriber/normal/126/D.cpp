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

long long n,f[103];
long long w[111][4][4];
int d[100],t;

long long rec(int l){
	if (l==2){
		if (d[0]<2&&d[1]<2)return 1;
		return 0;
	}
	if (d[l-1]>2||d[l-2]>2)return 0;
	if (w[l][d[l-1]][d[l-2]]!=-1)return w[l][d[l-1]][d[l-2]];
	long long r=0;
	if (d[l-1]<2)r+=rec(l-1);
	if (d[l-1]>0){
		d[l-3]++;
		d[l-2]++;
		r+=rec(l-1);
		d[l-3]--;
		d[l-2]--;
	}
	return w[l][d[l-1]][d[l-2]]=r;

}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	f[0]=1;
	f[1]=2;
	for (int i=2;i<100;i++)f[i]=f[i-1]+f[i-2];
	cin >> t;
	while(t--){
		cin >> n;
		long long x=n;
		m0(d);
		for (int i=88;i>=0;i--)if (f[i]<=x)x-=f[i],d[i]=1;
		for (int i=0;i<90;i++)for (int j=0;j<3;j++)for (int k=0;k<3;k++)w[i][j][k]=-1;
		CC(rec(87));
	}
	return 0;
}