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

int n,k,b,g,kk,ans;
long double q[111111];

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n;
	for (int i=0;i<n;i++){
		cin >> k >> b;
		if (k==0)continue;
		q[kk++]=-b/(long double)k;
	}
	sort(q,q+kk);
	ans=kk>0;
	for (int i=1;i<kk;i++)if (fabs(q[i-1]-q[i])>1e-19)ans++;
	CC(ans);
	return 0;
}