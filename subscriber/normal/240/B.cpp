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

int n,a,b,h[222],s[222],f[222][40004][2],ans=1e9+1;

int main(){
	freopen("input.txt","r",stdin);	
	freopen("output.txt","w",stdout);	
	cin >> n >> a >> b;
	for (int i=0;i<n;i++)cin >> h[i];
	for (int i=0;i<n;i++)s[i+1]=s[i]+h[i];
	m1(f);
	f[0][0][0]=0;
	f[0][0][1]=0;
	for (int i=0;i<n;i++)for (int j=0;j<=s[i+1];j++)for (int l=0;l<2;l++){
//		cout << i << " " << j << " " << l << " " << f[i][j][l] << endl;
		int bb=s[i]-j;
		if (j+h[i]<=a){
			if (i==0)f[i+1][j+h[i]][0]=min(f[i+1][j+h[i]][0],f[i][j][l]);else
			if (l==1)f[i+1][j+h[i]][0]=min(f[i+1][j+h[i]][0],f[i][j][l]+min(h[i],h[i-1]));else
			if (l==0)f[i+1][j+h[i]][0]=min(f[i+1][j+h[i]][0],f[i][j][l]);
		}
		if (bb+h[i]<=b){
			if (i==0)f[i+1][j][1]=min(f[i+1][j][1],f[i][j][l]);else
			if (l==1)f[i+1][j][1]=min(f[i+1][j][1],f[i][j][l]);else
			if (l==0)f[i+1][j][1]=min(f[i+1][j][1],f[i][j][l]+min(h[i],h[i-1]));
			
		}
	}
	for (int j=0;j<=s[n]&&j<=a;j++)for (int l=0;l<2;l++)ans=min(ans,f[n][j][l]);
	if (ans>=1e9)CC(-1);else
	CC(ans);
	return 0;
}