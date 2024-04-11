#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 11;

int main()
{
    string s;
    cin>>s;
    while (1==1)
    {
        if (s[4]!='9') s[4]++; else
        {
            s[4]='0';
            if (s[3]!='5') s[3]++; else
            {
                s[3]='0';
                if (s[0]=='2'&&s[1]=='3') s="00:00"; else
                if (s[1]!='9') s[1]++; else
                {
                    s[0]++;
                    s[1]='0';
                }
            }
        }
        if (s[0]==s[4]&&s[1]==s[3]) {cout<<s<<endl; return 0;}
    }
}