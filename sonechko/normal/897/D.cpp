#include<bits/stdc++.h>
using namespace std;

#define ll long long

const ll N = 1e3 + 11;

int a[N];

int main()
{
    int n,m,c;
    cin>>n>>m>>c;
    for (int iii=1; iii<=m; iii++)
    {
        int x;
        cin>>x;
        int tt=0;
        if (x<=c/2)
        {
            for (int i=1; i<=n; i++)
                if (a[i]==0||a[i]>x)
            {
                a[i]=x;
                cout<<i<<endl;
                break;
            }
        } else
        {
            for (int i=n; i>=1; i--)
                if (a[i]==0||a[i]<x)
            {
                a[i]=x;
                cout<<i<<endl;
                break;
            }
        }
        int xx=0;
        for (int i=1; i<=n; i++)
            if (a[i]==0) xx=1;
        if (xx==0) return 0;
    }
}