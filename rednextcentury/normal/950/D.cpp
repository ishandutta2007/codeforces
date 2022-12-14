#include <bits/stdc++.h>
using namespace std;
#define ll long long
int a[10000];
int main()
{
    ios_base::sync_with_stdio(0);

    /*int n;
    cin>>n;
    for (int i=1;i<=n;i++)
        a[2*i-1]=i;
    while(1)
    {
        int mx=-1;
        for (int i=2*n;i>=1;i--)
        {
            if (a[i]!=0)
            {
                mx = i;
                break;
            }
        }
        if (mx<=n)
            break;
        for (int i=mx-1;i>=1;i--)
        {
            if (a[i]==0)
            {
                a[i]=a[mx];
                a[mx]=0;
                break;
            }
        }
    for (int i=1;i<=2*n;i++)
        cout<<a[i]<<' ';
    cout<<endl;
    }*/


    ll n,q;
    cin>>n>>q;
    while(q--)
    {
        ll x;
        cin>>x;
        if (x%2)
            cout<<(x+1)/2<<endl;
        else
        {
            ll mv = n - x/2;
            ll id = x;
            while(mv)
            {
                id+=mv;
                if (mv%2)
                    break;
                mv/=2;
            }
            cout<<(id+1)/2<<endl;
        }
    }

}