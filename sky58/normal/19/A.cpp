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
typedef long long lint;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
vector <int> cl;
vector <string> na;
map<string,int> de;
string te1(string a){
	string ret;
	for(int i=0;i<a.size();i++){
		if(a[i]=='-') break;ret+=a[i];
	}
	return ret;
}
string te2(string a){
	reverse(a.begin(),a.end());
	string ret;
	for(int i=0;i<a.size();i++){
		if(a[i]=='-') break;ret+=a[i];
	}
	reverse(ret.begin(),ret.end());
	return ret;
}
int sc1(string a){
	int i,t=0;
	for(i=0;i<a.size();i++){
		if(a[i]==':') break;t*=10;t+=(a[i]-'0');
	}
	return t;
}
int sc2(string a){
	reverse(a.begin(),a.end());
	int i,t=0,s=1;
	for(i=0;i<a.size();i++){
		if(a[i]==':') break;t+=(a[i]-'0')*s;s*=10;
	}
	return t;
}
int main()
{
	int i,n;string s,t;vector <string> out;vector <vector <int> > te;
	cin>>n;
	for(i=0;i<4;i++) cl.pb(0);
	for(i=0;i<n;i++) te.pb(cl);
	for(i=0;i<n;i++) te[i][3]=i;
	for(i=0;i<n;i++){
		cin>>s;na.pb(s);de[s]=i;
	}
	for(i=0;i<n*(n-1)/2;i++){
		cin>>s>>t;
		int t1=de[te1(s)],t2=de[te2(s)],s1=sc1(t),s2=sc2(t);
		if(s1>s2) te[t1][0]+=3;if(s1<s2) te[t2][0]+=3;
		if(s1==s2){te[t1][0]++;te[t2][0]++;}
		te[t1][1]+=(s1-s2);te[t1][2]+=s1;
		te[t2][1]-=(s1-s2);te[t2][2]+=s2;
	}
	sort(te.begin(),te.end());reverse(te.begin(),te.end());
	for(i=0;i<n/2;i++) out.pb(na[te[i][3]]);sort(out.begin(),out.end());
	for(i=0;i<out.size();i++) cout<<out[i]<<endl;
	return 0;
}