#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#define mp make_pair
#define pb push_back
#define F first
#define S second
using namespace std;

int n,d,S,cc[111111],f[111111],le[111111],l,r,c,ca,no,ans,aa,ff;
long long fu;
vector<int>ee,gg;
vector<pair<int,int> >e;

int ss(int l){
	fu=0;
	ans=0;
	ca=0;
	for (int i=0;i<l;i++){
		if (fu+e[i].F>S){
			l=i;
			break;
		}
		ca+=e[i].S,ans++,fu+=e[i].F;
	}
	gg=ee;
	for (int i=l;i<e.size();i++)gg.pb(e[i].S);
	sort(gg.rbegin(),gg.rend());
	for (int i=0;i<gg.size();i++)if (!ca)break;else ca+=gg[i]-1,ans++;
	return ans;
}

void sol(){
	l=0;
	r=e.size();
	int ma=ss(r);
	while (l<r){
		c=(l+r)/2;
		if (ss(c)<ma)l=c+1;else r=c;
	}
	fu=0;
	for (int i=0;i<l;i++)fu+=e[i].F;
	if (ma>aa||ma==aa&&fu<ff)aa=ma,ff=fu;
}

int main(){
	cin >> n >> d >> S;
	for (int i=0;i<n;i++)scanf("%d%d%d",&cc[i],&f[i],&le[i]);
	for (int i=0;i<n;i++)if (le[i]>=d)e.pb(mp(f[i],cc[i]));else ee.pb(cc[i]);
	sort(e.begin(),e.end());
	sol();
	for (int i=0;i<e.size();i++)if (e[i].S>0){
		swap(e[0],e[i]);
		sort(e.begin()+1,e.end());
		sol();
		break;		
	}
	cout << aa << " " << ff << endl;
	return 0;
}