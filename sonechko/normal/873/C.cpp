#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int N = 300 + 11;
int a[N][N];
int kol(int l, int r1, int r2)
{
    int res=0;
    for (int i=r1; i<=r2; i++)
        res+=a[i][l];
    return res;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++)
    {
        cin>>a[i][j];
    }
    int ans=0,kkol=0;
    for (int j=1; j<=m; j++)
    {
        int ans1=0,kol1=0;
        int kol2=0;
        for (int i=1; i<=n; i++)
            if (a[i][j]==1)
        {
            int dsum=kol(j,i,i+min(k,n-i+1)-1);
            if (dsum>ans1) {ans1=dsum; kol1=kol2;}
            kol2++;
        }
        ans+=ans1;
        kkol+=kol1;
    }
    cout<<ans<<" "<<kkol<<endl;
}