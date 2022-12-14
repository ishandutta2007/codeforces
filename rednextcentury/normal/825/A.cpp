#include <bits/stdc++.h>
using namespace std;
int main ()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    s+='0';
    int num=0;
    string ret="";
    for (int i=0;i<=n;i++)
    {
        if (s[i]=='1')
            num++;
        else
            ret+='0'+num,num=0;
    }
    cout<<ret<<endl;
}