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

int n,f[555][555],ans=1e9,l,o,k,p[555][555],w[555][555],g[555];
char a[555];

int sl(int x,int y){
	if (x>=y)return 0;
	if (w[x][y]>=0)return w[x][y];
	return w[x][y]=sl(x+1,y-1)+(a[x]!=a[y]);
}


int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	gets(a);
	n=strlen(a);
	cin >> k;
	for (int i=0;i<n;i++)for (int j=0;j<n;j++)w[i][j]=-1;
	m1(f);
	f[0][0]=0;
	for (int i=0;i<n;i++)for (int j=0;j<k;j++){
		for (int l=i;l<n;l++)if (f[i][j]+sl(i,l)<f[l+1][j+1])f[l+1][j+1]=f[i][j]+sl(i,l),p[l+1][j+1]=i;
        }
	for (int i=1;i<=k;i++)if (f[n][i]<ans)ans=f[n][i],l=i;
	CC(ans);
	o=n;
	for (int i=l;i>=0;i--){
		int x=p[o][i];
		for (int j=0;j<(o-x);j++)a[x+j]=a[o-j-1];
		o=x;
		g[o]=1;
	}
	for (int i=0;i<n;i++){
		if (g[i]&&i)putchar('+');
		putchar(a[i]);
	}
	return 0;
}