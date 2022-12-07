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

int n,x,y,ans=1e9,a[333333],b[333333],st;
map<int,int>w;

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n;
	for (int i=0;i<n;i++){
		scanf("%d%d",&x,&y);
		if (!w[x])w[x]=++st;
		if (!w[y])w[y]=++st;
		x=w[x];
		y=w[y];
		a[x]++;
		if (x!=y)b[y]++;
	}
	for (int i=1;i<=st;i++){
		if (a[i]>=(n+1)/2)ans=0;else
		if (a[i]+b[i]>=(n+1)/2)ans=min(ans,(n+1)/2-a[i]);
	}
	if (ans>1e8)puts("-1");else
	CC(ans);
	return 0;
}