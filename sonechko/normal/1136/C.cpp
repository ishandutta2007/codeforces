#include<bits/stdc++.h>
using namespace std;

#define pb push_back

const int N = 600 + 11;

int a[N][N],b[N][N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t=1;
    while (t--)
    {
        int n,m;
        cin>>n>>m;
        for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            cin>>a[i][j];
        for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            cin>>b[i][j];
        int ans=1;
        for (int j=1; j<=m; j++)
        {
            vector<int> p1,p2;
            int l=1,r=j;
            while (l<=n&&r>=1)
            {
                p1.pb(a[l][r]);
                p2.pb(b[l][r]);
                l++;
                r--;
            }
            sort(p1.begin(),p1.end());
            sort(p2.begin(),p2.end());
            if (p1!=p2) ans=0;
        }
        for (int i=1; i<=n; i++)
        {
            vector<int> p1,p2;
            int l=i,r=m;
            while (l<=n&&r>=1)
            {
                p1.pb(a[l][r]);
                p2.pb(b[l][r]);
                l++;
                r--;
            }
            sort(p1.begin(),p1.end());
            sort(p2.begin(),p2.end());
            if (p1!=p2) ans=0;
        }
        if (ans) cout<<"YES\n"; else cout<<"NO\n";
    }

}