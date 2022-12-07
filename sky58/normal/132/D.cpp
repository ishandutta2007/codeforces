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
using namespace std;
#define pb push_back
#define pf push_front
typedef long long lint;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
int main()
{
	string s;int i=0;vector <int> out;
	cin>>s;reverse(s.begin(),s.end());s+="000";
	while(i<s.size()){
		if(s[i]=='1'){
			if(s[i+1]=='0'){
				out.pb(i+1);i++;
			}
			else{
				out.pb(-i-1);
				while(s[i]=='1') i++;
				s[i]='1';
			}
		}
		else i++;
	}
	cout<<out.size()<<endl;
	rep(i,out.size()){
		if(out[i]>0) printf("+2^%d\n",out[i]-1);
		else printf("-2^%d\n",-out[i]-1);
	}
	return 0;
}