#include<bits/stdc++.h>
using namespace std;
int a[5000000];
int F[5000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    memset(F,-1,sizeof(F));
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>a[i],F[a[i]]=a[i];
    long long ret=0;
    for (int i=0;i<22;i++)
        for (int j=0;j<(1<<22);j++)
            if (j&(1<<i))
                F[j]=max(F[j],F[j^(1<<i)]);

    for (int i=0;i<n;i++)
        cout<<F[(1<<22)-1-a[i]]<<' ';
}