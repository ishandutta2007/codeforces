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


int n,a[55],b[55],s;
long double l,r,c,q;

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n >> s;
	for (int i=0;i<n;i++)cin >>a[i];
	for (int i=0;i<n;i++)cin >> b[i];
	l=0;
	r=1e9;
	while (r-l>1e-7){
		c=(l+r)/2;
		q=0;
		for (int i=0;i<n;i++)if (a[i]*c>b[i])q+=s+1;else q+=a[i]*c;
		if (q>s)r=c;else l=c;
	}
	q=0;
	for (int i=0;i<n;i++)q+=a[i]*l;
	cout.precision(5);
	cout<<fixed << q << endl;
	return 0;
}