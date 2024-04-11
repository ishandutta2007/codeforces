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
int ok[4],ng[4];
int main()
{
	int i,n,a,b,c;cin>>n;
	memset(ok,0,sizeof(ok));memset(ok,0,sizeof(ok));
	rep(i,n){
		scanf("%d %d %d",&a,&b,&c);
		ok[a]+=b;ng[a]+=c;
	}
	if(ok[1]>=ng[1]) cout<<"LIVE"<<endl;else cout<<"DEAD"<<endl;
	if(ok[2]>=ng[2]) cout<<"LIVE"<<endl;else cout<<"DEAD"<<endl;
	return 0;
}