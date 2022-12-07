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
int ch(string s){
	int n=s.size();
	if(n>=3) if(s.substr(n-3,3)=="etr") return 0;
	if(n>=4) if(s.substr(n-4,4)=="etra") return 1;
	if(n>=6) if(s.substr(n-6,6)=="initis") return 2;
	if(n>=6) if(s.substr(n-6,6)=="inites") return 3;
	if(n>=4) if(s.substr(n-4,4)=="lios") return 4;
	if(n>=5) if(s.substr(n-5,5)=="liala") return 5;
	return -1;
}
int main()
{
	int i,pat=0,g=-1;string s;vector <string> ret;
	while(cin>>s){
		int t=ch(s),t2=t%2;
		if(t<0){
			cout<<"NO"<<endl;return 0;
		}
		if(g==-1) g=t2;
		else{
			if(g!=t2){
				cout<<"NO"<<endl;return 0;
			}
		}
		ret.pb(s);
	}
	if(ret.size()<2){
		cout<<"YES"<<endl;return 0;
	}
	for(i=0;i<ret.size();i++){
		int t=ch(ret[i])/2;
		if(pat==0){
			if(t==1){
				cout<<"NO"<<endl;return 0;
			}
			if(t==0) pat=1;
		}
		else{
			if(t!=1){
				cout<<"NO"<<endl;return 0;
			}
		}
	}
	if(pat==0){
		cout<<"NO"<<endl;return 0;
	}
	cout<<"YES"<<endl;
	return 0;
}