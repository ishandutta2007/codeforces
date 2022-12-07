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

int n,q1[3333],q2[3333],d[3333],ans=0;
char a[2222][2222];

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	scanf("%d\n",&n);
	for (int i=0;i<n;i++)gets(a[i]);
	for (int i=0;i<n;i++)for (int j=0;j<n;j++)if (a[i][j]=='1')a[i][j]=1;else a[i][j]=0;
	for (int i=0;i<n;i++)for (int j=n-1;j>i;j--)if (a[i][j]^q1[i]^q2[j]){
		ans++;
		q1[i]^=1;
		q2[j]^=1;
		d[i]^=1;
		d[j]^=1;
	}
	m0(q1);
	m0(q2);
	for (int i=n-1;i>=0;i--)for (int j=0;j<i;j++)if (a[i][j]^q1[i]^q2[j]){
		ans++;
		q1[i]^=1;
		q2[j]^=1;
		d[i]^=1;
		d[j]^=1;
	}
	for (int i=0;i<n;i++)if (a[i][i]^d[i])ans++;
	CC(ans);
	return 0;
}