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

int n,a[222222],k,e[222222],u[222222];
long long r,w,ans;

long long pv(long long a,long long b){
	if (b==0)return 1;
	long long r=pv(a,b/2);
	r=r*r%M;
	if (b%2)r=r*a%M;
	return r;
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n;
	for (int i=0;i<n;i++)cin >> a[i];
	sort(a,a+n);
	for (int y=1;y<=100000;y++){
		k=0;
		for (int j=1;j*j<=y;j++)if (y%j==0){
			e[k++]=j;
			if (j*j!=y)e[k++]=y/j;
		}
		sort(e,e+k);
		for (int j=0;j<k;j++)u[j]=lower_bound(a,a+n,e[j])-a;
		if (u[k-1]==n)continue;
		r=1;
		for (int j=0;j<k-1;j++)r=r*pv(j+1,u[j+1]-u[j])%M;
		w=pv(k,n-u[k-1]);
		w=(w-pv(k-1,n-u[k-1])+M)%M;
		ans=(ans+r*w)%M;
	}
	CC(ans);
	return 0;
}