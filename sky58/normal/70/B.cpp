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
int main()
{
	string s1,s="",f="";vector <int> t;int i,n;
	cin>>n;cin>>s;
	while(cin>>s1) s+=(" "+s1);
	for(i=0;i<s.size();i++){
//		cout<<f<<' '<<s[i]<<endl;
//		if(f=="" && s[i]==' ') continue;
		if(s[i]=='.' || s[i]=='!' || s[i]=='?'){
			f+=s[i];t.pb(f.size());f="";i++;
		}
		else f+=s[i];
	}
//	for(i=0;i<t.size();i++) cout<<t[i]<<endl;
	int no=t[0],out=1;if(no>n){cout<<"Impossible"<<endl;return 0;}
	for(i=1;i<t.size();i++){
		if(n>=no+t[i]+1) no+=t[i]+1;else{no=t[i];out++;}
		if(no>n){cout<<"Impossible"<<endl;return 0;}
	}
	cout<<out<<endl;return 0;
}