#include <bits/stdc++.h>
using namespace std;
long long occ[11][2];
long long Get(long long x,int id)
{
    for (int i=0;i<=9;i++)
        occ[i][id]=x/10;
    for (int i=0;i<=x%10;i++)
        occ[i][id]++;
}
long long P(long long a,long long b)
{
    if (b==0)return 1;
    long long x=P(a,b/2);
    if (b%2==0)
        return (x*x)%10;
    else
        return (x*x*a)%10;
}
int main()
{
    long long a,b;
    cin>>a>>b;
    Get(a,0);
    Get(b,1);
    long long ret=1;
    for (int i=0;i<10;i++)
    {
        ret=(ret*P(i,occ[i][1]-occ[i][0]))%10;
    }
    cout<<ret<<endl;
}