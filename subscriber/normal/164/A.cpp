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

int n,m,t[111111],x,y,f1[111111],f2[111111];
vector<int>v[111111],vv[111111];

void rec1(int x){
	if (f1[x]||t[x]==1)return;
	f1[x]=1;
	for (int i=0;i<v[x].size();i++)rec1(v[x][i]);
}

void rec2(int x){
	if (f2[x]||t[x]==1)return;
	f2[x]=1;
	for (int i=0;i<vv[x].size();i++)rec2(vv[x][i]);
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n >> m;
	for (int i=0;i<n;i++)cin >> t[i];
	for (int i=0;i<m;i++){
		cin >> x >> y;
		x--;
		y--;
		v[x].pb(y);
		vv[y].pb(x);
	}
	for (int i=0;i<n;i++)if (t[i]==1)
	for (int j=0;j<v[i].size();j++)rec1(v[i][j]);
	for (int i=0;i<n;i++)if (t[i]==2)rec2(i);
	for (int i=0;i<n;i++){
		int t1=f1[i],t2=f2[i];
		if (t[i]==1)t1=1;
		for (int j=0;j<v[i].size();j++)if (f2[v[i][j]])t2=1;
		CC(t1+t2==2);
	}	
	return 0;
}