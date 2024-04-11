#include <cstdio>
# include <iostream>
# include <string>
# include <set>
# include <queue>
# include <cstring>
# include <algorithm>
# include <cstdlib>
# include <ios>
using namespace std;
int a[1000001];
int b[1000001];
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    string s,h;
    cin>>s>>h;
    int n=s.length();
    int p=0;
    int l=0;
    for (int i=0;i<n;i++)
    {
        if (s[i]=='1')
            p++;
    }
    if (s.length()!=h.length())
        cout<<"NO\n";
    else
    {
        for (int i=0;i<n;i++)
        {
            if (h[i]=='1')
                l++;
        }
        if (p==0 && l!=0)
            cout<<"NO\n";
        else
        {
            if (p!=0 && l==0)
                cout<<"NO\n";
            else
                cout<<"YES\n";
        }
    }
}