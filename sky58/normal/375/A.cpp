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
int dig[10];
string d="0123456789";
int main()
{
	string s,a="1689",ret="";
	cin>>s;
	int n=s.size();
	rep(i,n) dig[(s[i]-'0')]++;
	dig[1]--;dig[6]--;dig[8]--;dig[9]--;
	int sum=0,zyo=1;
	rep(i,10) rep(j,dig[i]){
		ret+=d[i];sum=(sum+i*zyo)%7;zyo=(zyo*10)%7;
	}
	while(1){
		int t=0;
		rep(i,4) t=t*10+(a[i]-'0');
		if((sum+t*zyo)%7==0){
			reverse(All(ret));cout<<a<<ret<<endl;return 0;
		}
		if(!next_permutation(All(a))) break;
	}
	cout<<0<<endl;
}