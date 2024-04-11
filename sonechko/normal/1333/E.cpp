#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 500 + 11;

int n;
int a[N][N];
int use[N*N];
int u[N][N];

int get1()
{
    int l=0,r=0;
    for (int i=1; i<=n; i++)
    for (int j=1; j<=n; j++)
    {
        u[i][j]=0;
        if (a[i][j]==1) {l=i; r=j;}
    }
    u[l][r]=1;
    int kk=0;
    for (int p=1; p<=n*n-1; p++)
    {
        int l1=0,r1=0,c=n*n+1;
        for (int i=1; i<=n; i++)
        {
            if (u[l][i]==0&&a[l][i]<c)
            {
                c=a[l][i];
                l1=l;
                r1=i;
            }
            if (u[i][r]==0&&a[i][r]<c)
            {
                c=a[i][r];
                l1=i;
                r1=r;
            }
        }
        if (l1==0)
        {
            for (int i=1; i<=n; i++)
            for (int j=1; j<=n; j++)
                if (u[i][j]==0&&a[i][j]<c)
            {
                l1=i;
                r1=j;
                c=a[i][j];
            }
            kk++;
        }
        l=l1;
        r=r1;
        u[l][r]=1;
    }
    return kk;
}

int get2()
{
    int l=0,r=0;
    for (int i=1; i<=n; i++)
    for (int j=1; j<=n; j++)
    {
        u[i][j]=0;
        if (a[i][j]==1) {l=i; r=j;}
    }
    u[l][r]=1;
    int kk=0;
    for (int p=1; p<=n*n-1; p++)
    {
        int l1=0,r1=0,c=n*n+1;
        for (int i=1; i<=n; i++)
        {
            if (u[l][i]==0&&a[l][i]<c)
            {
                c=a[l][i];
                l1=l;
                r1=i;
            }
            if (u[i][r]==0&&a[i][r]<c)
            {
                c=a[i][r];
                l1=i;
                r1=r;
            }
            if (l+i<=n&&r+i<=n&&u[l+i][r+i]==0&&a[l+i][r+i]<c)
            {
                c=a[l+i][r+i];
                l1=l+i;
                r1=r+i;
            }
            if (l+i<=n&&r-i>=1&&u[l+i][r-i]==0&&a[l+i][r-i]<c)
            {
                c=a[l+i][r-i];
                l1=l+i;
                r1=r-i;
            }
            if (l-i>=1&&r+i<=n&&u[l-i][r+i]==0&&a[l-i][r+i]<c)
            {
                c=a[l-i][r+i];
                l1=l-i;
                r1=r+i;
            }
            if (l-i>=1&&r-i>=1&&u[l-i][r-i]==0&&a[l-i][r-i]<c)
            {
                c=a[l-i][r-i];
                l1=l-i;
                r1=r-i;
            }
        }
        if (l1==0)
        {
            for (int i=1; i<=n; i++)
            for (int j=1; j<=n; j++)
                if (u[i][j]==0&&a[i][j]<c)
            {
                l1=i;
                r1=j;
                c=a[i][j];
            }
            kk++;
        }
        l=l1;
        r=r1;
        u[l][r]=1;
    }
    return kk;
}

bool good()
{
    return (get1()<get2());
}

