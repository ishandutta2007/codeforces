#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ll long long

const int N = 1e6 + 11;

int a[N],s[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        s[i]=s[i-1]+a[i];
    }
    vector<int> l1,r1;
    for (int l=1; l<=n; l++)
    for (int r=l; r<=n; r++)
    {
        int sum=s[r]-s[l-1];
        int last=r;
        vector<int> l2,r2;
        l2.pb(l);
        r2.pb(r);
        for (int p=r+1; p<=n; p++)
        {
            int c=0;
            for (int t=p; t>last; t--)
            if (s[p]-s[t-1]==sum) {c=t; break;}
            if (c!=0)
            {
                l2.pb(c);
                r2.pb(p);
                last=p;
            }
        }
        if (l2.size()>l1.size())
        {
            l1=l2;
            r1=r2;
        }
    }
    cout<<l1.size()<<endl;
    for (int j=0; j<l1.size(); j++)
        cout<<l1[j]<<" "<<r1[j]<<endl;
}