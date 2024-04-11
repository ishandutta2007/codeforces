#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<cstdlib>
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
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
int main()
{
	int i,n,t,out=0;int a[110];
	cin>>n;
	if(n<3 || n%2==0){cout<<"-1"<<endl;return 0;}
	rep(i,n) cin>>a[i+1];
	for(i=n;i>0;i--){
		t=a[i];
		a[i/2]=max(0,a[i/2]-t);
		if(i%2>0) a[i-1]=max(0,a[i-1]-t);
		a[i]=0;
		out+=t;
	}
	cout<<out<<endl;
	return 0;
}