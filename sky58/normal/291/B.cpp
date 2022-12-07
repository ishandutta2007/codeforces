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
bool bad(char a){
	if(a<='z' && a>='a') return false;
	if(a<='9' && a>='0') return false;
	if(a<='Z' && a>='A') return false;
	if(a=='?' || a=='!' || a=='.' || a==',' || a=='"') return false;
	return true;
}
int main()
{
	string now="",s;int f=0;vector <string> ret;
	getline(cin,s);
	rep(i,s.size()){if(bad(s[i])) s[i]=' ';}s+=' ';
	rep(i,s.size()){
		if(f==2){
			if(s[i]==' '){ret.pb(now);f=0;now="";}
			else now+=s[i];
		}
		else if(f==1){
			if(s[i]=='"'){ret.pb(now);f=0;now="";}
			else now+=s[i];
		}
		else{
			if(s[i]=='"') f=1;
			else if(s[i]!=' '){f=2;now+=s[i];}
		}
	}
	//cout<<ret.size()<<endl;cout<<ret[ret.size()-1]<<endl;
	rep(i,ret.size()) cout<<"<"<<ret[i]<<">"<<endl;
	return 0;
}