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
int numw[514514];
string s;
int n,a,b,T;
bool cal(int mi){
	rep(i,mi){
		lint w=numw[i+1]+numw[n]-numw[n+i+1-mi];
		lint t=mi-1;if(i>0 && i<mi-1) t+=min(i,mi-i-1);
		//if(mi==3) cout<<i<<' '<<w<<' '<<t<<endl;
		if(w*b+t*a+mi<=(lint)T) return true;
	}
	return false;
}
int main()
{
	cin>>n>>a>>b>>T;cin>>s;
	memset(numw,0,sizeof(numw));
	rep(i,n){
		numw[i+1]=numw[i];
		if(s[i]=='w') numw[i+1]++;
	}
	int lo=0,hi=n;
	while(hi>lo){
		int mi=(hi+lo+1)/2;
		if(cal(mi)) lo=mi;else hi=mi-1;
	}
	cout<<lo<<endl;
}