#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define ss second
#define ff first
#define pb push_back
#define mp make_pair
#define y1 kdnfskefn
#define sqr(a) ((a)*(a))
const int N = 1e6 + 11;
int use[N],a[N],b[N];
///-----------------------------------------------------------
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m,l,r;
    cin>>n>>m>>l>>r;
    for (int i=1; i<=n; i++)
        {
            int l1,r1;
            cin>>l1>>r1;
            for (int j=l1; j<=r1; j++)
            {
                use[j]=1;
            }
        }
    for (int i=1; i<=m; i++)
    {
        cin>>a[i]>>b[i];
    }
    int ans=0;
    for (int k=l; k<=r; k++)
    {
        int t=0;
        for (int j=1; j<=m; j++)
        {
            for (int p=a[j]; p<=b[j]; p++)
            if (use[p+k]==1) {t=1; ans++; break;}
            if (t==1) break;
        }
    }
    cout<<ans<<endl;
}