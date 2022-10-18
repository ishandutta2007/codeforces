#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

int a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q;
    cin>>q;
    while (q--)
    {
        int n;
        cin>>n;
        for (int i=1; i<=n; i++)
            cin>>a[i];
        int pos=1;
        while (pos<n)
        {
            int t=n,pp=0;
            for (int i=pos; i<=n; i++)
            if (a[i]<=t) {t=a[i]; pp=i;}
            int ps=pp;
            while (pp>pos)
            {
                swap(a[pp-1],a[pp]);
                pp--;
            }
            if (ps==pos) pos++; else pos=ps;
        }
        for (int i=1; i<=n; i++)
            cout<<a[i]<<" ";
        cout<<"\n";
    }
}