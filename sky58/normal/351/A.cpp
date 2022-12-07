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
vector <int> nu;
string moji(int a){
	string ret="";string r="";int amari;
	if(a==0) return "0";if(a<0) return "-"+moji(-a);
	while(a>0){
		amari=a%10;r+=(amari+'0');a/=10;
	}
	for(int i=0;i<r.size();i++) ret+=r[r.size()-(i+1)];
	return ret;
}
int main()
{
	int out=100000000,n,x,y,m=0,sum=0;char c;
	cin>>n;
	rep(i,n*2){
		cin>>x>>c>>y;
		if(y>0){nu.pb(y);m++;}
		//cout<<x<<' '<<y<<endl;
	}
	sort(All(nu));
	/*rep(i,m+1){
		if(i>n || m-i>n) continue;
		int sum=0;
		rep(j,i) sum+=nu[j];
		REP(j,i,m) sum-=1000-nu[j];
		if(out>abs(sum)) out=abs(sum);
	}*/
	rep(i,m) sum+=nu[i];
	
	rep(i,m+1){
		if(i>n || m-i>n) continue;
		out=min(out,abs(sum-1000*i));
	}
	
	//sum%=1000;
	//out=min(sum,1000-sum);
	string ret=moji(out%1000);
	while(ret.size()<3) ret="0"+ret;
	cout<<moji(out/1000)<<"."<<ret<<endl;
	return 0;
}