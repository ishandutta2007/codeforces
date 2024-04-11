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


int n,R,r,k1,k2;
double g,ss;

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n >> R >> r;
	if (r+r>R){
		if (r>R||n>1)puts("NO");else puts("YES");
		return 0;
	}
	k1=r;
	k2=R-r;
	ss=k1/1./k2;
	ss=asin(ss)*2;
	if (ss*n<acos(-1)*2+1e-8)puts("YES");else puts("NO");
	return 0;
}