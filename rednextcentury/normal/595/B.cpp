# include <iostream>
# include <vector>
# include <stdio.h>
#include <limits.h>
#include <stack>
#include <map>
using namespace std;
int a[1000000];
int b[1000000];
long long p[10000];
long long solve(int len,int div,int ban)
{
    long long num=(p[len]-1)/div + 1;
    long long n1=(p[len-1]*ban)%div;
    if (p[len-1]-1-(div-n1)%div>=0)
    num-=(p[len-1]-1-(div-n1)%div)/(div) + 1;
    return num;
}
#define MOD 1000000007
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    p[0]=1;
    for (int i=1;i<=10;i++)
        p[i]=p[i-1]*10;
    int n,k;
    cin>>n>>k;
    int m=n/k;
    for (int i=0;i<m;i++)
        cin>>a[i];
    for (int i=0;i<m;i++)
        cin>>b[i];
    long long ans=1;
    for (int i=0;i<m;i++)
    {
        ans*=solve(k,a[i],b[i]);
        ans%=MOD;
    }
    cout<<ans<<endl;
}