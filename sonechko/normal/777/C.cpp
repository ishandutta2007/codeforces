#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 11;
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
int maxi[N];
int main()
{
    sync;
    int n,m;
    cin>>n>>m;
    int a[n+1][m+1],b[n+1][m+1];
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
        {
            cin>>a[i][j];
            if (i==1) b[i][j]=0;
        }

    for (int i=2; i<=n; i++)
        for (int j=1; j<=m; j++)
    {
        if (a[i][j]>=a[i-1][j]) b[i][j]=b[i-1][j]+1; else
            b[i][j]=0;
        maxi[i]=max(maxi[i],b[i][j]);
    }
    int k;
    cin>>k;
    for (int i=1; i<=k; i++)
    {
        int l,r;
        cin>>l>>r;
        if (maxi[r]>=r-l) cout<<"Yes"<<endl; else cout<<"No"<<endl;
    }
}