#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define ld long double
#define pb push_back
const int N = 2000 + 11;

ll s1[N][N],s2[N][N],a[N][N],use1[N][N],use2[N][N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    for (int j=1; j<=n; j++)
        cin>>a[i][j];
    for (int i=1; i<=n; i++)
    for (int j=1; j<=n; j++)
    {
        if (use1[i][j]==0)
        {
            int l=i,r=j;
            ll ss=0;
            while (l<=n&&r<=n)
            {
                ss+=a[l][r];
                l++;
                r++;
            }
            l=i,r=j;
            while (l<=n&&r<=n)
            {
                use1[l][r]=1;
                s1[l][r]=ss;
                l++;
                r++;
            }
        }
        if (use2[i][j]==0)
        {
            int l=i,r=j;
            ll ss=0;
            while (l<=n&&r>=1)
            {
                ss+=a[l][r];
                l++;
                r--;
            }
            l=i,r=j;
            while (l<=n&&r>=1)
            {
                use2[l][r]=1;
                s2[l][r]=ss;
                l++;
                r--;
            }
        }
    }
    ll l1=0,r1=0,x=-1,y=-1,l2=0,r2=0;
    for (int i=1; i<=n; i++)
    for (int j=1; j<=n; j++)
    if ((i+j)%2==0&&s1[i][j]+s2[i][j]-a[i][j]>x) {x=-a[i][j]+s1[i][j]+s2[i][j];
    l1=i; r1=j;}
    for (int i=1; i<=n; i++)
    for (int j=1; j<=n; j++)
    if ((i+j)%2==1&&s1[i][j]+s2[i][j]-a[i][j]>y) {y=-a[i][j]+s1[i][j]+s2[i][j];
    l2=i; r2=j;}
    cout<<x+y<<endl;
    cout<<l1<<" "<<r1<<" "<<l2<<" "<<r2<<endl;
}