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

int n,a[5555],l,r,c,f[5055][5055],s[5055],p[5055][5055];

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n;
	for (int i=0;i<n;i++)cin >> a[i];
	for (int i=0;i<n;i++)s[i+1]=s[i]+a[i];
	m1(f);
	m1(p);
	f[0][0]=0;
	for (int i=0;i<=n;i++)for (int j=0;j<=i;j++){
		if (i&&j)p[i][j]=min(p[i][j],p[i-1][j-1]+a[i-1]);
		f[i][j]=min(f[i][j],p[i][j]);
		if (f[i][j]>1e9)continue;
		if (i==n)continue;
		l=i+1;
		r=n;
		while(l<r){
			c=(l+r)/2;
			if (s[c]-s[i]<f[i][j])l=c+1;else r=c;
		}
		if (s[l]-s[i]<f[i][j])continue;
		p[l][j+(l-i-1)]=min(p[l][j+(l-i-1)],s[l]-s[i]);
	}
	for (int i=0;i<n;i++)if (f[n][i]<1e9){
		CC(i);
		return 0;
	}
	return 0;
}