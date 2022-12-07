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

int n,s,x,y,l1=0,l2=0;
vector<pt> a,b;
vector<long long>aa,bb;
long long o,ans=0;

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n >> s;
	for (int i=0;i<n;i++){
		scanf("%d%d",&x,&y);
		if (x==1)a.pb(mp(y,i));else b.pb(mp(y,i));
	}
	sort(a.rbegin(),a.rend());
	sort(b.rbegin(),b.rend());
	if (a.size())aa.pb(a[0].F);
	for (int i=1;i<a.size();i++)aa.pb(aa[i-1]+a[i].F);
	if (b.size())bb.pb(b[0].F);
	for (int i=1;i<b.size();i++)bb.pb(bb[i-1]+b[i].F);
	for (int i=0;i<=b.size();i++){
		o=0;
		if (i)o+=bb[i-1];
		x=s-i-i;
		x=min(x,(int)a.size());
		if (x<0)continue;
		if (x>0)o+=aa[x-1];
		if (o>ans)ans=o,l2=i,l1=x;
	}
	CC(ans);
	for (int i=0;i<l1;i++)CC(a[i].S+1);
	for (int i=0;i<l2;i++)CC(b[i].S+1);
	return 0;
}