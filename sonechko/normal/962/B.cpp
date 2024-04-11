#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 11;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie();
    int n,a,b,ans=0;
    cin>>n>>a>>b;
    string s;
    cin>>s;
    s="*"+s;
    for (int i=1; i<=n; i++)
    if (s[i]=='.')
    {
        if (s[i-1]=='*'||s[i-1]=='.')
        {
            if (a>b) {a--; s[i]='+'; ans++;} else
            if (b>0) {b--; s[i]='-'; ans++;}
        } else
        if (s[i-1]=='+'&&b>0) {b--; s[i]='-'; ans++;} else
        if (s[i-1]=='-'&&a>0) {a--; s[i]='+'; ans++;}
    }
    cout<<ans<<endl;
}