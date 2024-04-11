#include<bits/stdc++.h>
using namespace std;
long long f[100][100];
int main() 
{
    int n,h;
    cin>>n>>h;
    for(int i=0;i<=n;++i) 
        f[0][i]=1;
    for(int i=1;i<=n;++i)     
        for(int j=1;j<=n;++j)     
            for(int k=0;k<j;++k)
                f[j][i]+=f[k][i-1]*f[j-k-1][i-1];
    cout<<f[n][n]-f[n][h-1]<<endl;
    return 0;
}