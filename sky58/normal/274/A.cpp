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
map<lint,int> me;
vector <int> a;
int main()
{
	int i,n,k,out=0,b;
	cin>>n>>k;//out=n;
	rep(i,n){scanf("%d",&b);a.pb(b);}
	sort(All(a));
	rep(i,n) me[(lint)a[i]]++;
	if(k<2){cout<<n<<endl;return 0;}
	rep(i,n){
		if(me[a[i]]<1) continue;
		lint t=a[i];int co=0;
		while(t<2000000000){
			if(me[t]<1) break;me[t]=0;co++;t*=k;
		}
		out+=(co+1)/2;
	}
	cout<<out<<endl;
	return 0;
}