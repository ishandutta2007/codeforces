#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
using namespace std ;
int main ()
{
    int t;
    cin>>t;;
    while(t--)
    {
        int n;
        string s;
        cin>>n>>s;
        bool ok=1;
        for (int i=0;i<n;i++)
        {
            if (abs(s[i]-s[n-1-i])%2 ||abs(s[i]-s[n-1-i])>2 )
                ok=0;
        }
        if (ok)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}