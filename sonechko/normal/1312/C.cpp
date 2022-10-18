#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define ff first
#define ss second
#define pb push_back

const int N = 2e5 + 11;

ll a[N],kol[N];

void up()
{
    int n,k;
    cin>>n>>k;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    for (int st=0; st<=60; st++)
    {
        for (int i=0; i<k; i++)
            kol[i]=0;
        int kk=0;
        for (int i=1; i<=n; i++)
        {
            int c=a[i]%k;
            a[i]/=k;
            if (c>1) {cout<<"NO\n"; return;}
            if (c==1) kk++;
            if (kk>1) {cout<<"NO\n"; return;}
        }
    }
    cout<<"YES\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--)
        up();
}