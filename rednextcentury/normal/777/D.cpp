#include <bits/stdc++.h>
using namespace std;
#define ll long long
string s[1000000];
int l[1000000];
int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>s[i];
        l[i]=s[i].size();
    }
    for (int i=n-2;i>=0;i--)
    {
        int j;
        bool ok =0;
        for (j=0;j<min(l[i],l[i+1]);j++)
        {
            if (s[i][j]!=s[i+1][j])
            {
                if (s[i][j]<s[i+1][j])
                    ok=1;
                break;
            }
        }
        if (ok)continue;
        l[i]=j;
    }
    for (int i=0;i<n;i++)
        cout<<s[i].substr(0,l[i])<<endl;
}