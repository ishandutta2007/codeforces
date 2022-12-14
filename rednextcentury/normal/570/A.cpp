 #include <bits/stdc++.h>
using namespace std;
int a[101][101];
int c[1001];
int main()
{
    int n,m;
    cin>>n>>m;
    for (int i=0;i<m;i++)
    {
        int mx=-1;
        int idx=0;
        for (int j=0;j<n;j++)
        {
            cin>>a[i][j];
            if (a[i][j]>mx)
            {
                mx=a[i][j];
                idx=j;
            }
        }
        c[idx]++;
    }
    int mx=-1,idx=0;
    for (int i=0;i<n;i++)
    {
        if (c[i]>mx)
        {
            mx=c[i];
            idx=i+1;
        }
    }
    cout<<idx<<endl;
}