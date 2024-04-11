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
string ma[114];
int a[114];
int main()
{
	int n;
	vector<int> out;
	cin>>n;
	rep(i,n) cin>>ma[i];
	rep(i,n) cin>>a[i];
	while(1){
		int f=-1;
		rep(i,n){
			if(a[i]==0) f=i;
		}
		if(f<0) break;
		out.pb(f);
		rep(i,n) a[i]-=(ma[f][i]-'0');
	}
	int m=out.size();
	if(m>0) sort(All(out));
	cout<<m<<endl;
	rep(i,m){
		cout<<out[i]+1;
		if(i<m-1) cout<<' ';
	}
	cout<<endl;
}