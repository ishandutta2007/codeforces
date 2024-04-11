#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define mp make_pair
#define ss second
#define ff first
#define ll long long
#define pb push_back
const int MOD = 1e9 + 7;
#define mod %MOD


const int N = 2e5 + 11;
int t[N],l[N],r[N],a[N];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,q,m;
    cin>>n>>q>>m;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    for (int i=1; i<=q; i++)
    {
        cin>>t[i]>>l[i]>>r[i];
    }
    for (int i=1; i<=m; i++)
    {
        int p;
        cin>>p;
        for (int j=q; j>=1; j--)
        {
            int x=l[j],y=r[j],ty=t[j];
            if (x<=p&&p<=y)
            {
                if (ty==1)
                {
                    if (p==x) p=y; else p--;
                } else
                {
                    p=y-p+x;
                }
            }
        }
        cout<<a[p]<<" ";
    }
    cout<<endl;
}