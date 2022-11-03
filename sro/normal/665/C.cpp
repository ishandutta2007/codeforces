#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

char s[200007];

int main()
{
    cin>>s;
    for(int i=2;s[i-1];i++)
    {
        if(s[i-2]==s[i-1])
        {
            for(char j='a';j<='z';j++)
                if(j!=s[i-2]&&j!=s[i])
                {
                    s[i-1]=j;
                    break;
                }
        }
    }
    cout<<s<<endl;
    return 0;
}