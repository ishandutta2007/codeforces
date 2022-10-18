#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q;
    cin>>q;
    while (q--)
    {
        ll n,m,k;
        cin>>n>>m>>k;
        ll t=min(n,m);
        t+=((max(n,m)-min(n,m))/2)*2;
        k-=max(n,m);
        if (k<0) cout<<-1<<"\n"; else
        {
            if (k%2==0) t+=k; else
            {
                t+=k-1;
                if ((max(n,m)-min(n,m))%2==1) t++; else t--;
            }
            cout<<t<<"\n";
        }
    }
}