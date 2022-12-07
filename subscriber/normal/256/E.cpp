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
#define M 777777777
using namespace std;
typedef pair<int,int> pt;     

int n,m,q[4][4],v,t;
long long s[333333][4][4],ans;


void ini(int pos,int l,int r){
	if (l==r){
		for (int i=0;i<3;i++)for (int j=0;j<3;j++)s[pos][i][j]=0;
		for (int i=0;i<3;i++)s[pos][i][i]=1;
		return;
	}
	int c=(l+r)/2;
	ini(pos+pos,l,c);
	ini(pos+pos+1,c+1,r);
	for (int i=0;i<3;i++)for (int j=0;j<3;j++)s[pos][i][j]=0;
	for (int i=0;i<3;i++)for (int j=0;j<3;j++)
	for (int ii=0;ii<3;ii++)for (int jj=0;jj<3;jj++)if (q[ii][jj])
	s[pos][i][j]=(s[pos][i][j]+s[pos+pos][i][ii]*1ll*s[pos+pos+1][jj][j])%M;
}

void add(int pos,int l,int r,int v,int t){
	if (v>r||v<l)return;
	if (l==r){
		for (int i=0;i<3;i++)for (int j=0;j<3;j++)s[pos][i][j]=0;
		if (t>0)s[pos][t-1][t-1]=1;else for (int i=0;i<3;i++)s[pos][i][i]=1;
		return;		
	}
	int c=(l+r)/2;
	add(pos+pos,l,c,v,t);
	add(pos+pos+1,c+1,r,v,t);
	for (int i=0;i<3;i++)for (int j=0;j<3;j++)s[pos][i][j]=0;
	for (int i=0;i<3;i++)for (int j=0;j<3;j++)
	for (int ii=0;ii<3;ii++)for (int jj=0;jj<3;jj++)if (q[ii][jj])
	s[pos][i][j]=(s[pos][i][j]+s[pos+pos][i][ii]*1ll*s[pos+pos+1][jj][j])%M;
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n >> m;
	for (int i=0;i<3;i++)for (int j=0;j<3;j++)cin >> q[i][j];
	ini(1,0,n-1);
	for (int i=0;i<m;i++){
		scanf("%d%d",&v,&t);
		add(1,0,n-1,v-1,t);
		ans=0;
		for (int ii=0;ii<3;ii++)for (int jj=0;jj<3;jj++)ans=(ans+s[1][ii][jj])%M;
		printf("%d\n",(int)ans);
	}
	return 0;
}