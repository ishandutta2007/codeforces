#include <bits/stdc++.h>
#define ll long long
using namespace std;
char ret[1001][1001];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m,a,b,c;
    int N,M;
    cin>>n>>m>>a>>b>>c;
    N=n,M=m;
    if (n%2 && m%2){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    if (n%2)
    {
        if (a<m/2)
        {
            cout<<"IMPOSSIBLE"<<endl;
            return 0;
        }
        a-=m/2;
        for (int i=1;i<=m;i++)
        {
            int x=(i-1)/2;
            if (x%2)
                ret[n][i]='z';
            else
                ret[n][i]='y';
        }
        n--;
    }
    if (m%2)
    {
        if (b<n/2)
        {
            cout<<"IMPOSSIBLE"<<endl;
            return 0;
        }
        b-=n/2;
        for (int i=1;i<=n;i++)
        {
            int x=(i-1)/2;
            if (x%2)
                ret[i][m]='z';
            else
                ret[i][m]='y';
        }
        m--;
    }
    for (int i=1;i<=n;i+=2)
    {
        for (int j=1;j<=m;j+=2)
        {
            char l1='a',l2='a';
            while(l1==ret[i-1][j] || l1==ret[i][j-1] || l1==ret[i-1][j+1] || l1==ret[i+1][j-1])l1++;
            while(l1==l2 || l2==ret[i-1][j] || l2==ret[i][j-1] || l2==ret[i-1][j+1] || l2==ret[i+1][j-1])l2++;
            if (c)
            {
                c--;
                ret[i][j]=ret[i+1][j]=ret[i][j+1]=ret[i+1][j+1]=l1;
            }
            else if (a>1)
            {
                a-=2;
                ret[i][j]=ret[i][j+1]=l1;
                ret[i+1][j]=ret[i+1][j+1]=l2;
            }
            else if (b>1)
            {
                b-=2;
                ret[i][j]=ret[i+1][j]=l1;
                ret[i][j+1]=ret[i+1][j+1]=l2;
            }
            else
            {
                cout<<"IMPOSSIBLE"<<endl;
                return 0;
            }
        }
    }
    for (int i=1;i<=N;i++)
    {
        for (int j=1;j<=M;j++)
            cout<<ret[i][j];
        cout<<endl;
    }
}