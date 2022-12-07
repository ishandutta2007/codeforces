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
	string s="",s2;
	while(cin>>s2){s+=s2;s+=' ';}
	int i,j,n=s.size()-1,pre=0;
	rep(i,n){
		int t=0,u=s[i];
		rep(j,8){
			t=t*2+u%2;u/=2;
		}
		cout<<(pre+256-t)%256<<endl;pre=t;
	}
	return 0;
}