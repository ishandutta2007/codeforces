#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

const int N = 2e5 + 11;

int color[N],a[N];

void up()
{
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        color[i]=0;
    }
    int cc=n,p=2,m=0;
    while (cc>0)
    {
        int ks=0;
        for (int i=1; i<=n; i++)
            if (a[i]%p==0&&color[i]==0) ks++;
        if (ks>0)
        {
            m++;
            for (int i=1; i<=n; i++)
                if (a[i]%p==0&&color[i]==0) color[i]=m;
            cc-=ks;
        }
        p++;
    }
    cout<<m<<"\n";
    for (int i=1; i<=n; i++)
        cout<<color[i]<<" ";
    cout<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q;
    cin>>q;
    while (q--) up();
}