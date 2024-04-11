#include <bits/stdc++.h>
using namespace std;
char x[1000000];
char y[1000000];
char mp[100000];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    for (int i=0;i<m;i++)
        cin>>x[i]>>y[i];
    for (char h='a';h<='z';h++)
    {
        char c=h;
        for (int i=0;i<m;i++)
        {
            if (c==x[i])
                c=y[i];
            else if (c==y[i])
                c=x[i];
        }
        mp[h]=c;
    }
    for (int i=0;i<n;i++)
        s[i]=mp[s[i]];
    cout<<s<<'\n';
}