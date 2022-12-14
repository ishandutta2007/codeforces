#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mid (l+r)/2
#define L x*2
#define R x*2+1
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        int l=0;
        while(l<n && s[l]!='8')
            l++;
        string t="";
        for (int i=l;i<n;i++)
            t+=s[i];
        if (t.size()>=11)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}