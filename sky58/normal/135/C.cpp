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
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
string out[4]={"00","01","10","11"};
bool ret[5];
int main()
{
	memset(ret,false,sizeof(ret));string s;
	cin>>s;int n=s.size(),i,on=0,ze=0,qu=0;
	rep(i,n){
		if(s[i]=='0') ze++;
		if(s[i]=='1') on++;
		if(s[i]=='?') qu++;
	}
	if(n%2>0){
		if(ze+qu>on) ret[0]=true;
		if(ze+2<on+qu) ret[3]=true;
		if(ze<on+qu && ze+2+qu>on){
			ret[1]=ret[2]=true;
			if(s[n-1]=='0') ret[1]=false;
			else if(s[n-1]=='1') ret[2]=false;
			else{
				if(ze+qu+1==on) ret[1]=false;
				if(ze+1==on+qu) ret[2]=false;
			}
//			if(ze+qu<1) ret[1]=ret[2]=false;
		}
	}
	else{
		if(ze+qu>on) ret[0]=true;
		if(ze<on+qu) ret[3]=true;
		if(ze<=on+qu && ze+qu>=on){
			ret[1]=ret[2]=true;
			if(s[n-1]=='0') ret[1]=false;
			else if(s[n-1]=='1') ret[2]=false;
			else{
				if(ze+qu==on) ret[1]=false;
				if(ze==on+qu) ret[2]=false;
			}
		}
	}
	rep(i,4){
		if(ret[i]) cout<<out[i]<<endl;
	}
	return 0;
}