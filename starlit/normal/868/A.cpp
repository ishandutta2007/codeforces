#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n;
bool e=0,f=0;
string s,t;
int main()
{
    cin>>s>>n;
	while(n--)
	{
        cin>>t;
	    if(t==s)
        {puts("YES");return 0;}
        if(t[0]==s[1])e=1;
        if(t[1]==s[0])f=1;
	}
	if(e&f)
    puts("YES");
    else puts("NO");
}