#include<bits/stdc++.h>
#include<stack>
#define ll long long
#define PB push_back
#define MP make_pair
#define F first
#define S second
using namespace std;
inline bool open(char c) {return (c=='<'||c=='{'||c=='('||c=='[');}
inline bool same_type(char a,char b) {return (a=='<'&&b=='>')||(a=='{'&&b=='}')||(a=='('&&b==')')||(a=='['&&b==']');}
int main()
{
	ll ans=0;stack<char>st;string s;cin>>s;
	for(ll i=0;i<s.size();i++)
	{
		if(open(s[i])) st.push(s[i]);
		else if(!st.empty()) {ans+=(!same_type(st.top(),s[i]));st.pop();}
		else {cout<<"Impossible";return 0;}
	}
	if(!st.empty()) {cout<<"Impossible";return 0;}
	cout<<ans;
}