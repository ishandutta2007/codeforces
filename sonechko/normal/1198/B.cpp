#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

int a[N],tim[N];
int kk;
pair<int,int> d[N];
int mx[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    int q;
    cin>>q;
    for (int i=1; i<=q; i++)
    {
        int t;
        cin>>t;
        if (t==1)
        {
            int num,x;
            cin>>num>>x;
            tim[num]=i;
            a[num]=x;
        } else
        {
            int x;
            cin>>x;
            kk++;
            d[kk]=mp(i,x);
        }
    }
    for (int i=kk; i>=1; i--)
        mx[i]=max(mx[i+1],d[i].ss);
    for (int i=1; i<=n; i++)
    {
        int l=1,r=kk;
        while (r-l>1)
        {
            int mid=(l+r)/2;
            if (d[mid].ff<tim[i]) l=mid; else r=mid;
        }
        int pos=-1;
        if (d[l].ff>=tim[i]) pos=l; else
        if (d[r].ff>=tim[i]) pos=r; else pos=-1;
        if (pos!=-1)
        {
            a[i]=max(a[i],mx[pos]);
        }
        cout<<a[i]<<" ";
    }
    cout<<"\n";

}