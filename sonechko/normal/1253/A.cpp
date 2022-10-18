#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ll long long

const int N = 4e5 + 11;

int a[N],b[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie();
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        for (int i=1; i<=n; i++)
            cin>>a[i];
        for (int i=1; i<=n; i++)
        {
            cin>>b[i];
            b[i]=b[i]-a[i];
        }
        int t=1;
        for (int i=1; i<=n; i++)
            if (b[i]<0) t=0;
        int p1=-1,p2=-1;
        for (int i=1; i<=n; i++)
            if (b[i]!=0)
        {
            if (p1==-1) p1=i;
            p2=i;
        }
        if (p1!=-1)
        {
            int c=b[p1];
            for (int i=p1; i<=p2; i++)
                if (b[i]!=c) t=0;
        }
        if (t) cout<<"YES\n"; else cout<<"NO\n";
    }
}