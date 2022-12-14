#include <bits/stdc++.h>
using namespace std;
long long n;
long long ToInt(string s)
{
    long long ret = 0;
    for (long long i=0;i<s.size();i++)
        ret=ret*10+s[i]-'0';
    return ret;
}
long long calc(string s)
{
    long long x = ToInt(s);
    long long y = x;
    x = max(x - n/2 , 1LL);
    return (min(n/2,y-1)-x+1)/2;
}
string ToString(long long n)
{
    string ret="";
    while(n)
    {
        ret+=n%10+'0';
        n/=10;
    }
    reverse(ret.begin(),ret.end());
    return ret;
}
int main()
{
    cin>>n;
    n=n*2;
    string s = ToString(n);
    if (s.size()==1)
    {
        long long op = n/2;
        cout<<op*(op-1)/2<<endl;
        return 0;
    }
    long long num = 0;
    for (long long i=0;i<s.size();i++)
    {
        if (s[i]=='9')num++;
    }
    if (num==s.size())
    {
        cout<<calc(s)<<endl;
        return 0;
    }
    long long ret = 0;
    if (num+1==s.size())
        ret=calc(s);
    while(s[0]>'0')
    {
        s[0]--;
        for (long long i=1;i<s.size();i++)
            s[i]='9';
        ret+=calc(s);
    }
    cout<<ret<<endl;
}