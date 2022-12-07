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
string out[1100];
string bi(int a,int b){
	string ret="";
	for(int i=0;i<a;i++){
		ret+=((b%2)+'0');b/=2;
	}
	if(b>0) return "a";
	reverse(ret.begin(),ret.end());return ret;
}
string de(string a){
	if(a=="") return "";
	int t,i,n=a.size();
	for(t=n-1;t>=0;t--){
		if(a[t]=='0') break;
	}
	if(t<0) return "a";
	a[t]='1';for(i=t+1;i<n;i++) a[i]='0';return a;
}
int main()
{
	int i,n,a,j;string tmp;
	vector <string> ret;ret.pb("");vector <pint> in;in.pb(mp(0,-1));
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a;in.pb(mp(a,i));
	}
//	cout<<de("11111111")<<endl;
	sort(in.begin(),in.end());
	for(i=1;i<=n;i++){
		if(in[i].fi!=in[i-1].fi){
			tmp=de(ret[i-1]);if(tmp=="a"){cout<<"NO"<<endl;return 0;}
			for(j=0;j<in[i].fi-in[i-1].fi;j++) tmp+='0';ret.pb(tmp);
		}
		else{
			tmp=de(ret[i-1]);if(tmp=="a"){cout<<"NO"<<endl;return 0;}ret.pb(tmp);
		}
//		string ne=bi(in[i].fi-tmp.size(),t);if(ne=="a"){cout<<"NO"<<endl;return 0;}
//		ret.pb(tmp+ne);
//		cout<<ret[i]<<endl;
	}
	cout<<"YES"<<endl;
	for(i=0;i<in.size();i++){
		if(in[i].se>-1) out[in[i].se]=ret[i];
	}
	for(i=0;i<n;i++) cout<<out[i]<<endl;return 0;
}