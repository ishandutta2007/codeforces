#include<iostream>
#include<cstring>
#include<string.h>
#include<math.h>
#include<stdio.h>
using namespace std;
double p[11][11];
const double EPS = 1e-8;
double abs(double k)
{
    return k<0?-k:k;
}
void add(int i,int j,double k)
{
    p[i][j] += k;
    if(i==10)
    {
        if(1-p[i][j]<EPS) p[i][j]=1;
        return;
    }
    if(1-p[i][j]>EPS)
    {
        return;
    }else{
        add(i+1,j,(p[i][j]-1)/2);
        add(i+1,j+1,(p[i][j]-1)/2);
        p[i][j]=1;
    }
}
int main()
{
    int n,t,ans=0;cin>>n>>t;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            p[i][j]=0;
        }
    }
    for(int i=1;i<=t;i++)
    {
        add(1,1,1);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            if(abs(p[i][j]-1)<EPS) ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}