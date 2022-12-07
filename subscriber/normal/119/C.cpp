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

int n,m,k,l1,l2,p1[111][111][111],p2[111][111][111],e1[111];
long long e2[111];
pair<pt,pair<long long,long long> >q[111];
long long f[111][111][111],ans=0;

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n >> m >> k;
	for (int i=0;i<m;i++)cin >> q[i].S.F >> q[i].S.S >> q[i].F.F;
	for (int i=0;i<m;i++)q[i].F.S=i;
	sort(q,q+m);
	memset(f,128,sizeof(f));
	for (int l=0;l<m;l++)
	for (int i=0;i<=q[l].S.S-q[l].S.F;i++)f[1][l][i]=q[l].S.F+i;
	for (int o=1;o<n;o++)
	for (int i=0;i<m-1;i++)for (int j=0;j<=q[i].S.S-q[i].S.F;j++)for (int l=i+1;l<m;l++)if (q[l].F.F>q[i].F.F){
		long long x=j+q[i].S.F+k;
		if (x>=q[l].S.F&&x<=q[l].S.S){
			if (f[o][i][j]+x>=f[o+1][l][x-q[l].S.F])f[o+1][l][x-q[l].S.F]=f[o][i][j]+x,p1[o+1][l][x-q[l].S.F]=i,p2[o+1][l][x-q[l].S.F]=j;
		}
		x=(j+q[i].S.F)*k;
		if (x>=q[l].S.F&&x<=q[l].S.S){
			if (f[o][i][j]+x>=f[o+1][l][x-q[l].S.F])f[o+1][l][x-q[l].S.F]=f[o][i][j]+x,p1[o+1][l][x-q[l].S.F]=i,p2[o+1][l][x-q[l].S.F]=j;
		}
	}	                                                             
	for (int i=0;i<m;i++)for (int j=0;j<=q[i].S.S-q[i].S.F;j++)if (f[n][i][j]>ans)ans=f[n][i][j],l1=i,l2=j;
	if (!ans){
		puts("NO");
		return 0;
	}
	for (int o=n;o;o--){
		e1[o-1]=q[l1].F.S+1;
		e2[o-1]=l2+q[l1].S.F;
		int t=p1[o][l1][l2];
		l2=p2[o][l1][l2];
		l1=t;
	}
	puts("YES");
	for (int i=0;i<n;i++)cout << e1[i] << " " << e2[i] << endl;
	return 0;
}