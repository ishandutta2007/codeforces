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

int n,l,k,p[222],a[222];
double f[222][222][466],ans;

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n >> l >> k;
	for (int i=0;i<n;i++)cin >> p[i];
	for (int i=0;i<n;i++)cin >> a[i];
	f[0][0][k+200]=1;
	for (int i=0;i<n;i++)for (int j=0;j<=i;j++)for (int h=1;h<=400;h++){
			f[i+1][j][h]+=f[i][j][h]*(100-p[i])/100.;
			f[i+1][j+1][min(400,h+a[i])]+=f[i][j][h]*p[i]/100.;
	}
	for (int i=l;i<=n;i++)for (int j=200;j<=400;j++)ans+=f[n][i][j];
	CC(ans);
	return 0;
}