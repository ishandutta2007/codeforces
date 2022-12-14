
#include <bits/stdc++.h>
using namespace std;
char b[1000];
char a[1000];
bool vis[10000];
string solve(char x)
{
    string res;
    res+=x;
    while(1)
    {
        bool p=1;
        if (b[res[0]]!='-')
        {
            p=0;
            res=char(b[res[0]])+res;
        }
        if (a[res[res.size()-1]]!='-')
        {
            p=0;
            res+=char(a[res[res.size()-1]]);
        }
        if (p)
            break;

    }
    for (int i=0;i<res.size();i++)
        vis[res[i]]=0;
    return res;

}
int main()
{
    int n;
    cin>>n;
    for (char x='a';x<='z';x++)
        a[x]=b[x]='-';
    while(n--)
    {
        string s;
        cin>>s;
        for (int j=0;j<s.size();j++)
        {
            vis[s[j]]=1;
            if (j>0)
                b[s[j]]=s[j-1];
            if(j+1<s.size())
                a[s[j]]=s[j+1];
        }
    }
    string res="";
    bool p=1;
    for (char x='a';x<='z';x++)
    {
        if (vis[x])
        {
            res+=solve(x);
        }
    }
    cout<<res<<endl;
}