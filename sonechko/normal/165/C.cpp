#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 11;

int a[N];

int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    s="."+s;
    ll ans=0;
    for (int i=1; i<s.size(); i++)
        if (s[i]=='1') a[i]=a[i-1]+1; else a[i]=a[i-1];
    for (int i=1; i<s.size(); i++)
    {
        int l=i,r=s.size()-1;
        while (r-l>1)
        {
            int mid=(l+r)/2;
            if (a[mid]-a[i-1]<n) l=mid; else r=mid;
        }
        int pr=0;
        if (a[l]-a[i-1]==n) pr=l; else
        if (a[r]-a[i-1]==n) pr=r;
        if (pr!=0)
        {
            l=pr;
            r=s.size()-1;
            while (r-l>1)
            {
                int mid=(l+r)/2;
                if (a[mid]-a[i-1]==n) l=mid; else r=mid;
            }
            if (a[r]-a[i-1]==n) ans+=(ll)r-pr+1; else
            if (a[l]-a[i-1]==n) ans+=(ll)l-pr+1;
        }
    }
    cout<<ans<<endl;
}