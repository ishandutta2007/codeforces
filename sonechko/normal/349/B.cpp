#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define ss second
#define ff first
const ll N = 5000000 + 11;
ll a[N],b[N];
int  main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    int k=1;
    for (int i=1; i<=9; i++)
    {
        cin>>a[i];
        if (a[i]<=a[k]) k=i;
    }
    int p=n/a[k];
    int ps=p*a[k];
    for (int i=1; i<=p; i++)
    b[i]=k;
    for (int i=1; i<=p; i++)
    {
        int kk=b[i];
        for (int j=9; j>=kk+1; j--)
        if (ps-a[k]+a[j]<=n) {ps=ps-a[k]+a[j]; b[i]=j; break;}
    }
    if (p==0) cout<<-1<<endl; else
    {
        for (int j=1; j<=p; j++)
            cout<<b[j];
        cout<<endl;
    }
}