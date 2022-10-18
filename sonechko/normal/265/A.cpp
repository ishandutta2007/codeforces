#include<bits/stdc++.h>

using namespace std;

string s,t;
int n,i,j,ans,m;

int main()
{
    cin>>s>>t;
    n=s.length();
    m=t.length();
    i=0;
    for (j=0; j<m; j++)
    {
        if ((t[j]==s[i])&(i!=n-1))
        {
            i++;
        }
    }
    cout<<i+1<<endl;
}