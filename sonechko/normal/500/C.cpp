#include<bits/stdc++.h>
using namespace std;
#define pb push_back

const int N = 2e5 + 11;
int a[N],b[N],use[N];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    int kol=0,ans=0;
    for (int i=1; i<=m; i++)
    {
        int l;
        cin>>l;
        if (use[l]==0)
        {
            kol++;
            b[kol]=l;
            use[l]=1;
        }
        int t=1;
        for (int j=1; j<=kol; j++)
        if (b[j]==l) {t=j; break;} else ans+=a[b[j]];
        for (int j=t; j>=2; j--)
        b[j]=b[j-1];
        b[1]=l;
    }
    cout<<ans<<endl;
}