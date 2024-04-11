#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ss second
#define ff first
#define mp make_pair

const int N = 2e5 + 11;

int a[N],b[N],c[N];

int main()
{
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   int n;
   cin>>n;
   for (int i=1; i<=n; i++)
    cin>>a[i];
    int res=0;
   for (int i=1; i<=n; i++)
    if (a[i]==1) b[i]=b[i-1]+1; else b[i]=b[i-1];
    for (int i=n; i>=1; i--)
    if (a[i]==2) c[i]=c[i+1]+1; else c[i]=c[i+1];
    res=max(res,b[n]);
    res=max(res,c[1]);
    for (int i=1; i<=n; i++)
        res=max(res,b[i]+c[i]);
    for (int l=1; l<=n; l++)
    {
        int kol1=0,kol2=0,rres=0,ans=0;
        for (int r=l; r<=n; r++)
        {
            if (a[r]==2)
            {
                kol2++;
                ans=max(ans,kol2);
                rres=max(rres,kol2);
            } else
            {
                kol1++;
                rres++;
                ans=max(ans,rres);
                ans=max(ans,kol1);
            }
            res=max(res,ans+b[l-1]+c[r+1]);
        }
    }
    cout<<res<<endl;
}