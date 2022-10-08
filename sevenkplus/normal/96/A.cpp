#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    string s;
    cin>>s;char LA=0;
    for(int i=0,l=0;i<(int)s.length();i++)
    {
        if(s[i]==LA)l++;else l=1,LA=s[i];
        if(l>=7){puts("YES");return 0;}
    }
    puts("NO");
    return 0;
}