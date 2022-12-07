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

int n,k,a[5555],b[5555],f[4004][4004],ans,x,o;

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n >> k;
	for (int i=0;i<n;i++)cin >> a[i] >> b[i];
	a[n]=86401;
	m1(f);
	f[0][0]=1;
	for (int i=0;i<n;i++)for (int j=0;j<=k;j++){
		if (a[i]>f[i][j])f[i+1][j]=min(f[i+1][j],a[i]+b[i]);else
		f[i+1][j]=min(f[i+1][j],f[i][j]+b[i]);
		f[i+1][j+1]=min(f[i+1][j+1],f[i][j]);
	}
	for (int i=0;i<=n;i++)for (int j=0;j<=k;j++){
		x=k-j;
		o=a[min(i+x,n)];
		ans=max(ans,o-f[i][j]);
	}
	CC(ans);
	return 0;
}