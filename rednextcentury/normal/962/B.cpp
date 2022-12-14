#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,a,b;
    cin>>n>>a>>b;
    string s;
    cin>>s;
    s="*"+s;
    int ret=0;
    for (int i=0;i<s.size();i++)
    {
        if (s[i]=='.')
        {
            if (s[i-1]=='a')
            {
                if (b>0)s[i]='b',b--,ret++;
            }
            else if (s[i-1]=='b')
            {
                if (a>0)s[i]='a',a--,ret++;
            }
            else
            {
                if (a>=b && a)s[i]='a',a--,ret++;
                else if (b>=a && b)s[i]='b',b--,ret++;
            }
        }
    }
    cout<<ret<<endl;
}