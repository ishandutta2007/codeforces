#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define ll long long

const int N = 2e6 + 11;

int a[N],s[N],poss[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,q;
    cin>>n>>q;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        a[n+i]=a[i];
    }
    for (int i=1; i<=n*2; i++)
        s[i]=s[i-1]+a[i];
    for (int p=1; p<=q; p++)
    {
        int t;
        cin>>t;
        int pos=1;
        for (int i=1; i<=n; i++)
        {
            while (pos<2*n&&s[pos+1]-s[i-1]<=t)
                pos++;
            poss[i]=pos;
        }
        int l=2e9,c=1;
        for (int i=1; i<=n; i++)
            if (poss[i]-i<l) {l=poss[i]-i; c=i;}
        int ans=n;
        for (int j=c; j<=c+l+1; j++)
        {
            int kol=0;
            int p=j+1;
            if (p>n) p-=n;
            if (p>n) p-=n;
            int d=j;
            if (d>n) d-=n;
            if (d>n) d-=n;
            //cout<<c<<".."<<j<<" = ";
            while (p<=d+n)
            {
                int dd;
                if (p<=n) dd=poss[p]; else dd=n+poss[p-n];
                kol++;
                //cout<<" |"<<p<<".."<<d;
                p=dd+1;
            }
            //cout<<" = "<<kol<<endl;

            ans=min(ans,kol);
        }
        cout<<ans<<"\n";
    }
}