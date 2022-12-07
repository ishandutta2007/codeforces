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
#include<cassert>
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
int inf=1001001001;
int cal(int t){
	if(t%2==0){
		if(t<0 || t==2) return -inf;
		return t/4;
	}
	return 1+cal(t-9);
}
int main()
{
	int n,t;
	scanf("%d",&n);
	rep(i,n){
		scanf("%d",&t);
		int ret=cal(t);
		if(ret<0) printf("-1\n");
		else printf("%d\n",ret);
	}
}