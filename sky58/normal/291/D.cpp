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
int ret[25][11000];
int main()
{
	int n,k;
	cin>>n>>k;
	rep(i,k){
		int s=min(n,(1<<i)+1),t=min(n,(1<<(i+1))+1);
		rep(j,s) ret[i][j]=0;
		REP(j,s,t) ret[i][j]=j-(1<<i);
		REP(j,t,n) ret[i][j]=(1<<i);
	}
	rep(i,k) rep(j,n){
		cout<<n-ret[i][n-j-1];
		if(j<n-1) cout<<' ';else cout<<endl;
	}
	return 0;
}