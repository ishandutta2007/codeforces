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


int n,m,k,A,B,a,b,yy[111111],pp[111111],xx[111111],s[111111],t[111111],ms[333][333],kk,ans;
long long q[333][333];
int w[111][111][111];

int rec(int x,int g,int o){
//	cout << x+1 << " " << g << " " << o << endl;
	if (x==B)return o;
	if (o>n)return 1e9;
	if (w[x][g][o])return w[x][g][o]-1;
	if (g==k){	
		int r=1e9;
		for (int i=0;i<k;i++)
		if (ms[s[i]][t[i]]<1e5&&ms[s[i]][x]+ms[x][t[i]]==ms[s[i]][t[i]]&&q[s[i]][t[i]]==q[s[i]][x]*q[x][t[i]])
		r=min(r,rec(x,i,o+1));
		return (w[x][g][o]=r+1)-1;
	}
	int r=-1;
	for (int w=xx[x];w;w=pp[w])if (ms[s[g]][x]+ms[yy[w]][t[g]]+1==ms[s[g]][t[g]]){
		r=max(r,rec(yy[w],g,o));
		if (r>1e5)break;
	}
	if (r<0)r=1e9;
	r=min(r,rec(x,k,o));
	return (w[x][g][o]=r+1)-1;
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n >> m >> A >> B;
	A--,B--;
	for (int i=0;i<n;i++)for (int j=0;j<n;j++)ms[i][j]=1e9;
	for (int i=0;i<n;i++)ms[i][i]=0,q[i][i]=1;
	for (int i=0;i<m;i++){
		cin >> a >> b;
		a--,b--;
		yy[++kk]=b;
		pp[kk]=xx[a];
		xx[a]=kk;
		ms[a][b]=1;
		q[a][b]=1;
	}
	for (int k=0;k<n;k++)for (int i=0;i<n;i++)for (int j=0;j<n;j++)if (i!=j&&k!=i&&k!=j){
		if (ms[i][k]+ms[k][j]<ms[i][j])ms[i][j]=ms[i][k]+ms[k][j],q[i][j]=q[i][k]*q[k][j];else
		if (ms[i][k]+ms[k][j]==ms[i][j])q[i][j]+=q[i][k]*q[k][j];
	}
	cin >> k;
	for (int i=0;i<k;i++)cin >> s[i] >> t[i],s[i]--,t[i]--;
	ans=rec(A,k,0);
	if (ans>1e5)puts("-1");else
	CC(ans);
	return 0;
}