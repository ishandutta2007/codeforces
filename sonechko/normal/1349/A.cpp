#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 4e5 + 11;

int k1[N],k2[N],ks[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=200000; i++)
    {
        k1[i]=-1;
        k2[i]=-1;
        ks[i]=0;
    }
    for (int ii=1; ii<=n; ii++)
    {
        int x;
        cin>>x;
        int d=2;
        while (d*d<=x)
        {
            int k=0;
            while (x%d==0)
                {k++; x/=d;}
            if (k1[d]==-1)
            {
                k1[d]=k;
                k2[d]=-1;
            } else
            if (k2[d]==-1)
            {
                if (k<k1[d]) {k2[d]=k1[d]; k1[d]=k;} else k2[d]=k;
            } else
            if (k<k1[d]) {k2[d]=k1[d]; k1[d]=k;} else
            if (k<k2[d]) k2[d]=k;
            ks[d]++;
            d++;
        }
        if (x>1)
        {
            int k=1;
            d=x;
            if (k1[d]==-1)
            {
                k1[d]=k;
                k2[d]=-1;
            } else
            if (k2[d]==-1)
            {
                if (k<k1[d]) {k2[d]=k1[d]; k1[d]=k;} else k2[d]=k;
            } else
            if (k<k1[d]) {k2[d]=k1[d]; k1[d]=k;} else
            if (k<k2[d]) k2[d]=k;
            ks[d]++;
        }
    }
    ll ans=1;
    for (int i=2; i<=200000; i++)
        if (ks[i]<n-1) {} else
        {
            if (ks[i]==n-1)
            {
            int k=0;
            if (k2[i]==-1)
            {
                if (k<k1[i]) {k2[i]=k1[i]; k1[i]=k;} else k2[i]=k;
            } else
            if (k<k1[i]) {k2[i]=k1[i]; k1[i]=k;} else
            if (k<k2[i]) k2[i]=k;
            }
            int kol=k2[i];
            for (int j=1; j<=kol; j++)
                ans*=1ll*i;
        }
    cout<<ans;
}
/**
2 5
2 2 2 3
2 2 2 5
2 2 2 2 5

**/