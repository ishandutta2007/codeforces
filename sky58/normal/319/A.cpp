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
int main()
{
	string s;
	cin>>s;int n=s.size();lint mo=1000000007,out=0;
	rep(i,n){
		if(s[i]=='0') continue;
		lint ze=1,on=1;
		rep(j,i) ze=(ze*2)%mo;
		REP(j,i+1,n) ze=(ze*4)%mo;
		out=(ze+out)%mo;
	}
	//on=((on*(on+mo-1))%mo*500000004)%mo;
	//cout<<(on*ze)%mo<<endl;
	cout<<out<<endl;
	return 0;
}