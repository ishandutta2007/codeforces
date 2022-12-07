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

long long t1,t2,x1,x2,tt,l,r,c,a1,a2,ans=2e12,sa;

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> t1 >> t2 >> x1 >> x2 >> tt;
	for (int i=0;i<=x1;i++){
		l=0;
		r=x2;
		while (l<r){
			c=(l+r)/2;
			if (i==0||t1==t2||(i*t1+c*t2)<tt*(i+c))l=c+1;else r=c;
		}	
		if ((i*t1+l*t2)<tt*(i+l))continue;
		if ((i*t1+l*t2)*sa<ans*(i+l)||(i*t1+l*t2)*sa==ans*(i+l)&&i+l>sa)a1=i,a2=l,ans=(i*t1+l*t2),sa=i+l;
	}
	cout << a1 << " " << a2 << endl;
	return 0;
}