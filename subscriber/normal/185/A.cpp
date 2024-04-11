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

long long a[2][2],r[2][2],c[2][2],n;

void mm1(){
	m0(c);
	for (int i=0;i<2;i++)for (int j=0;j<2;j++)for (int k=0;k<2;k++)c[i][j]=(c[i][j]+r[i][k]*r[k][j])%M;
	for (int i=0;i<2;i++)for (int j=0;j<2;j++)r[i][j]=c[i][j];
}

void mm2(){
	m0(c);
	for (int i=0;i<2;i++)for (int j=0;j<2;j++)for (int k=0;k<2;k++)c[i][j]=(c[i][j]+r[i][k]*a[k][j])%M;
	for (int i=0;i<2;i++)for (int j=0;j<2;j++)r[i][j]=c[i][j];
}

void gg(long long x){
	if (!x)return;
	gg(x/2);
	mm1();
	if (x%2)mm2();
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	                               
	cin >> n;
	a[0][0]=3;
	a[0][1]=1;
	a[1][0]=1;
	a[1][1]=3;
	m0(r);
	r[0][0]=r[1][1]=1;
	gg(n);
	CC(r[0][0]);
	return 0;
}