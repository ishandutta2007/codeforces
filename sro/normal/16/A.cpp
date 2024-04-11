#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int n,m;
string s[107];

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
        for(int j=0;j<m-1;j++)
            if(s[i][j]!=s[i][j+1])
                return puts("NO"),0;
    }
    for(int i=0;i<n-1;i++)
        if(s[i][0]==s[i+1][0])
            return puts("NO"),0;
    return puts("YES"),0;
}