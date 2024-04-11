#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e5 + 11;

bool gg(string s)
{
    int n=s.size();
    s="."+s;
    for (int j=1; j<=n; j++)
        if (s[j]!=s[n-j+1]) return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin>>s;
    s="."+s;
    int n=s.size()-1;
    for (int len=n; len>=1; len--)
    {
        for (int i=1; i<=n-len+1; i++)
        {
            string d="";
                for (int j=i; j<=i+len-1; j++)
                    d+=s[j];
            if (gg(d)) {cout<<len<<endl; return 0;}
        }
    }
    cout<<0<<endl;
}