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
#define pw(x) (1ull<<(x))
#define M 1000000007
using namespace std;
typedef pair<int,int> pt;

long long n,x,y,q,l,r,c,h;

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n >> x >> y >> q;
	l=0;
	r=q;
	while (l<r){
		c=(l+r)/2;
		long long g=1+(c*4+4)*c/2;

		h=1-(x-c);
		if (h>0)g-=(2+(h-1)*2)*h/2;

		h=1-(y-c);
		if (h>0)g-=(2+(h-1)*2)*h/2;

		h=x+c-n;
		if (h>0)g-=(2+(h-1)*2)*h/2;

		h=y+c-n;
		if (h>0)g-=(2+(h-1)*2)*h/2;

		h=0-(x+y-1-c);
		if (h>0)g+=(1+h)*h/2;

		h=c-(x+n-y);
		if (h>0)g+=(1+h)*h/2;

		h=c-(y+n-x);
		if (h>0)g+=(1+h)*h/2;

		h=c-(n-x+n-y+1);
		if (h>0)g+=(1+h)*h/2;

		if (g>=q)r=c;else l=c+1;
	}
	CC(l);
	return 0;
}