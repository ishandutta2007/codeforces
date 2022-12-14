#include<bits/stdc++.h>
using namespace std;
bool check(string x)
{
    for (int i=0;i<x.size();i++)
    {
        if (x[i]!=x[x.size()-i-1])
            return 0;
    }
    return 1;
}
int main()
{
    string s;
    cin>>s;
    int ret=0;
    for (int i=0;i<s.size();i++)
    {
        for (int j=i;j<s.size();j++)
        {
            if (!check(s.substr(i,(j-i+1))))
                ret=max(ret,(j-i)+1);
        }
    }
    cout<<ret<<endl;
}