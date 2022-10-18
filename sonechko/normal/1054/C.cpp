#include<bits/stdc++.h>
using namespace std;

#define ff first
#define pb push_back
#define ss second
#define mp make_pair
#define ll long long
#define mod %MOD

const int N = 1e6 + 11;
const int MOD = 1e9 + 7;

int a[N],b[N],c[N],aa[N],bb[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        aa[i]=a[i];
    }
    for (int i=1; i<=n; i++)
    {
        cin>>b[i];
        bb[i]=b[i];
    }
    for (int i=n; i>=1; i--)
    {
        vector<int> v;
        for (int j=1; j<=n; j++)
            if (c[j]==0&&a[j]==0&&b[j]==0) {c[j]=i; v.pb(j);}
        for (int j=0; j<v.size(); j++)
        {
            int pos=v[j];
            for (int i=1; i<pos; i++)
                b[i]--;
            for (int i=pos+1; i<=n; i++)
                a[i]--;
        }
    }
    for (int i=1; i<=n; i++)
    {
        a[i]=0;
        b[i]=0;
    }
    for (int i=1; i<=n; i++)
    for (int j=i+1; j<=n; j++)
    if (c[i]<c[j]) b[i]++; else
    if (c[i]>c[j]) a[j]++;
    for (int i=1; i<=n; i++)
    if (a[i]!=aa[i]||b[i]!=bb[i]) {cout<<"NO"<<endl; return 0;}
    cout<<"YES"<<endl;
    for (int i=1; i<=n; i++)
        cout<<c[i]<<" ";
    cout<<endl;
}