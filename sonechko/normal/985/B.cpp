#include<Bits/stdc++.h>
using namespace std;

const int N = 2000 + 11;

int b[N],a[N][N];

int main()
{
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++)
    {
        char ch;
        cin>>ch;
        if (ch=='1') a[i][j]=1;
        b[j]+=a[i][j];
    }
    for (int i=1; i<=n; i++)
    {
        int ts=0;
        for (int j=1; j<=m; j++)
            if (b[j]-a[i][j]==0) ts=1;
        if (ts==0) {cout<<"YES"<<endl; return 0;}
    }
    cout<<"NO"<<endl;
}