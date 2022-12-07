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

int n,m,a[111][111],q1[111],q2[111],A,B,C,ans=0;
vt v;

int main(){
	freopen("input.txt","r",stdin);	
	freopen("output.txt","w",stdout);	
	cin >> n >> m;
	for (int i=0;i<n;i++)for (int j=0;j<m;j++)cin >> a[i][j];
	cin >> A >> B >> C;
	v.pb(A);
	v.pb(B);
	v.pb(C);
	SV(v);
	for (int i=0;i<n;i++)for (int j=0;j<m;j++)q1[i]+=a[i][j];
	for (int i=0;i<n;i++)for (int j=i+1;j<n-1;j++){
		int s1=0,s2=0,s3=0;
		for (int k=0;k<=i;k++)s1+=q1[k];
		for (int k=i+1;k<=j;k++)s2+=q1[k];
		for (int k=j+1;k<n;k++)s3+=q1[k];
		vt vv;
		vv.pb(s1);
		vv.pb(s2);
		vv.pb(s3);
		SV(vv);
		if (v==vv)ans++;
	}
	for (int i=0;i<n;i++)for (int j=0;j<m;j++)q2[j]+=a[i][j];
	for (int i=0;i<m;i++)for (int j=i+1;j<m-1;j++){
		int s1=0,s2=0,s3=0;
		for (int k=0;k<=i;k++)s1+=q2[k];
		for (int k=i+1;k<=j;k++)s2+=q2[k];
		for (int k=j+1;k<m;k++)s3+=q2[k];
		vt vv;
		vv.pb(s1);
		vv.pb(s2);
		vv.pb(s3);
		SV(vv);
		if (v==vv)ans++;
	}
	CC(ans);
	return 0;
}