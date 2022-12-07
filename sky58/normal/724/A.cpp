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
string we[7]={"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};
map<string,int> de;
int main()
{
	rep(i,7) de[we[i]]=i;
	string s,t;
	cin>>s;cin>>t;
	int a=de[s],b=de[t],c=(b+7-a)%7;
	if(c==0 || c==2 || c==3) cout<<"YES"<<endl;else cout<<"NO"<<endl;
}