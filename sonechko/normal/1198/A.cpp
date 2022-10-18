#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 4e5 + 11;

int a[N],kol[N],ks[N];
int kk;
int n,ii;

int lg(int l)
{
    for (int p=0; p<=20; p++)
        if ((1<<p)>=l) return p;
}

bool good(int kol)
{
    if (lg(kol)*n>ii) return 0;
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>ii;
    ii*=8;
    vector<int> vv;
    for (int i=1; i<=n; i++)
        {
            cin>>a[i];
            vv.pb(a[i]);
        }
    sort(vv.begin(),vv.end());
    for (int i=0; i<vv.size(); i++)
        if (i==0||vv[i]!=vv[i-1])
    {
        kk++;
        kol[kk]++;
    } else kol[kk]++;
    int pos=1;
    for (int i=1; i<=kk; i++)
        ks[i]=ks[i-1]+kol[i];
    int ans=n;
    for (int i=1; i<=kk; i++)
    {
        if (pos<i) pos=i;
        while (pos<kk&&good(pos+1-i+1)==1)
            pos++;
        if (good(pos-i+1))
        {
            ans=min(ans,n-(ks[pos]-ks[i-1]));
        }
    }
    cout<<ans<<"\n";
}