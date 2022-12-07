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

int n,m,p[555555],u[555555],s[555555],ans[555555],x,y;
vector<int>v[555555],za[555555],an[555555];

void add(int x){
	while (x<=n){
		s[x]++;
		x=x+x-(x&(x-1));
	}
}

int find(int x){
	int r=0;
	while (x){
		r+=s[x];
		x&=x-1;
	}
	return r;
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n >> m;
	for (int i=0;i<n;i++)scanf("%d",&p[i]),u[p[i]]=i+1;
	for (int i=1;i<=n;i++){
		int j=i;
		while (j<=n){
			v[max(u[i],u[j])].pb(min(u[i],u[j]));
			j+=i;
		}
	}
	for (int i=0;i<m;i++){
		scanf("%d%d",&x,&y);
		za[y].pb(x);
		an[y].pb(i);
	}
	for (int i=1;i<=n;i++){
		for (int j=0;j<v[i].size();j++)add(v[i][j]);
		for (int j=0;j<za[i].size();j++)ans[an[i][j]]=find(n)-find(za[i][j]-1);
	}
	for (int i=0;i<m;i++)printf("%d\n",ans[i]);
	return 0;
}