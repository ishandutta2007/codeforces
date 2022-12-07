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

int n,k,d[111111],c[111111];
long long s,tt,p;

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n >> k;
	for (int i=0;i<n;i++)cin >> d[i];
	for (int i=0;i<n;i++)cin >> c[i];
	s=c[0];
	tt=0;
	p=c[0];
	for (int i=1;i<=n;i++){
		s-=d[i-1];
		tt+=d[i-1];
		while (s<0)s+=p,tt+=k;
		s+=c[i];
		if (c[i]>p)p=c[i];		
	}
	CC(tt);
	return 0;
}