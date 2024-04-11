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
	string s,out="";int i;cin>>s;
	if(s.substr(0,3)=="ftp"){
		out+="ftp://";s=s.substr(3);
	}
	else if(s.substr(0,4)=="http"){
		out+="http://";s=s.substr(4);
	}
	REP(i,1,s.size()-1){
		if(s.substr(i,2)=="ru"){
			out+=s.substr(0,i);out+=".ru";
			if(i+2<s.size()){
				out+="/";out+=s.substr(i+2);
			}
			cout<<out<<endl;break;
		}
	}
	return 0;
}