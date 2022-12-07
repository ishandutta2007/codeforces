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

int n,m,a,b,ms[111][111],d[111],w[111],dd[111];
double f[111],ff[111],ans;

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n >> m;
	m1(ms);
	for (int i=0;i<m;i++){
		cin >> a >> b;
		a--;
		b--;
		ms[a][b]=ms[b][a]=1;
	}
	m1(d);
	d[0]=0;
	f[0]=1;
	m0(w);
	for (int i=0;i<n;i++){
		int o=1e9,l;
		for (int i=0;i<n;i++)if (!w[i]&&d[i]<o)o=d[i],l=i;
		w[l]=1;
		for (int i=0;i<n;i++)if (o+ms[l][i]<d[i]){
			d[i]=o+ms[l][i];
			f[i]=f[l];
		}else if (o+ms[l][i]==d[i])f[i]+=f[l];
	}

	m1(dd);
	dd[n-1]=0;
	ff[n-1]=1;
	m0(w);
	for (int i=0;i<n;i++){
		int o=1e9,l;
		for (int i=0;i<n;i++)if (!w[i]&&dd[i]<o)o=dd[i],l=i;
		w[l]=1;
		for (int i=0;i<n;i++)if (o+ms[l][i]<dd[i]){
			dd[i]=o+ms[l][i];
			ff[i]=ff[l];
		}else if (o+ms[l][i]==dd[i])ff[i]+=ff[l];
	}
	for (int i=0;i<n;i++){
		double o=0;
		for (int j=0;j<n;j++)
		if (ms[i][j]==1){
			if (d[i]+1+dd[j]==d[n-1])o+=f[i]*ff[j];
			if (dd[i]+1+d[j]==d[n-1])o+=ff[i]*f[j];
		}
		ans=max(ans,o);
	}
	printf("%.10lf\n",ans/f[n-1]);
	return 0;
}