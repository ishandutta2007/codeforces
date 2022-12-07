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

int l,r,k=0;
long long a[111111];
long long ans=0;

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> l >> r;
	a[k++]=4;
	a[k++]=7;
	for (int i=0;i<k;i++)if (a[i]<1e9)a[k++]=a[i]*10+4,a[k++]=a[i]*10+7;
	sort(a,a+k);
	for (int i=0;i<k;i++)if (a[i]>=l){
		long long x=l;
		long long y=r;
		if (i)x=max(x,a[i-1]+1);
		y=min(y,a[i]);
		ans+=a[i]*1ll*(y-x+1);
		if (a[i]>r)break;
	}		
	CC(ans);
	return 0;
}