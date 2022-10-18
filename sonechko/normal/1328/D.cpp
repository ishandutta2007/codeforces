#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ld long double

const int N = 5e5 + 11;

int a[N];

void up()
{
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    for (int i=1; i<=n; i++)
        a[i+n]=a[i];
    int k=0;
    a[0]=a[n];
    a[n+1]=a[1];
    for (int i=1; i<=n; i++)
        if (a[i]!=a[i-1]) k++;
    if (k==0)
    {
        cout<<"1\n";
        for (int i=1; i<=n; i++)
            cout<<1<<" ";
        cout<<"\n";
        return;
    }
    if (k%2==1&&k!=n)
    {
        for (int i=1; i<=n; i++)
            if (a[i]==a[i-1]&&a[i]!=a[i+1]) {a[i]=2e9; break;}
    }
    if (k%2==0||(k!=n))
    {
        cout<<"2\n";
        int p=1;
        for (int i=1; i<=n; i++)
        {
            if (i>1&&a[i]!=a[i-1]) p=3-p;
            cout<<p<<" ";
        }
        cout<<"\n";
        return;
    }
    cout<<"3\n";
    int p=1;
    for (int i=1; i<=n; i++)
    {
        if (i>1&&a[i]!=a[i-1]) p=3-p;
        if (i<n) cout<<p<<" "; else cout<<"3 ";
    }
    cout<<"\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q;
    cin>>q;
    while (q--) up();
}