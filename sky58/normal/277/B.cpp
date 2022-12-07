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
	int i,n,m;
	cin>>n>>m;
	if(m==3){
		if(n==3){
			cout<<"0 0"<<endl;
			cout<<"1 0"<<endl;
			cout<<"0 1"<<endl;
		}
		if(n==4){
			cout<<"0 0"<<endl;
			cout<<"3 0"<<endl;
			cout<<"0 3"<<endl;
			cout<<"1 1"<<endl;
		}
		if(n>4){
			cout<<"-1"<<endl;
		}
		return 0;
	}
	rep(i,m) cout<<i<<' '<<100000+i*i<<endl;
	rep(i,n-m) cout<<i<<' '<<-100000-i*i<<endl;
	return 0;
}