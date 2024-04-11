#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define ff first
#define ss second
#define pb push_back

const int N = 2e5 + 11;

int a[10][10];
int u[10];

void up()
{
    int n=9;
    for (int i=1; i<=n; i++)
    for (int j=1; j<=n; j++)
    {
        char c;
        cin>>c;
        a[i][j]=(c-'0');
    }
    for (int i=1; i<=9; i++)
    {
        u[i]=0;
    }
    for (int ii=1; ii<=3; ii++)
    {
        for (int jj=1; jj<=3; jj++)
    {
        int x=0,y=0;
        for (int l=(ii-1)*3+1; l<=ii*3; l++)
        {
            for (int r=(jj-1)*3+1; r<=jj*3; r++)
            if (a[l][r]==1) {x=l; y=r;}
        }
        x++;
        if (x>ii*3) x=(ii-1)*3+1;
        a[x][y]=1;
    }
    }
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
            cout<<a[i][j];
        cout<<endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--) up();
}