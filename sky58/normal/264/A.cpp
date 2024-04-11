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
int out[1100000];
int main()
{
	string s;cin>>s;
	int i,n=s.size(),le=0,ri=n-1;
	rep(i,n){
		if(s[i]=='l'){
			out[ri]=i+1;ri--;
		}
		else{
			out[le]=i+1;le++;
		}
	}
	rep(i,n) cout<<out[i]<<endl;
	return 0;
}