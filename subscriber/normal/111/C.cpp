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

int n,m,f[44][1111],a[44],ans=1000000;

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n >> m;
	if (n<m)swap(n,m);
	m1(f);
	int w=1;
	for (int i=0;i<m;i++)w=w*3;
	for (int i=0;i<pw(m);i++){
		int x=0,s=0;
		for (int j=0;j<m;j++)if (i&pw(j))x=x*3+2,s++;else if (j&&(i&pw(j-1))||(j<m-1)&&(i&pw(j+1)))x=x*3;else x=x*3+1;
		f[0][x]=s;
	}
	for (int i=0;i<n;i++)for (int j=0;j<w;j++){
		int u=j;
		for (int k=m-1;k>=0;k--){
			a[k]=u%3;
			u/=3;
		} 
		for (int o=0;o<pw(o);o++){
			int t=0,s=0,x=0;
			for (int k=0;k<m;k++)if (a[k]==1&&(o&pw(k))==0)t=1;
			if (t)continue;
			for (int k=0;k<m;k++)if (o&pw(k))s++,x=x*3+2;else if (a[k]==2||k&&(o&pw(k-1))||(k<m-1)&&(o&pw(k+1)))x=x*3;else x=x*3+1;
			f[i+1][x]=min(f[i+1][x],f[i][j]+s);
		}
	}
	for (int i=0;i<w;i++){
		int t=0,u=i;
		while (u){
			if (u%3==1)t=1;
			u/=3;
		}
		if (!t)ans=min(ans,f[n-1][i]);
	}
	CC(n*m-ans);
	return 0;
}