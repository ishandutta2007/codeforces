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

int n,k,x,o,aa,bb,z,an[111111];
vector<pt>a,b;
vector<int>v[1111111];
long long ans=0;

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n >> k;
	for (int i=0;i<n;i++){
		cin >> x >> o;
		ans+=x+x;
		if (o==1)a.pb(mp(x,i));else b.pb(mp(x,i));
	}
	sort(AL(a));
	sort(AL(b));
	aa=a.size();
	bb=b.size();
	for (int i=0;i<min(aa,k);i++)ans-=a[aa-i-1].F;
	if (k<=aa){
		ans+=a[aa-k].F;
		int h=1e9;
		for (int i=0;i<bb;i++)h=min(h,b[i].F);
		for (int i=0;i<=aa-k;i++)h=min(h,a[i].F);
		ans-=h;
	}
	for (int i=aa-1;i>=0;i--){
		if (z<k)z++;
		an[a[i].S]=z;
	}
	for (int i=bb-1;i>=0;i--){
		if (z<k)z++;
		an[b[i].S]=z;
	}

	for (int i=0;i<n;i++)v[an[i]-1].pb(i+1);
	cout << ans/2;
	if (ans%2)puts(".5");else puts(".0");
	for (int i=0;i<k;i++){
		cout << v[i].size() << " ";
		for (int j=0;j<v[i].size()-1;j++)cout << v[i][j] << " ";
		CC(v[i][v[i].size()-1]);
	}
	return 0;
}