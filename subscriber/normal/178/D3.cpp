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

int n,a[55],e[5][5],q,s,f[55],A[5],B[5],D;

int X[16]={0,0,0,0,1,1,1,1,2,3,2,3,2,3,2,3};
int Y[16]={0,1,2,3,0,1,2,3,0,0,1,1,2,2,3,3};

void rec(int x,int y){
	if (y==n){
		if (A[x]*n!=s)return;
		y=0,x++;
	}else if (x==n-1&&y>0){
		if(D*n!=s||B[y-1]*n!=s)return;
	}
	if (x==n){
		for (int i=0;i<n;i++)if (A[i]*n!=s)return;
		for (int i=0;i<n;i++)if (B[i]*n!=s)return;
		q=0;
		for (int i=0;i<n;i++)q+=e[i][i];
		if (q*n!=s)return;
		q=0;
		for (int i=0;i<n;i++)q+=e[i][n-1-i];
		if (q*n!=s)return;
		CC(q);
		for (int i=0;i<n;i++){
			for (int j=0;j<n;j++)cout << e[i][j] << " ";
			puts("");
		}
		exit(0);
	}
	for (int i=0;i<n*n;i++)if (!f[i]){
		if (i>0&&f[i-1]==0&&a[i]==a[i-1])continue;
		e[x][y]=a[i];
		A[x]+=a[i];
		B[y]+=a[i];
		if (x==n-y-1)D+=a[i];
		f[i]=1;
		rec(x,y+1);
		f[i]=0;
		if (x==n-y-1)D-=a[i];
		A[x]-=a[i];
		B[y]-=a[i];
	}
}

void rc(int l){
	if (l==4&&A[0]*n!=s)return;
	if (l==8&&A[1]*n!=s)return;
	if (l==10&&B[0]*n!=s)return;
	if (l==12&&B[1]*n!=s)return;
	if (l==14&&B[2]*n!=s)return;
	if (l==16){
		for (int i=0;i<n;i++)if (A[i]*n!=s)return;
		for (int i=0;i<n;i++)if (B[i]*n!=s)return;
		q=0;
		for (int i=0;i<n;i++)q+=e[i][i];
		if (q*n!=s)return;
		q=0;
		for (int i=0;i<n;i++)q+=e[i][n-1-i];
		if (q*n!=s)return;
		CC(q);
		for (int i=0;i<n;i++){
			for (int j=0;j<n;j++)cout << e[i][j] << " ";
			puts("");
		}
		exit(0);
	}
	for (int i=0;i<n*n;i++)if (!f[i]){
		e[X[l]][Y[l]]=a[i];
		A[X[l]]+=a[i];
		B[Y[l]]+=a[i];
		f[i]=1;
		rc(l+1);
		A[X[l]]-=a[i];
		B[Y[l]]-=a[i];
		f[i]=0;

	}
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n;
	for (int i=0;i<n*n;i++)cin >> a[i],s+=a[i];
	random_shuffle(a,a+n*n);
	if (n<4)rec(0,0);
	if (n==4)rc(0);
	return 0;
}