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

string a,p,ans="";
int n,l,pp[333],f[333][333],pr[333][333];
char an[333][333];


int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n >> l >> a >> p;
	int o=a.size();
	a+='#';
	pp[0]=0;
	for (int i=1;i<=a.size();i++){
		int x=pp[i-1];
		while (x&&a[x]!=a[i])x=pp[x-1];
		if (a[x]==a[i])pp[i]=x+1;else pp[i]=0;
	}
	f[0][0]=1;
	for (int i=0;i<n;i++)for (int j=0;j<=a.size();j++)if (f[i][j]){
		for (char k='a';k<'a'+l;k++){
			int x=j,u;
			while (x&&a[x]!=k)x=pp[x-1];
			if (a[x]==k)u=x+1;else u=0;
			if ((u==o)!=(p[i-o+1]=='1'))continue;
			f[i+1][u]=1;
			pr[i+1][u]=j;
			an[i+1][u]=k;
		}
	}
	int oo=-1;
	for (int i=0;i<=a.size();i++)if (f[n][i])oo=i;
	if (oo<0){
		puts("No solution");
		return 0;
	}
	for (int i=n;i;i--){
		ans=an[i][oo]+ans;
		oo=pr[i][oo];
	}
	CC(ans);
	return 0;
}