#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 11;

int a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,r;
    cin>>n>>r;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    int ans=0;
    for (int i=1; i<=n; i++)
        if (a[i]<2)
    {
        int t=-1;
        for (int j=i+r-1; j>=i-r+1; j--)
        if (j>0&&(a[j]==1||a[j]==3)) {t=j; break;}
        if (t==-1) {cout<<-1<<endl; return 0;}
        ans++;
        for (int j=t-r+1; j<=t+r-1; j++)
            if (j>=1&&a[j]==0) a[j]=2; else
            if (j>=1&&a[j]==1) a[j]=3;
    }
    cout<<ans<<endl;
}