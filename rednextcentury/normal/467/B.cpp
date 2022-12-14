#include <cmath>
#include <cstdio>
#include <queue>
#include <iostream>
#include <ios>
using namespace std;
int val[1001];
int ans=0;
int n,m,k;
int start;
int countdist(int a,int b)
{
int num1[21]={0};
int num2[21]={0};
    int l=0;
    while(a>0)
    {
        num1[l++]=a%2;
        a/=2;
    }
    l=0;
    int dist=0;
    while(b>0)
    {
        num2[l++]=b%2;
        b/=2;
    }
    for (int i=0;i<=n;i++)
        if (num1[i]!=num2[i])
            dist++;
    return dist;
}
int main()
{

    ios_base::sync_with_stdio(0);
    cin>>n>>m>>k;
    for (int i=0;i<m;i++)
    {
        cin>>val[i];
    }
    cin>>start;
    for (int i=0;i<m;i++)
    {
        if (countdist(start,val[i])<=k)
            ans++;
    }
    cout<<ans<<endl;
}