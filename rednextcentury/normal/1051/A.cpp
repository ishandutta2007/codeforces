#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main()
{
    fast;
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int ret=1+s.size();
        string t;
        for (int i=0;i<s.size();i++)
        {
            for (int j=i-1;j<=i+2;j++)
            {
                int dig=0,lower=0,upper=0;
                for (int x=0;x<i;x++)
                {
                    if (isdigit(s[x]))dig=1;
                    else if (tolower(s[x])==s[x])
                        lower=1;
                    else upper=1;
                }
                for (int x=j+1;x<s.size();x++)
                {
                    if (isdigit(s[x]))dig=1;
                    else if (tolower(s[x])==s[x])
                        lower=1;
                    else upper=1;
                }
                int need = 3-dig-upper-lower;
                if (need<=(j-i+1))
                {
                    if ((j-i+1)<ret)
                    {
                        ret=j-i+1;
                        int cur=i;
                        t=s;
                        if (dig==0)t[cur++]='1';
                        if (lower==0)t[cur++]='a';
                        if (upper==0)
                            t[cur++]='A';
                    }
                }
            }
        }
            cout<<t<<endl;
    }
}