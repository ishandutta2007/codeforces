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
map<int,int> me;
int main()
{
	int n,a,f=0,ret=0;
	cin>>n;
	rep(i,n){
		cin>>a;me[a]++;
	}
	map<int,int>::iterator it = me.begin();
	while( it != me.end() )
	{
		if((*it).first>0){
			if((*it).second>2) f=1;
			ret+=(*it).second/2;
		}
		it++;
	}
	if(f>0) cout<<-1<<endl;
	else cout<<ret<<endl;
	return 0;
}