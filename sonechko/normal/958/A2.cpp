#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ff first
#define ss second
#define ull unsigned long long
#define mp make_pair
const int N = 2000 + 11;
const ull p1=29,p2=31;

char a[N][N],b[N][N];
ull pow1[N],pow2[N],h_a[N][N],h_b[N][N];

int main()
{
    #ifndef __WIN32
    freopen("twopaths.in", "r", stdin);
    freopen("twopaths.out", "w", stdout);
    #endif // __WIN32
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    pow1[0]=p1;
    pow2[0]=p2;
    for (int i=1; i<=n; i++)
    {
        pow1[i]=pow1[i-1]*p1;
        pow2[i]=pow2[i-1]*p2;
    }
    for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++)
    {
        cin>>a[i][j];
        h_a[i][j]=h_a[i-1][j]+h_a[i][j-1]-h_a[i-1][j-1]+(a[i][j]-'a'+1)*pow1[i]*pow2[j];
    }
    for (int i=1; i<=m; i++)
    for (int j=1; j<=n; j++)
    {
        cin>>b[i][j];
        h_b[i][j]=h_b[i-1][j]+h_b[i][j-1]-h_b[i-1][j-1]+(b[i][j]-'a'+1)*pow1[i]*pow2[j];
    }
    for (int i=1; i<=n-m+1; i++)
    for (int j=1; j<=n-m+1; j++)
    {
        ull h1=h_a[i+m-1][m]-h_a[i-1][m];
        h1*=pow1[n-i]*pow2[n-1];
        ull h2=h_b[m][j+m-1]-h_b[m][j-1];
        h2*=pow1[n-1]*pow2[n-j];
        if (h1==h2) {cout<<i<<" "<<j<<endl; return 0;}
    }
    cout<<"OH NO"<<endl;
}