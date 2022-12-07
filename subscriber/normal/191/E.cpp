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
                             
int n,a[111111],e,ss[111111],u[111111];
long long k,s[111111],ee[111111],l,r,c;
pair<long long,int>q[111111];

void add(int x){
	while (x<=e){
		ss[x]++;
		x=x+x-(x&(x-1));
	}
}

int find(int x){
	int r=0;
	while (x){
		r+=ss[x];
		x&=x-1;
	}
	return r;
}

bool oo(long long h){
	long long w=0;
	m0(ss);
	for (int i=0;i<=n;i++){
		long long g=h-s[i];
		int x=lower_bound(ee+1,ee+e+1,g)-ee;
		w+=find(e)-find(x-1);
		add(u[i]);
	}
	return w>=k;
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n >> k;
	for (int i=0;i<n;i++)cin >> a[i];
	for (int i=0;i<n;i++)s[i+1]=s[i]+a[i];
	for (int i=0;i<=n;i++)q[i]=mp(-s[i],i);
	sort(q,q+n+1);
	for (int i=0;i<=n;i++){
		if (i==0||q[i-1].F!=q[i].F)e++;
		ee[e]=q[i].F;
		u[q[i].S]=e;
	}
	l=-1e17;
	r=1e17;
	while (l<r){
		if (r-l<10){
			for (long long i=r;i>=l;i--)if (oo(i)){
				CC(i);
				return 0;
			}
		}
		c=(l+r)/2;
		if (oo(c))l=c;else r=c;
	}
	return 0;
}