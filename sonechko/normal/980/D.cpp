#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ss second
#define ff first
#define mp make_pair
#define pb push_back
#define y1 dhnfg
#define ld long double

const int N = 1e6 + 11;

int a[N],kk[N];
int b[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        int p;
        cin>>p;
        int minu=1;
        if (p<0) {p*=-1; minu=-1;}
        for (int d=2; d*d<=p; d++)
        {
            ll k=0;
            while (p%d==0)
            {
                p/=d;
                k^=1;
            }
            if (k==1) minu*=d;
        }
        minu*=p;
        a[i]=minu;
    }
    vector<pair<int,int> > vv;
    for (int i=1; i<=n; i++)
        vv.pb(mp(a[i],i));
    sort(vv.begin(),vv.end());
    int kkk=0;
    for (int j=0; j<vv.size(); j++)
    if (j==0||vv[j].ff!=vv[j-1].ff) {kkk++;
    if (vv[j].ff==0) a[vv[j].ss]=0; else a[vv[j].ss]=kkk;} else
        a[vv[j].ss]=a[vv[j-1].ss];
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
            b[j]=0;
        int ans=0;
        for (int j=i; j<=n; j++)
        {
            if (a[j]==0) {} else
            if (b[a[j]]==0) {b[a[j]]=1; ans++;}
            kk[max(1,ans)]++;
        }
    }
    for (int i=1; i<=n; i++)
    cout<<kk[i]<<" ";
    cout<<endl;
}