void rec(int l, int r)
{
    if (l==n+1)
    {
        if (good())
        {
            cout<<get1()<<" : "<<get2()<<endl;
            cout<<endl;
            for (int i=1; i<=n; i++)
            {
                for (int j=1; j<=n; j++)
                    cout<<a[i][j]<<" ";
                cout<<endl;
            }
            cout<<endl;
            exit(0);
        }
        return;
    }
    if (r==n+1) {rec(l+1,1); return;}
    for (int i=1; i<=n*n; i++)
        if (use[i]==0)
    {
        use[i]=1;
        a[l][r]=i;
        rec(l,r+1);
        a[l][r]=0;
        use[i]=0;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    if (n==1) return cout<<"-1", 0;
    if (n==2) return cout<<"-1", 0;
    if (n==3)
    {
        cout<<"1 2 4\n";
        cout<<"5 3 8\n";
        cout<<"9 6 7\n";
        return 0;
    }
    if (n==4)
    {
        cout<<"1 2 3 4\n";
        cout<<"5 6 7 8\n";
        cout<<"9 10 11 14\n";
        cout<<"13 16 12 15\n";
        return 0;
    }
    if (n%2==1)
    {
        int k=0;
        for (int i=1; i<=n-3; i++)
            if (i%2==1)
        {
            for (int j=1; j<=n; j++)
            {
                k++;
                a[i][j]=k;
            }
        } else
        {
            for (int j=n; j>=1; j--)
            {
                k++;
                a[i][j]=k;
            }
        }
        for (int j=1; j<=n-3; j++)
            if (j%2==1)
            {
                for (int i=n-2; i<=n; i++)
                {
                    k++;
                    a[i][j]=k;
                }
            } else
            {
                for (int i=n; i>=n-2; i--)
                {
                    k++;
                    a[i][j]=k;
                }
            }
        k++;
        a[n-2][n-2]=k;
        k++;
        a[n-2][n-1]=k;
        k++;
        a[n-1][n-1]=k;
        k++;
        a[n-2][n]=k;
        k++;
        a[n-1][n-2]=k;
        k++;
        a[n][n-1]=k;
        k++;
        a[n][n]=k;
        k++;
        a[n-1][n]=k;
        k++;
        a[n][n-2]=k;
    } else
    {
        int k=0;
        for (int i=1; i<=n-4; i++)
            if (i%2==1)
        {
            for (int j=1; j<=n; j++)
            {
                k++;
                a[i][j]=k;
            }
        } else
        {
            for (int j=n; j>=1; j--)
            {
                k++;
                a[i][j]=k;
            }
        }
        for (int j=1; j<=n-4; j++)
            if (j%2==1)
            {
                for (int i=n-3; i<=n; i++)
                {
                    k++;
                    a[i][j]=k;
                }
            } else
            {
                for (int i=n; i>=n-3; i--)
                {
                    k++;
                    a[i][j]=k;
                }
            }
        /**
        1 2 3 4
        5 6 7 8
        9 10 11 14
        13 16 12 15
        **/
        k++;
        a[n-3][n-3]=k;
        k++;
        a[n-3][n-2]=k;
        k++;
        a[n-3][n-1]=k;
        k++;
        a[n-3][n]=k;
        k++;
        a[n-2][n-3]=k;
        k++;
        a[n-2][n-2]=k;
        k++;
        a[n-2][n-1]=k;
        k++;
        a[n-2][n]=k;
        k++;
        a[n-1][n-3]=k;
        k++;
        a[n-1][n-2]=k;
        k++;
        a[n-1][n-1]=k;
        k++;
        a[n][n-1]=k;
        k++;
        a[n][n-3]=k;
        k++;
        a[n-1][n]=k;
        k++;
        a[n][n]=k;
        k++;
        a[n][n-2]=k;
    }
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
    return 0;
    if (good()==0)
    {
        while (1==1)
        {

        }
    }
    exit(0);
    rec(1,1);
}
/**

20
2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
1 1 1 1 1 1 1 1 2  3  3  4  5  5  6  7  8  9  10

1 1 1 1 1 1 1 1 1 2 3 3 4 5 5 5 6 7 7 8 9 10 11 12

1 2 4
5 3 8
9 6 7

x x x
x x x
9 x x

1 2 3 4 5
10 9 8 7 6
11 16 17 18 20
12 15 21 19 24
13 14 25 22 23


6 5 4 3 2 1
7 8 9 10 11 12
18 17 16 15 14 13
19 26 27 28 29 31
20 25 24 32 30 35
21 22 23 36 33 34


1 2 3 4
5 6 7 8
9 10 11 14
13 16 12 15

1 2 3 4 5
6 7 8 9 10
11 12 13 14 15
16 17 18 19 22
20 23 25 21 24

1 2 3 4 5 6
7 8 9 10 11 12
13 14 15 16 17 18
19 20 21 22 23 24
25 26 27 28 29 32
30 33 34 36 31 35

1 2 3 4 5 6 7
8 9 10 11 12 13 14
15 16 17 18 19 20 21
22 23 24 25 26 27 28
29 30 31 32 33 34 35
36 37 38 39 40 41 44
42 45 46 47 49 43 48

**/