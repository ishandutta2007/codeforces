#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define ll long long
#define mp make_pair
#define pb push_back

const int N = 6e6 + 11;

int nx[N][2],all_,kol[N],a[N];

void up(int x)
{
    int t=0;
    kol[t]++;
    for (int i=30; i>=0; i--)
    {
        int p=0;
        if (x&(1<<i)) p=1;
        if (nx[t][p]==0) {all_++; nx[t][p]=all_;}
        t=nx[t][p];
        kol[t]++;
    }
}

int find_(int c)
{
    int t=0;
    kol[t]--;
    int gg=0;
    for (int i=30; i>=0; i--)
    {
        int p=0;
        if (c&(1<<i)) p=1;
        if (nx[t][p]!=0)
        {
            int g=nx[t][p];
            kol[g]--;
            if (kol[g]==0) nx[t][p]=0;
            gg^=p*(1<<i);
            t=g;
        } else
        {
            int g=nx[t][1-p];
            kol[g]--;
            if (kol[g]==0) nx[t][1-p]=0;
            t=g;
            gg^=(1-p)*(1<<i);
        }
    }
    return gg;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    cin>>a[i];
    for (int i=1; i<=n; i++)
    {
        int m;
        cin>>m;
        up(m);
    }
    for (int i=1; i<=n; i++)
    {
        int g=find_(a[i]);
        cout<<(a[i]^g)<<" ";
    }
}