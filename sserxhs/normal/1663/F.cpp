#include <bits/stdc++.h>
using namespace std;
#if !defined(ONLINE_JUDGE)&&defined(LOCAL)
#include "my_header\debug.h"
#else
#define dbg(...) ;
#define dbgn(...) ;
#endif
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int N=1e6+5;
string q[4]={"buffy","the","vampire","slayer"};
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	string s;
	cin>>s;
	if (s.size()==4) return cout<<"none",0;
	for (auto t:q) if (t.size()==s.size()) for (int i=0;i<s.size();i++) s[i]=(s[i]-'a'+t[i]-'a')%26+'a';
	cout<<s;
	//assert(s.size()==7);
}