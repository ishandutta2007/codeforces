#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long

const int N = 1e6 + 11;

int a[N],v[16000000];
bool use[16000000];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    int d=0;
    for (int i=1; i<=n; i++)
    {
        int x;
        cin>>x;
        if (d==0) d=x; else d=__gcd(d,x);
        a[i]=x;
    }
    int ans=n;
    for (int i=1; i<=n; i++)
    {
        a[i]/=d;
        v[a[i]]++;
        if (a[i]!=1) ans=min(ans,n-v[a[i]]);
    }
    for (int j=2; j<=15000000; j++)
        if (use[j]==0)
    {
        int res=0;
        for (int k=j; k<=15000000; k+=j)
        {
            res+=v[k];
            use[k]=1;
        }
        ans=min(ans,n-res);
    }
    if (ans==n) cout<<-1<<endl; else
    cout<<ans<<endl;
    return 0;
    for (int i=1; i<=n; i++)
    {
        int x=a[i];
        x/=d;
        int p=2;
        while (p*p<=x)
        {
            int kol=0;
            while (x%p==0)
            {
                kol++;
                x/=p;
            }
            if (kol!=0) {v[p]++; ans=min(ans,n-v[p]);}
            p++;
        }
        if (x!=1) {v[x]++; ans=min(ans,n-v[x]);}
    }
    if (ans==n) cout<<-1<<endl; else cout<<ans<<endl;
}