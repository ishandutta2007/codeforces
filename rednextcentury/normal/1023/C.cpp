#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    int num=0;
    string ret="";
    for (int i=0;i<s.size();i++)
    {
        if (ret.size()-num == m)
            break;
        if (s[i]=='(')
            ret+=s[i],num++;
        else if (num)
        {
            num--;
            ret+=")";
        }
    }
    string pos="";
    for (int i=ret.size()-1;i>=0;i--)
    {
        if (ret[i]!='(' || num==0)
            pos+=ret[i];
        else if (num)
        {
            num--;
        }
    }
    reverse(pos.begin(),pos.end());
    cout<<pos<<endl;
}