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
int a[2100],rsum[2100];
vector <int> u;
vector <int> pos[2100];
int main()
{
	int n,out=0;cin>>n;
	rep(i,n){
		cin>>a[i];a[i]=abs(a[i]);u.pb(a[i]);
	}
	sort(All(u));u.erase(unique(All(u)),u.end());int m=u.size();
	rep(i,n) a[i]=lower_bound(All(u),a[i])-u.begin();
	rep(i,n) pos[a[i]].pb(i);
	rep(i,m){
		//rep(j,pos[i].size()) cout<<pos[i][j]<<' ';cout<<endl;
		if(i>0){
			int sum=0,nsum=0,it=0;
			rep(j,n) sum+=rsum[j];
			rep(j,pos[i].size()){
				for(;it<pos[i][j];it++) nsum+=rsum[it];
				out+=min(nsum,sum-nsum);
			}
		}
		rep(j,pos[i].size()) rsum[pos[i][j]]++;
	}
	cout<<out<<endl;
	return 0;
}