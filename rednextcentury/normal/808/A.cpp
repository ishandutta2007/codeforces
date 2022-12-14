#include<bits/stdc++.h>
using namespace std;
long long solve(string a,string b)
{
    long long x=0,y=0;
    for (int i=0;i<a.size();i++)
        x=x*10+a[i]-'0';
    for (int i=0;i<b.size();i++)
        y=y*10+b[i]-'0';
    return y-x;
}
int main()
{
    string s;
    cin>>s;
    string b=s;
    for (int i=s.size()-1;i>=1;i--)
    {
        b[i]='0';
    }
    if (b[0]=='9')
        b[0]='0',b="1"+b;
    else b[0]++;
    cout<<solve(s,b)<<endl;
}