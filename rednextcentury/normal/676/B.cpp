#include<bits/stdc++.h>
using namespace std;
int a[100][100];
int main()
{
    int n,t;
    cin>>n>>t;
    t*=(1<<9);
    a[0][0]=t;
    int num=0;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<i+1;j++)
        {
            if (a[i][j]>=(1<<9))
                num++;
            a[i+1][j]+=max(a[i][j]-(1<<9),0)/2;
            a[i+1][j+1]+=max(a[i][j]-(1<<9),0)/2;
        }
    }
    cout<<num<<endl;
}