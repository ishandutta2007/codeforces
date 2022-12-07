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

int k,n,x,y,f[111],mm,ans=0;
vt v[111];

void rec(int x,int d){
	if (f[x])return;
	f[x]=1;
	mm=max(mm,d);
	for (int i=0;i<v[x].size();i++)rec(v[x][i],d+1);
}

int main(){
	freopen("input.txt","r",stdin);	
	freopen("output.txt","w",stdout);	
	cin >> k;
	for (int i=0;i<k;i++){
		cin >> n;
		for (int j=0;j<n;j++)v[j].clear();
		for (int j=0;j<n-1;j++){
			cin >> x >> y;
			x--;
			y--;
			v[x].pb(y);
			v[y].pb(x);
			
		}
		mm=0;
		for (int i=0;i<n;i++){
			m0(f);
			rec(i,0);
		}
		ans+=mm;
	}
	CC(ans);
	return 0;
}