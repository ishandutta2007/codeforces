#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

const int N = 100 + 11;

int a[N][N];
char b[N][N];

void up()
{
    int n,m,k;
    cin>>n>>m>>k;
    int kk=0;
    for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++)
    {
        char c;
        cin>>c;
        if (c=='.') a[i][j]=0; else a[i][j]=1;
        kk+=a[i][j];
    }
    int k1=kk/k;
    int k2=kk%k;
    int ks=0,p=0;
    for (int i=1; i<=n; i++)
    {
        if (i%2==1)
        {
            for (int j=1; j<=m; j++)
            {
                ks+=a[i][j];
                if (p<=9) b[i][j]=p+'0'; else
                if (p<=9+26) b[i][j]=(p-10)+'a'; else
                b[i][j]=(p-10-26)+'A';
                if (k2>0&&ks==k1+1&&p+1<k) {ks=0; k2--; p++;} else
                if (k2==0&&ks==k1&&p+1<k) {ks=0; p++;}
            }
        } else
        {
            for (int j=m; j>=1; j--)
            {
                ks+=a[i][j];
                if (p<=9) b[i][j]=p+'0'; else
                if (p<=9+26) b[i][j]=(p-10)+'a'; else
                b[i][j]=(p-10-26)+'A';
                if (k2>0&&ks==k1+1&&p+1<k) {ks=0; k2--; p++;} else
                if (k2==0&&ks==k1&&p+1<k) {ks=0; p++;}
            }
        }
    }
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
            cout<<b[i][j];
        cout<<"\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--)
        up();
}