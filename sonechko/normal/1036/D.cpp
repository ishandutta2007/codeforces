#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 3e5 + 11;

ll a[N],b[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    int m;
    cin>>m;
    for (int i=1; i<=m; i++)
        cin>>b[i];
    ll k=1,s1=0,s2=0,pos=0;
    for (int i=1; i<=n; i++)
    {
        s1+=a[i];
        while (s2<s1)
        {
            pos++;
            s2+=b[pos];
            if (pos==m) break;
        }
        if (s1==s2)
        {
            if (i==n) break;
            k++;
            s1=0;
            s2=0;
        }
    }
    if (s1!=s2||pos!=m) cout<<-1; else
    cout<<k;
}