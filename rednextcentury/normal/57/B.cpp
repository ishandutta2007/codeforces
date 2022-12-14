#include<bits/stdc++.h>
using namespace std;
long long a[1000000][3];
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    for (int i=0;i<m;i++)
        cin>>a[i][0]>>a[i][1]>>a[i][2];
    long long sum=0;
    while(k--)
    {
        int x;
        cin>>x;
        for (int i=0;i<m;i++)
        {
            if (x>=a[i][0] && x<=a[i][1])
                sum+=a[i][2]+x-a[i][0];
        }
    }
    cout<<sum<<endl;
}