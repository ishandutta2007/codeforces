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
using namespace std;
typedef pair<int,int> pt;
typedef vector<int> vt;

int n,m,x,y,p[3333333],w[3333333],ww[3333333],e,s;
long long ans=0;
vector<int>v[1111111];


int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n >> m;
	for (int i=0;i<m;i++){
		scanf("%d%d",&x,&y);
		x--;
		y--;
		v[x].pb(y);
		v[y].pb(x);
	}
	m0(p);
	for (int i=0;i<n;i++){
		for (int j=0;j<v[i].size();j++){
			if (w[p[v[i][j]]]!=i+1){
				s++;
				w[p[v[i][j]]]=i+1;
				ww[p[v[i][j]]]=s;
				p[v[i][j]]=s;
			}else p[v[i][j]]=ww[p[v[i][j]]];
		}
	}
	sort(p,p+n);
	e=1;
	for (int i=1;i<n;i++)if (p[i]!=p[i-1]){
		ans+=e*1ll*(e-1)/2;
		e=1;
	}else e++;
	ans+=e*1ll*(e-1)/2;
	m0(p);
	s=0;
	m0(w);
	for (int i=0;i<n;i++)v[i].pb(i);
	for (int i=0;i<n;i++)p[i]=0;
	for (int i=0;i<n;i++){
		for (int j=0;j<v[i].size();j++){
			if (w[p[v[i][j]]]!=i+1){
				s++;
				w[p[v[i][j]]]=i+1;
				ww[p[v[i][j]]]=s;
				p[v[i][j]]=s;
			}else p[v[i][j]]=ww[p[v[i][j]]];
		}
	}
	sort(p,p+n);
	e=1;
	for (int i=1;i<n;i++)if (p[i]!=p[i-1]){
		ans+=e*1ll*(e-1)/2;
		e=1;
	}else e++;
	ans+=e*1ll*(e-1)/2;
	CC(ans);
	return 0;
}