#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    string s;
    cin>>n>>s;
    bool ok=1;
    for (int i=1;i<n;i++)
    {
        if (s[i]!=s[i-1])
            ok=0;
    }
    if (ok)cout<<n<<endl;
    else
    {
        int ans=0;
        int i=0;
        while(i<n && s[i]=='<')
            ans++,i++;
        i=n-1;
        while(i>=0 && s[i]=='>')
            ans++,i--;
        cout<<ans<<endl;
    }
}