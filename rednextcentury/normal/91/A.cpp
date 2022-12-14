# include<iostream>
# include<iomanip>
#include <cstdio>
# include <algorithm>
using namespace std;
int after[1000000][26];
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    int n1,n2;
    n1=s1.length();
    n2=s2.length();
    for (int x=0;x<26;x++)
    {
        after[n1-1][x]=-1;
    }
    after[n1-1][int(s1[n1-1]-'a')]=n1-1;
    for (int i=n1-2;i>=0;i--)
    {
        for (int x=0;x<26;x++)
        {
            after[i][x]=after[i+1][x];
        }
        after[i][int(s1[i]-'a')]=i;
    }
    int j=-1;
    int ans=1;
    for (int i=0;i<n2;i++)
    {
        if (j<n1-1 && after[j+1][int(s2[i]-'a')]!=-1)
        {
            j=after[j+1][int(s2[i]-'a')];
            continue;
        }
        else if (after[0][int(s2[i]-'a')]!=-1)
        {
            j=after[0][int(s2[i]-'a')];
            ans++;
            continue;
        }
        else
        {
            cout<<-1<<endl;
            return 0;
        }
    }
    cout<<ans<<endl;
}