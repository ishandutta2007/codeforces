#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define pb push_back
#define ld long double
#define mp make_pair

const int N = 2e5 + 11;

int a[N],t[N],tt[N];
bool use[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,k;
    cin>>n>>k;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    int pos=0,kol=0;
    while (1)
    {
        int kk=0;
        for (int i=1; i<=k; i++)
            if (t[i]==0)
        {
            if (pos!=n)
            {
                pos++;
                t[i]=pos;
                tt[i]=0;
                kk++;
            }
        } else kk++;
        if (kk==0) break;
        int p=round((ld)100*(ld)kol/(ld)n);
        for (int i=1; i<=k; i++)
        {
            tt[i]++;
            if (tt[i]==p) use[t[i]]=1;
            if (tt[i]==a[t[i]])
            {
                t[i]=0;
                kol++;
            }
        }
    }
    int ans=0;
    for (int i=1; i<=n; i++)
        ans+=use[i];
    cout<<ans<<endl;
}