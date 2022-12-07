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

int n,p[555],a[555][555],g[555][555],f[555];
long long ans,aa[555];

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n;
	for (int i=0;i<n;i++)for (int j=0;j<n;j++)scanf("%d",&a[i][j]);
	for (int i=0;i<n;i++)cin >> p[i],p[i]--;
	m1(g);
	for (int i=0;i<n;i++)g[i][i]=0;
	for (int i=n-1;i>=0;i--){
		int s=p[i];
		f[s]=1;
		ans=0;
		for (int j=0;j<n;j++)if (f[j])g[s][j]=a[s][j],g[j][s]=a[j][s];
		for (int j=0;j<n;j++)if (f[j])for (int k=0;k<n;k++)if (f[j]&&f[k])g[s][j]=min(g[s][j],g[s][k]+g[k][j]),g[j][s]=min(g[j][s],g[j][k]+g[k][s]);
		for (int j=0;j<n;j++)if (f[j])for (int k=0;k<n;k++)if (f[j]&&f[k])g[j][k]=min(g[j][k],g[j][s]+g[s][k]);
		for (int j=0;j<n;j++)if (f[j])for (int k=0;k<n;k++)if (f[j]&&f[k])ans+=g[j][k];
		aa[i]=ans;
	}
	for (int i=0;i<n;i++)cout << aa[i] << " ";
	return 0;
}