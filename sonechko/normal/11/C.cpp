#include<bits/stdc++.h>
using namespace std;
const int N = 250 + 11;
const long long MOD = 1e9 + 7;
#define mod %MOD
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ss second
#define ff first
#define ll long long
#define mp make_pair
#define endl "\n"
#define pb push_back
#define y1 ijdj
#define next lzk
#define ld long double
#define sqr(a) ((a)*(a))
int fdown[N][N],fright[N][N],a[N][N],f1[N][N],f2[N][N],sdown[N][N],sright[N][N],s1[N][N],s2[N][N];
inline void gets()
{
    int n=5,m=5;
    cin>>n>>m;
    for (int i=0; i<=n+1; i++)
        for (int j=0; j<=m+1; j++)
    {
        fdown[i][j]=0;
        fright[i][j]=0;
        a[i][j]=0;
        f1[i][j]=0;
        f2[i][j]=0;
        sright[i][j]=0;
        sdown[i][j]=0;
        s1[i][j]=0;
        s2[i][j]=0;
    }
    int sum = 0;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++)
        {
            char ch;
            cin>>ch;
            if (ch=='1') a[i][j]=1;
        }
}
    for (int i=n+1; i>=0; i--)
    for (int j=m+1; j>=0; j--)
    {
        if (a[i][j]==1)
        {
            fdown[i][j]=fdown[i+1][j]+1;
            fright[i][j]=fright[i][j+1]+1;
            f1[i][j]=f1[i+1][j-1]+1;
            f2[i][j]=f2[i+1][j+1]+1;
        }
    }
    for (int i=0; i<=n+1; i++)
    {
        for (int j=0; j<=m+1; j++)
    {
        sdown[i][j]=sdown[i-1][j]+a[i][j];
        sright[i][j]=sright[i][j-1]+a[i][j];
        s1[i][j]=s1[i-1][j+1]+a[i][j];
        s2[i][j]=s2[i-1][j-1]+a[i][j];
    }
    }
    int ans=0;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
        if (a[i][j]==1)
    {
        if (fdown[i][j]>1&fright[i][j]==fdown[i][j])
        {
            int k=fdown[i][j];
            if (fright[i+k-1][j]==fdown[i][j]&&fdown[i][j+k-1]==k)
            {
                if (a[i-1][j-1]==0&&a[i-1][j+k-1+1]==0&&a[i+k-1+1][j+k-1+1]==0&&a[i+k-1+1][j-1]==0&&
                sright[i-1][j+k-1]==sright[i-1][j-1]&&sright[i+k][j+k-1]==sright[i+k][j-1]&&
                sdown [i+k-1][j-1]==sdown [i-1][j-1]&&sdown [i+k-1][j+k]==sdown [i-1][j+k]&&
                (k==2||(
                sright[i+1][j+k-2]==sright[i+1][j]&&sright[i+k-2][j+k-2]==sright[i+k-2][j]&&
                sdown [i+k-2][j+1]==sdown [i][j+1]&&sdown [i+k-2][j+k-2]==sdown [i][j+k-2]
                        )))
                        { ans++;}
            }
        }
        if (f1[i][j]>1&&f2[i][j]==f1[i][j])
        {
            int k=f1[i][j];
            if (i==1&&j==2)
            {
            }
            if (f2[i+k-1][j-k+1]==k&&f1[i+k-1][j+k-1]==k)
            {
                if (a[i-1][j]==0&&a[i+k-1][j-k+1-1]==0&&a[i+k-1][j+k-1+1]==0&&
                    a[i+2*k-2+1][j]==0&&
                s1[i-1][j]==s1[i+k-1][j-k+1-1]&&s1[i+k-1][j+k-1+1]==s1[i+2*k-2+1][j]&&
                s2[i-1][j]==s2[i+k-1][j+k-1+1]&&s2[i+k-1][j-k+1-1]==s2[i+2*k-2+1][j]&&
                s1[i][j+1]==s1[i+k-1+1][j-k+1]&&s1[i+k-1-1][j+k-1]==s1[i+2*k-2][j-1]&&
                s2[i][j-1]==s2[i+k-1+1][j+k-1]&&s2[i+k-1-1][j-k+1]==s2[i+2*k-2][j+1]&&
                a[i-1][j-1]==0&&a[i-1][j+1]==0&&a[i+k-1-1][j-k+1-1]==0&&
                a[i+k-1+1][j-k+1-1]==0&&a[i+2*k-2+1][j-1]==0&&
                a[i+2*k-2+1][j+1]==0&&a[i+k-1-1][j+k-1+1]==0&&
                a[i+k-1+1][j+k-1+1]==0&&
                s1[i-1][j-1]==s1[i+k-1-1][j-k+1-1]&&s1[i+k-1+1][j+k-1+1]==s1[i+2*k-2+1][j+1]&&
                s2[i-1][j+1]==s2[i+k-1-1][j+k-1+1]&&s2[i+k-1+1][j-k+1-1]==s2[i+2*k-2+1][j-1]&&
                (k==2||(
                s1[i+1][j+1]==s1[i+k-1][j-k+1+2]&&s1[i+k-1-1][j+k-1-1]==s1[i+2*k-2-2][j]&&
                s2[i+1][j-1]==s2[i+k-1][j+k-1-2]&&s2[i+k-1][j-k+1+2]==s2[i+2*k-2-2][j]
                ))) {ans++;}
            }
        }
    }
    cout<<ans<<endl;
}
int main()
{
    #ifdef LOCAL
    freopen("input.txt","r", stdin);
    freopen("output.txt", "w", stdout);
    #else
    sync;
    #endif
    sync;
    int t;
    cin>>t;
    for (int ij=1; ij<=t; ij++)
    {
        gets();
    }
}