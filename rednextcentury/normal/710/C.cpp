#include<bits/stdc++.h>
using namespace std;
queue<int> even,odd;
int a[100][100];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int N = n*n;
    for (int i=1;i<=N;i++)
        if (i%2)odd.push(i);
        else even.push(i);
    int num=n-2;
    for (int i=0;i<n/2;i++)
    {
        a[n/2][i]=1;
        for (int j=1;j<=num/2;j++)
            a[n/2+j][i]=1,a[n/2-j][i]=1;
        num-=2;
    }
    for (int i=0;i<n;i++)
        a[i][n/2]=1;
    num=1;
    for (int i=n/2+1;i<n;i++)
    {
        a[n/2][i]=1;
        for (int j=1;j<=num/2;j++)
            a[n/2+j][i]=1,a[n/2-j][i]=1;
        num+=2;
    }
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            //cout<<a[i][j]<<' ';
            if (a[i][j]==1)
            {
                cout<<odd.front()<<' ';
                odd.pop();
            }
            else
            {
                cout<<even.front()<<' ';
                even.pop();
            }
        }
        cout<<endl;
    }
}