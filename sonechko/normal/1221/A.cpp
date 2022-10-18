#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long

const int N = 2e5 + 11;

int a[N],kk[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q;
    cin>>q;
    for (int iii=1; iii<=q; iii++)
    {
        int n;
        cin>>n;
        for (int j=0; j<=30; j++)
            kk[j]=0;
        for (int i=1; i<=n; i++)
        {
            int l;
            cin>>l;
            int k=0;
            while (l%2==0)
            {
                l/=2;
                k++;
            }
            kk[k]++;
        }
        for (int j=0; j<=10; j++)
            kk[j+1]+=kk[j]/2;
        if (kk[11]) cout<<"YES\n"; else cout<<"NO\n";
    }
}