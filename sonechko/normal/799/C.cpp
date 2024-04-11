#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
const int N = 2e5 + 11;
pair<int,int> a[N],b[N];
int maxi1[N],maxi2[N];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,c,d;
    cin>>n>>c>>d;
    int n1=0,n2=0;
    for (int i=1; i<=n; i++)
    {
        int l,r;
        char ch;
        cin>>l>>r>>ch;
        if (ch=='C') {n1++; a[n1]=mp(r,l);}
        if (ch=='D') {n2++; b[n2]=mp(r,l);}
    }
    sort(a+1,a+n1+1);
    sort(b+1,b+n2+1);
    vector<pair<int,int> > v1,v2;

    int ans=0;

    for (int i=2; i<=n1; i++)
    if (a[i].ff+a[i-1].ff<=c) ans=max(ans,a[i].ss+a[i-1].ss);
    for (int i=2; i<=n2; i++)
    if (b[i].ff+b[i-1].ff<=d) ans=max(ans,b[i].ss+b[i-1].ss);


    int k=0;
    int mm=0;
    for (int i=1; i<=c; i++)
    {
        while (k<n1&&a[k+1].ff<=i)
        {
            k++;
            mm=max(mm,a[k].ss);
        }
        maxi1[i]=mm;
    }

    k=0;
    mm=0;
    for (int i=1; i<=d; i++)
    {
        while(k<n2&&b[k+1].ff<=i)
        {
            k++;
            mm=max(mm,b[k].ss);
        }
        maxi2[i]=mm;
    }
    for (int i=1; i<=n1; i++)
    if (a[i].ff<=c)
    {
        int p=min(a[i].ff-1,c-a[i].ff);
        if (maxi1[p]!=0) ans=max(ans,maxi1[p]+a[i].ss);
        if (maxi2[d]!=0) ans=max(ans,maxi2[d]+a[i].ss);
    }
    for (int i=1; i<=n2; i++)
    if (b[i].ff<=d)
    {
        int p=min(b[i].ff-1,d-b[i].ff);
        if (maxi2[p]!=0) ans=max(ans,maxi2[p]+b[i].ss);
        if (maxi1[c]!=0) ans=max(ans,maxi1[c]+b[i].ss);
    }
    cout<<ans<<endl;

}