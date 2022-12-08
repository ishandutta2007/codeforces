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
#define sqr(x) ((x)*1ll*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define SV(x) sort(x.begin(),x.end())
#define pw(x) (1ull<<(x))
using namespace std;
typedef pair<int,int> pt;
typedef vector<int> vt;
typedef unsigned long long UL;

int n,ai,aj,bi,bj;
long long ans=1e18;
pair<pt,pt>q[555555],t[555555];

bool gg(pair<pt,pt>a,pair<pt,pt>b){
	return a.F.S<b.F.S;
}

void check(pair<pt,pt>a,pair<pt,pt>b){
	if (a.S.F==b.S.F)return;
	long long x=sqr(a.F.F-b.F.F)+sqr(a.F.S-b.F.S);
	if (x<ans)ans=x,ai=a.S.F,aj=a.S.S,bi=b.S.F,bj=b.S.S^3;
}

void rec(int l,int r){
	if (r-l<=3){
		for (int i=l;i<=r;i++)for (int j=l;j<i;j++)check(q[i],q[j]);
		sort(q+l,q+r+1,&gg);
		return;
	}
	int g=(l+r)/2;
	int xx=q[g].F.F;
	rec(l,g);
	rec(g+1,r);
//	sort(q+l,q+r+1,&gg);
	inplace_merge(q+l,q+g+1,q+r+1,&gg);
	int k=0;
	for (int i=l;i<=r;i++)if (sqr(xx-q[i].F.F)<ans){
		for (int j=k-1;j>=0&&sqr(q[i].F.S-t[j].F.S)<ans;j--)check(q[i],t[j]);
		t[k++]=q[i];
	}

}


int main(){
	freopen("input.txt","r",stdin);	
	freopen("output.txt","w",stdout);	
	cin >> n;
	int nn=n;
	for (int i=0;i<n;i++)scanf("%d%d",&q[i].F.F,&q[i].F.S);
	for (int i=0;i<n;i++)q[i].S.F=i,q[i].S.S=0;
	for (int i=0;i<nn;i++)q[n++]=mp(mp(-q[i].F.F,q[i].F.S),mp(q[i].S.F,1));
	for (int i=0;i<nn;i++)q[n++]=mp(mp(q[i].F.F,-q[i].F.S),mp(q[i].S.F,2));
	for (int i=0;i<nn;i++)q[n++]=mp(mp(-q[i].F.F,-q[i].F.S),mp(q[i].S.F,3));
	sort(q,q+n);
	rec(0,n-1);
//	CC(ans);
	cout << ai+1 << " " << aj+1 << " " << bi+1 << " " << bj+1 << endl;
	return 0;
}