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
#define M 1000000007

int n,m,nn,q[333][333];
char a[1111][1111];
long long q1[333],q2[333],d[333];

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	scanf("%d%d\n",&n,&m);
	nn=n*4+1;
	for (int i=0;i<nn;i++)gets(a[i]);
	for (int i=0;i<n;i++)for (int j=0;j<m;j++){
		string s="";
		for (int ii=0;ii<3;ii++)for (int jj=0;jj<3;jj++)s+=a[i*4+1+ii][j*4+1+jj];
		if (s==".........")q[i][j]=3;
		if (s=="....O....")q[i][j]=3;
		if (s=="..O...O..")q[i][j]=1;
		if (s=="O.......O")q[i][j]=2;
		if (s=="..O.O.O..")q[i][j]=1;
		if (s=="O...O...O")q[i][j]=2;
		if (s=="O.O...O.O")q[i][j]=3;
		if (s=="O.O.O.O.O")q[i][j]=3;
		if (s=="O.OO.OO.O")q[i][j]=1;
		if (s=="OOO...OOO")q[i][j]=2;
	}
	for (int i=0;i<m;i++){
		if (n%2==0){
			int t=0;
			for (int j=0;j<n;j++)if (q[j][i]==2)t=1;
			if (!t)q1[i]=1;
		}
		if (i<m-1){
			m0(d);
			d[0]=1;
			for (int j=0;j<n;j++){
				if (q[j][i]!=1&&q[j][i+1]!=1)d[j+1]=(d[j+1]+d[j])%M;
				if (j<n-1&&q[j][i]!=2&&q[j][i+1]!=2&&q[j+1][i]!=2&&q[j+1][i+1]!=2)d[j+2]=(d[j+2]+d[j])%M;
			}
			q2[i]=d[n];
		}
	}
	for (int i=0;i<m-1;i++)if (q1[i]&&q1[i+1])q2[i]=(q2[i]-1+M)%M;
	m0(d);
	d[0]=1;
	for (int i=0;i<m;i++){
		d[i+1]=(d[i+1]+d[i]*q1[i])%M;
		d[i+2]=(d[i+2]+d[i]*q2[i])%M;
	}
	CC(d[m]);
	return 0;
}