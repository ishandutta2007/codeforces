#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ss second
#define ff first
#define mp make_pair
#define pb push_back


const int N = 2e5 + 11;

int use[N],xx[N],yy[N];
int nn,n,m;

bool pr(int l1, int r1)
{
    if (l1==0) return true;
    if (r1==0) return true;
    int x1=xx[l1];
    int y1=yy[l1];
    int x2=xx[r1];
    int y2=yy[r1];
    if (abs(x1-x2)==1&&y1==y2) { return false;}
    if (abs(y1-y2)==1&&x1==x2) { return false;}
    return true;
}
int num(int l, int r)
{
    return (l-1)*m+r;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    if (n==1&&m==1) {cout<<"YES"<<endl; cout<<1<<endl; return 0;}
    if (m%2==0&&m>=4)
    {
        int g[n+2][m+2];
        int k1=1,k2=m;
        for (int i=m/2; i>=1; i--)
        {
            if (i%2==0) g[1][k1]=i; else g[1][k1]=m-i+1;
            if (i%2==0) g[1][k2]=m-i+1; else g[1][k2]=i;
            k1++;
            k2--;
        }
        for (int i=1; i<=m; i++)
            g[2][i]=g[1][m-i+1]+m;
        for (int i=3; i<=n; i++)
        for (int j=1; j<=m; j++)
            g[i][j]=g[i-2][j]+m+m;
        cout<<"YES"<<endl;
        for (int i=1; i<=n; i++)
        {
            for (int j=1; j<=m; j++)
                cout<<g[i][j]<<" ";
            cout<<"\n";
        }
        return 0;
    }
    if (n%2==0&&n>=4)
    {

        int x[n+2][m+2];
        int xx[n*m+3];

        int kol=0;

        for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
        {
            kol++;
            x[i][j]=kol;
        }

        kol=0;

        for (int j=1; j<=m; j++)
        for (int i=1; i<=n; i++)
        {
            kol++;
            xx[kol]=x[i][j];
        }

        swap(n,m);

        int g[n+2][m+2];

        int k1=1,k2=m;
        for (int i=m/2; i>=1; i--)
        {
            if (i%2==0) g[1][k1]=i; else g[1][k1]=m-i+1;
            if (i%2==0) g[1][k2]=m-i+1; else g[1][k2]=i;
            k1++;
            k2--;
        }
        for (int i=1; i<=m; i++)
            g[2][i]=g[1][m-i+1]+m;
        for (int i=3; i<=n; i++)
        for (int j=1; j<=m; j++)
            g[i][j]=g[i-2][j]+m+m;
        swap(n,m);
        cout<<"YES"<<endl;
        for (int i=1; i<=n; i++)
        {
            for (int j=1; j<=m; j++)
                cout<<xx[g[j][i]]<<" ";
            cout<<"\n";
        }
        return 0;
    }
    if (m%2==1&&m>=5)
    {
        int g[n+2][m+2];
        m--;
        int k1=1,k2=m;
        for (int i=m/2; i>=1; i--)
        {
            if (i%2==0) g[1][k1]=i; else g[1][k1]=m-i+1;
            if (i%2==0) g[1][k2]=m-i+1; else g[1][k2]=i;
            k1++;
            k2--;
        }
        m++;
        g[1][m]=m;
        for (int i=1; i<=m; i++)
            g[2][i]=g[1][i-1]+m;
        g[2][1]=m+m;
        for (int i=3; i<=n; i++)
        for (int j=1; j<=m; j++)
            g[i][j]=g[i-2][j]+m+m;
        cout<<"YES"<<endl;
        for (int i=1; i<=n; i++)
        {
            for (int j=1; j<=m; j++)
                cout<<g[i][j]<<" ";
            cout<<"\n";
        }
        return 0;
    }
    if (n%2==1&&n>=5)
    {
         int x[n+2][m+2];
        int xx[n*m+3];

        int kol=0;

        for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
        {
            kol++;
            x[i][j]=kol;
        }

        kol=0;

        for (int j=1; j<=m; j++)
        for (int i=1; i<=n; i++)
        {
            kol++;
            xx[kol]=x[i][j];
        }
        swap(n,m);
        int g[n+2][m+2];
        m--;
        int k1=1,k2=m;
        for (int i=m/2; i>=1; i--)
        {
            if (i%2==0) g[1][k1]=i; else g[1][k1]=m-i+1;
            if (i%2==0) g[1][k2]=m-i+1; else g[1][k2]=i;
            k1++;
            k2--;
        }
        m++;
        g[1][m]=m;
        for (int i=1; i<=m; i++)
            g[2][i]=g[1][i-1]+m;
        g[2][1]=m+m;
        for (int i=3; i<=n; i++)
        for (int j=1; j<=m; j++)
            g[i][j]=g[i-2][j]+m+m;
        swap(n,m);
        cout<<"YES"<<endl;
        for (int i=1; i<=n; i++)
        {
            for (int j=1; j<=m; j++)
                cout<<xx[g[j][i]]<<" ";
            cout<<"\n";
        }
        return 0;
    }
    if (n==3&&m==3)
    {
        cout<<"YES"<<endl;
        cout<<"1 3 4"<<endl;
        cout<<"5 7 6"<<endl;
        cout<<"9 2 8"<<endl;
        return 0;
    }
    cout<<"NO"<<endl;
}


/**

2 4 1 3 5
10 7 9 6 8
12 14 11 13 15
20 17 19 16 18
22 24 21 23 25
**/