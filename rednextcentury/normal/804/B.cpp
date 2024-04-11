#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    long long ret=0;
    long long curB=0;
    for (int i=s.size()-1;i>=0;i--)
    {
        if (s[i]=='a')
        {
            ret+=curB;
            ret%=1000000007;
            curB*=2;
            curB%=1000000007;
        }
        else
            curB++,curB%=1000000007;
    }
    cout<<ret<<endl;
}