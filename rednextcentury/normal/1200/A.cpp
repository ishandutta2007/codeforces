#include <bits/stdc++.h>
using namespace std;
int has[100];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
    for (auto x:s)
    {
        if (x=='L')
        {
            for (int i=0;i<10;i++)
                if (!has[i])
            {
                has[i]=1;
                break;
            }
        }
        else if (x=='R')
        {
            for (int i=9;i>=0;i--)
                if (!has[i])
            {
                has[i]=1;
                break;
            }
        }
        else
        {
            has[x-'0']=0;
        }
    }
    for (int i=0;i<10;i++)cout<<has[i];
}