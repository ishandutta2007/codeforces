#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 11;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin>>s;
    for (int i=0; i<=1000000; i++)
    {
        if (s[0]==s[4]&&s[1]==s[3]) {cout<<i<<endl; return 0;}
        if (s[4]!='9') s[4]++; else
        {
            s[4]='0';
            if (s[3]!='5') s[3]++; else
            {
                s[3]='0';
                if (s[0]=='2'&&s[1]=='3') {s[0]='0'; s[1]='0';} else
                if (s[1]!='9') s[1]++; else
                {
                    s[1]='0';
                    s[0]++;
                }
            }
        }
    }
}