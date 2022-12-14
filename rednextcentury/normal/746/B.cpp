#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    string s;
    cin>>n>>s;
    string ret="";
    int i=0;
    if (n%2)
        ret+=s[0],s=s.substr(1,s.size()-1);
    for (int i=0;i<s.size();i++)
    {
        if (i%2==0)
            ret=s[i]+ret;
        else
            ret+=s[i];
    }
    
    cout<<ret<<endl;
}