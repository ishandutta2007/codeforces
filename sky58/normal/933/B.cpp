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
vector<lint> out;
map<lint,int> ma;
int main()
{
	lint p,k;
	cin>>p;cin>>k;
	ma[p]=1;
	if(p<k){
		cout<<1<<endl;
		cout<<p<<endl;
		return 0;
	}
	while(1){
		lint a;
		if(p>=0) a=-p/k;else a=(-p+k-1)/k;
		out.pb(p+a*k);p=a;
		/*if(ma[p]>0){
			cout<<-1<<endl;return 0;
		}*/
		if(p==0){
			cout<<-1<<endl;return 0;
		}
		ma[p]++;
		if(p<(lint)k && p>0LL) break;
	}
	out.pb(p);
	int n=out.size();
	cout<<n<<endl;
	rep(i,n){
		if(i<n-1) cout<<out[i]<<' ';else cout<<out[i]<<endl;
	}
}