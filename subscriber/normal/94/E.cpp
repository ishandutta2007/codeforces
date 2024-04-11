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

int a[44],o=6,n;
vector<pair<pair<int,int>,pair<int,int> > >cu,ans;

void rec(int x){
	 if (a[x-1]==n)o=x,ans=cu;
	 if (x>=o)return;
	 for (int i=0;i<x;i++)for (int j=0;j<x;j++)for (int l=0;l<4;l++){
	 	a[x]=a[i]+a[j]*pw(l);
	 	cu[x-1]=mp(mp(x,pw(l)),mp(i,j));
	 	rec(x+1);
	 }
	 for (int i=0;i<x;i++)for (int l=0;l<4;l++){
	 	a[x]=a[i]*pw(l);
	 	cu[x-1]=mp(mp(x,pw(l)),mp(i,-1));
	 	rec(x+1);
	 }
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cu.resize(10);
	cin >> n;
	a[0]=1;
	rec(1);
	CC(o-1);
	for (int i=0;i<o-1;i++){
	 	SS q;
	 	if (ans[i].S.S==-1){
	 		q<<"lea e"<<(char)('a'+ans[i].F.F)<<"x, ["<<ans[i].F.S<<"*e"<<(char)('a'+ans[i].S.F)<<"x]";
	 	}else
	 	q<<"lea e"<<(char)('a'+ans[i].F.F)<<"x, [e"<<(char)('a'+ans[i].S.F)<<"x + "<<ans[i].F.S<<"*e"<<(char)('a'+ans[i].S.S)<<"x]";
	 	cout << q.str() << endl;
	}
	return 0;
}