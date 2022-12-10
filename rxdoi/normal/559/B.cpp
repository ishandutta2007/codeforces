#include<string>
#include<iostream>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

string S,T;

string Get(string s)
{
	if (s.length()&1) return s;
	string t1="",t2="";
	For(i,0,s.length()/2) t1+=s[i];
	For(i,s.length()/2,s.length()) t2+=s[i];
	t1=Get(t1),t2=Get(t2);
	return t1<t2?t1+t2:t2+t1;
}

int main()
{
	cin>>S>>T;
	cout<<(Get(S)==Get(T)?"YES":"NO");
}