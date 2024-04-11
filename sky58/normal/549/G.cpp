#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<ctime>
#include<queue>
#include<deque>
#include<complex>
using namespace std;
#define pb push_back
#define pf push_front
typedef long long lint;
typedef complex<double> P;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
int a[252521];
int main()
{
	int n,f=0;
	scanf("%d",&n);
	rep(i,n) scanf("%d",&a[i]);
	rep(i,n) a[i]-=n-1-i;
	sort(a,a+n);
	rep(i,n) a[i]+=n-1-i;
	rep(i,n-1){
		if(a[i+1]<a[i]) f=1;
	}
	if(f>0) cout<<":("<<endl;
	else{
		rep(i,n-1) cout<<a[i]<<' ';
		cout<<a[n-1]<<endl;
	}
}