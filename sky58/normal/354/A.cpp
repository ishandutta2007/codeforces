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
int a[100010],sum[100010];
int main()
{
	int n,l,r,ql,qr,out=2000001000;
	cin>>n>>l>>r>>ql>>qr;
	rep(i,n){
		cin>>a[i];
		sum[i+1]=sum[i]+a[i];
	}
	rep(i,n+1){
		int t=l*sum[i]+r*(sum[n]-sum[i]),j=n-i;
		if(i>j+1) t+=ql*(i-j-1);
		if(j>i+1) t+=qr*(j-i-1);
		out=min(out,t);
	}
	cout<<out<<endl;
}