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

int n,x,a[444],g[444][444],ans[444];

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin>> n;
	for (int i=0;i<n;i++)for (int j=0;j<n;j++){
		cin >> x;
		g[i][x-1]=j;
	}
	for (int i=0;i<n;i++){
		cin >> x;
		a[x-1]=i;
	}
	ans[0]=1;
	for (int i=0;i<n;i++){
		x=0;
		if (!i)x=1;
		for (int j=0;j<n;j++)if (i!=j){
			if (a[j]<a[x])x=j;
			if (g[i][x]<g[i][ans[i]])ans[i]=x;
		}
	}
	for (int i=0;i<n;i++)cout << ans[i]+1 << " ";
	return 0;
}