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
lint c[1100][1100];
lint sun[1100],sum[1100];
lint zyo(lint a){return a*a;}
int main()
{
	int i,j,n,m;
	lint outn=0,outm=0,minm=8000000000000000000LL,minn=minm;
	cin>>n>>m;
	rep(i,1100) sun[i]=sum[i]=0;
	rep(i,n) rep(j,m){
		scanf("%d",&c[i][j]);
		sun[i]+=c[i][j];sum[j]+=c[i][j];
	}
	rep(i,n+1){
		lint t=0;
		rep(j,n) t+=zyo(j*4+2-i*4)*sun[j];
		if(t<minn){minn=t;outn=i;}
	}
	rep(i,m+1){
		lint t=0;
		rep(j,m) t+=zyo(j*4+2-i*4)*sum[j];
		if(t<minm){minm=t;outm=i;}
	}
	cout<<minm+minn<<endl;
	cout<<outn<<' '<<outm<<endl;
	return 0;
}