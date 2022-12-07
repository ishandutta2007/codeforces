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

int n,l,x,a[333333],y,s,k;
double v1,v2,d,r,ans[111111];

pair<double,int> w[433333];

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n >> l >> v1 >> v2;
	d=l*v2/(v1+v2);
	for (int i=0;i<n;i++)cin >> a[i];
	for (int i=0;i<n;i++){
		w[k++]=mp(a[i],1);
		if (a[i]+d>l+l){
			w[k++]=mp(l+l,-1);
			w[k++]=mp(0,1);
			w[k++]=mp(a[i]+d-l-l,-1);
		}else w[k++]=mp(a[i]+d,-1);
	}
	sort(w,w+k);
	for (int i=0;i<k;i++){
		if (s)ans[s]+=(w[i].F-w[i-1].F)/(l+l);
		if (w[i].S==1)s++;else s--;
	}
	ans[0]=1;
	for (int i=1;i<=n;i++)ans[0]-=ans[i];
	cout.precision(20);
	for (int i=0;i<=n;i++)CC(ans[i]);
	return 0;
}