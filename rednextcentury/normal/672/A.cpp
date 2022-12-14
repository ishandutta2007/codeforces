#include <bits/stdc++.h>
using namespace std;
string s="";
string ToString(int x)
{
    string ret="";
    while(x)
    {
        ret+=char(x%10+'0');
        x/=10;
    }
    reverse(ret.begin(),ret.end());
    return ret;
}
int main ()
{
    for (int i=1;i<=1000;i++)
    {
        s+=ToString(i);
    }
    int n;
    cin>>n;
    cout<<s[n-1]<<endl;
}