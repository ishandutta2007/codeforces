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
using namespace std;
typedef pair<int,int> pt;
typedef vector<int> vt;
#define M 1000000007

int n,m,k;

long long pv(long long a,long long b){
	if (!b)return 1;
	long long r=pv(a,b/2);
	r=r*r%M;
	if (b%2)r=r*a%M;
	return r;
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n >> m >> k;
	if (n<k||k==1)CC(pv(m,n));else
	if (n==k)CC(pv(m,(n+1)/2));else
	if (k%2)CC(m*m);else CC(m);
	return 0;
}