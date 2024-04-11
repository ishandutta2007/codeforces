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

int n,a[55],e[5][5],q,s,f[55],A[5],B[5];

void rec(int x,int y){
	if (y==n){
		if (A[x]*n!=s)return;
		y=0,x++;
	}else if (x==n-1&&y>0){
		if(B[y-1]*n!=s)return;
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
		f[i]=1;
		rec(x,y+1);
		f[i]=0;
		A[x]-=a[i];
		B[y]-=a[i];
	}
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n;
	for (int i=0;i<n*n;i++)cin >> a[i],s+=a[i];
	sort(a,a+n*n);
	rec(0,0);
	return 0;
}