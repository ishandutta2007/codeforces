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

long long a,b,x;
long long A[5000555],B[5000555];
int k,g;

long long ge(long long x){
	if (b-x<4000444)return B[b-x];
	return A[x-a];
}

long long iz(long long x,long long v){
	if (b-x<4000444)B[b-x]=v;else
	A[x-a]=v;
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> b >> a >> k;
	int g=1;
	for (int i=2;i<=k;i++)g=g*i/__gcd(i,g);
	x=b;
	while (x>a){
		long long fx=ge(x);
		if (x%g==0&&x+g<=b&&x-g>=a){
			long long t=x-(x-a)/g*g;
			long long v=fx+(x-a)/g*(fx-ge(x+g));
			if (ge(t)==0)iz(t,v);else iz(t,min(ge(t),v));
			x=t;
			continue;
		}
		if (ge(x-1)==0)iz(x-1,fx+1);else iz(x-1,min(ge(x-1),fx+1));
		for (int i=2;i<=k;i++){
			long long t=x-x%i;
			if (t==x)continue;
			if (ge(t)==0)iz(t,fx+1);else iz(t,min(ge(t),fx+1));
		}
		x--;
	}
	CC(ge(a));
	return 0;
}