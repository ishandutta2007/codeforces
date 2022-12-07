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

string s;
int n,k,f[111][111][111][2],ans=0;


int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> s >> k;
	n=s.size();
	m0(f);
	f[0][0][0][1]=1;
	for (int i=0;i<n;i++)for (int j=0;j<=k;j++)for (int x=0;x<=i;x++)for (int l=0;l<2;l++)if (f[i][j][x][l]){
		if (s[i]=='F'){
			if (l)f[i+1][j][x+1][1]=1;else{
				if (!x)f[i+1][j][1][1]=1;else f[i+1][j][x-1][0]=1;
			}
			f[i+1][j+1][x][l^1]=1;
		}else{
			f[i+1][j][x][l^1]=1;
			if (l)f[i+1][j+1][x+1][1]=1;else{
				if (!x)f[i+1][j+1][1][1]=1;else f[i+1][j+1][x-1][0]=1;
			}
		}
	}
	for (int i=0;i<2;i++)for (int j=0;j<=n;j++)for (int o=0;o<=k;o++)if (abs(k-o)%2==0&&f[n][o][j][i])ans=max(ans,j);
	CC(ans);
	return 0;
}