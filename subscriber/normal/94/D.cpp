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


int n,m,w,e=0;
double s=0,t,q,g[55];
vector<pair<int,double> >an[55];

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n >> w >> m;
	t=n*w/1./m;
	for (int i=0;i<n;i++){
		q=w;
		int u=0;
		while (q>1e-11){
			double l=min(t-g[e],q);
			if (l>1e-11)an[e].pb(mp(i,l)),u++;
			g[e]+=l;
			q-=l;
			if (fabs(t-g[e])<1e-11)e++;
		}
		if (u>2){
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	cout.precision(7);
	for (int i=0;i<m;i++){
		for (int j=0;j<an[i].size();j++){
			cout << an[i][j].F+1 << " " << fixed << an[i][j].S << " ";
		}	
		puts("");
	}
	return 0;
}